// Project.cpp by Travis Bishop, Alan Achtenberg and Timothy Baker

#include <iostream>
#include "Graph.h"         // get access to our graphics library facilities
#include "GUI.h"
#include "Window.h"
#include <FL/Fl_Button.H>
#include <FL/fl_draw.H>
#include "Highscore.h"


using namespace Graph_lib;
using namespace std;


Image main_menu(Point(0,0), "title.jpg");		//All images used
Image rules(Point(720,0), "rules.jpg");
Image tamu_banner(Point(0,0), "tamu_sidebanner.jpg");
Image tu_banner(Point(600,0), "tu_sidebanner.jpg");
Image field(Point(120,0), "field.jpg");
Image position_select(Point(120,0), "position_select.jpg");
Image change(Point(720,0), "change.jpg");

int team=0;	//team color condition
string name;
int moves;

struct Lines_window : Graph_lib::Window {		
	int selected;
	int clicked;
	int row, col;	//row and column of each button
    Lines_window(Point xy, int w, int h, const string& title);
    static void cb(Address, Address);

	Button next_button;	//next button for the intro screen
	Button continue_next_button;	//next button for instructions screen
	Button LSU_button;
	Button AU_button;
	Button UF_button;
	In_box name_box;
	Button quit_button;

	static void cb_next(Address, Address);	//button callbacks and functions
	void next();
	static void cb_continue_next(Address, Address);
	void continue_next();
	static void cb_LSU(Address, Address);
	void LSU();
	static void cb_AU(Address, Address);
	void AU();
	static void cb_UF(Address, Address);
	void UF();
	void Score_window();
	static void cb_quit(Address, Address);
	void quit();
};
Lines_window::Lines_window(Point xy, int w, int h, const string& title)		//initialization for Lines_window and all its buttons
    : Graph_lib::Window(xy,w,h,title),
	next_button(Point(0,480), 60, 30, "Next", cb_next),
	continue_next_button(Point(210,480), 60, 30, "Continue", cb_continue_next),
	name_box(Point(135,480), 60, 30, "Enter your name"),
	LSU_button(Point(0,0), 240, 480, "LSU", cb_LSU),
	AU_button(Point(240,0), 240, 480, "AU", cb_AU),
	UF_button(Point(480,0), 240,480, "UF", cb_UF),
	quit_button(Point(340,480), 60, 30, "Quit", cb_quit)
{
	attach(quit_button);	//attaching buttons to Lines_window
	attach(next_button);
	attach(main_menu);
	attach(rules);
	attach(change);
}


struct My_Button : public Button{
	Lines_window* window;
	Circle* cirle;
	int selected;
	int clicked;
	vector<vector<My_Button*> >* board;
	int row, column;	//each My_Button knows its position
	My_Button(Point xy, int w, int h, const string& label, Callback cb,
			int r, int c)
				            : Button(xy,w,h,label,cb),
						row(r), column(c){}
	void attach(Graph_lib::Window& win)
	{
	    pw = new Fl_Button(loc.x, loc.y, width, height, label.c_str());
	    pw->callback(reinterpret_cast<Fl_Callback*>(do_it), this);
	    own = &win;
	}
	void set_fill_color(Color c){pw->color(Fl_Color(c.as_int()));}
};

int score=0;

void Lines_window::cb(Address, Address pb)// One callback shared by all squares
{  										  // Callback knows row and column of button that was clicked
	int& p=score;	// p is a reference to the global variable score
	int& m=moves;	// m is a reference to moves
	My_Button* button = &reference_to<My_Button>(pb);
	Lines_window* temp = button->window;

	int end;
	if (temp->selected == 1) {
		vector<vector<My_Button*> >* board = button->board;
		int r = temp->row;
		int c = temp->col;
		if (abs(temp->row - button->row) == 1 && abs(temp->col - button->column) == 1 		//checks to see that the proper button is selected
			&& (*board)[r][c]->selected == 1 && button->selected != 2) {
			temp->selected = 0;
			(*board)[r][c]->selected = 0;
			button->selected = 1;

			temp->detach(*(*board)[r][c]->cirle);		//detaches and reataches the circle offense piece
			button->cirle->set_color(Color::white);
			button->cirle->set_fill_color(fl_rgb_color(80,0,0));
			temp->attach(*button->cirle);
			++m;

			bool win = 0;
			if (button->row == 7) {		// end of game conditions
				win = 1;
			} else {
				bool stop = 0;
				for (int i = 0; i <= 7; i++) {
					for (int j = 0; j <= 7; j++) {
						if ((*board)[i][j]->selected == 2 && i - 1 >= 0 && j + 1 <= 7 && (*board)[i-1][j+1]->selected == 0) {		// if not end of game, moves the defense
							temp->detach(*(*board)[i][j]->cirle);
							(*board)[i][j]->selected = 0;
							if(team==1){		// chooses the color of the piece based on team choice
							(*board)[i - 1][j + 1]->cirle->set_color(fl_rgb_color(253,208,35));
							(*board)[i - 1][j + 1]->cirle->set_fill_color(fl_rgb_color(70,29,124));}
							if(team==2){
							(*board)[i - 1][j + 1]->cirle->set_color(fl_rgb_color(204,204,204));
							(*board)[i - 1][j + 1]->cirle->set_fill_color(fl_rgb_color(153,0,0));}
							if(team==3){
							(*board)[i - 1][j + 1]->cirle->set_color(fl_rgb_color(255,74,0));
							(*board)[i - 1][j + 1]->cirle->set_fill_color(fl_rgb_color(0,33,165));}
							temp->attach(*(*board)[i - 1][j + 1]->cirle);
							(*board)[i-1][j + 1]->selected = 2;
							stop = 1;
							break;
						} else 
						if ((*board)[i][j]->selected == 2 && i - 1 >= 0 && j - 1 >= 0 && (*board)[i-1][j-1]->selected == 0) {	//same as above, but based on offensive moves
							temp->detach(*(*board)[i][j]->cirle);
							(*board)[i][j]->selected = 0;
							if(team==1){
							(*board)[i - 1][j - 1]->cirle->set_color(fl_rgb_color(253,208,35));
							(*board)[i - 1][j - 1]->cirle->set_fill_color(fl_rgb_color(70,29,124));}
							if(team==2){
							(*board)[i - 1][j - 1]->cirle->set_color(fl_rgb_color(204,204,204));
							(*board)[i - 1][j - 1]->cirle->set_fill_color(fl_rgb_color(153,0,0));}
							if(team==3){
							(*board)[i - 1][j - 1]->cirle->set_color(fl_rgb_color(255,74,0));
							(*board)[i - 1][j - 1]->cirle->set_fill_color(fl_rgb_color(0,33,165));}
							
							temp->attach(*(*board)[i - 1][j - 1]->cirle);
							(*board)[i-1][j - 1]->selected = 2;
							stop = 1;
							break;
						}
					}
					if (stop == 1) {
						break;
					}
				}
				if (stop == 0) {
					win = 2;
				}
			}

			if (win == 1) {		//condition for a full win
				cout << "You won." << endl;
				p=100;
				Save_Score(score, name);
				reference_to<Lines_window>(pb).Score_window();
				}
			if (win == 2) {		//condition for a partial win
				cout << "You won." << endl;
				p=m*3;
				Save_Score(score, name);
				reference_to<Lines_window>(pb).Score_window();
				
				
			} else {		//condition for loss
				int u = button->row;
				int v = button->column;
				bool lost = 1;
				if (u-1 >= 0 && v-1>=0 && (*board)[u-1][v-1]->selected == 0) {
					lost = 0;
				}
				if (u-1 >= 0 && v+1<=7 && (*board)[u-1][v+1]->selected == 0) {
					lost = 0;
				}
				if (u+1 <= 7 && v-1>=0 && (*board)[u+1][v-1]->selected == 0) {
					lost = 0;
				}
				if (u+1 <= 7 && v+1<=7 && (*board)[u+1][v+1]->selected == 0) {
					lost = 0;
				}
				if (lost == 1) {
					cout << "You lost" << endl;
					p=m*2;
					Save_Score(score, name);
					reference_to<Lines_window>(pb).Score_window();
					
				}
			}
			temp->redraw();
		} else {
			temp->row = button->row;
			temp->col = button->column;
		}
	} else {
		temp->row = reference_to<My_Button>(pb).row;
		temp->col= reference_to<My_Button>(pb).column;
		temp->selected = 1;
	}
} 


//------------------------------------------------------------------------------ Button Code

void Lines_window::cb_next(Address, Address pw)//next button code
{
	reference_to<Lines_window>(pw).next();
}
void Lines_window::next()
{
	next_button.hide();
	main_menu.move(720,0);
	rules.move(-720,0);
	attach(continue_next_button);
	attach(name_box);
}
void Lines_window::cb_quit(Address, Address pw)//quit button code
{
	reference_to<Lines_window>(pw).quit();
}
void Lines_window::quit()
{
	exit(0);
}


void Lines_window::cb_continue_next(Address, Address pw)//continue to next screen button code
{
	reference_to<Lines_window>(pw).continue_next();
}
void Lines_window::continue_next()
{
	string& n = name;
	n = name_box.get_string();
	cout << "Hello " << name << "!\n";
	name_box.hide();
	continue_next_button.hide();
	attach(LSU_button);
	attach(AU_button);
	attach(UF_button);
	rules.move(720,0);
	change.move(-720,0);
}


void Lines_window::cb_LSU(Address, Address pw)//LSU button code
{
	reference_to<Lines_window>(pw).LSU();
}
void Lines_window::LSU()
{
	int& t= team;
	t=1;
	LSU_button.hide();
	AU_button.hide();
	UF_button.hide();
	change.move(720,0);
	hide();
}


void Lines_window::cb_AU(Address, Address pw)//AU button code
{
	reference_to<Lines_window>(pw).AU();
}
void Lines_window::AU()
{
	LSU_button.hide();
	AU_button.hide();
	UF_button.hide();
	int& t= team;
	t=2;
	change.move(720,0);
	hide();
}



void Lines_window::cb_UF(Address, Address pw)//UF button code
{
	reference_to<Lines_window>(pw).UF();
}
void Lines_window::UF()
{
	LSU_button.hide();
	AU_button.hide();
	UF_button.hide();
	int& t= team;
	t=3;
	change.move(720,0);
	hide();
}



void Lines_window::Score_window()		//create simple highscore window
{
	Lines_window win2(Point(175,175),400,510,"High Scores");
	win2.next_button.hide();
	vector<int> scores;
	vector<string> names;
	Read_Score(scores,names);		//reads in the score and name
	Out_box top_s1(Point(50,30),200,20,"1");		//Initializing all the boxes for scores
	win2.attach(top_s1);
	Out_box top_s2(Point(50,50),200,20,"2");
	win2.attach(top_s2);
	Out_box top_s3(Point(50,70),200,20,"3");
	win2.attach(top_s3);
	Out_box top_s4(Point(50,90),200,20,"4");
	win2.attach(top_s4);
	Out_box top_s5(Point(50,110),200,20,"5");
	win2.attach(top_s5);

	vector<string> out;		//Formatting the raw scores and names for output to the boxes
	for(int i=0;i<5;++i)
	{
	stringstream ss;
	ss<<scores[i];
	string temp;
	ss>>temp;
	temp=temp+" "+names[i];
	out.push_back(temp);
	}

	top_s1.put(out[0]);
	top_s2.put(out[1]);
	top_s3.put(out[2]);
	top_s4.put(out[3]);
	top_s5.put(out[4]);

	gui_main();
}
void Initialization()		//Intro window for set-up
	{
		Lines_window win(Point(100,100),720,510,"checkerboard");
		gui_main();
	}

void Game()		//play the game
	{
		Lines_window win1(Point(100,100),720,510,"checkerboard");
		win1.attach(tamu_banner);
		win1.attach(tu_banner);
		win1.attach(field);
		win1.next_button.hide();
		win1.selected = 0;
		win1.clicked = 0;
		vector<vector<My_Button*> >board(8,vector<My_Button*>(8));
		for(int i = 0; i < 8; ++i){										//build the board/buttons
			for(int j = 0; j < 8; ++j){
				board[i][j] = new My_Button(Point(60*j+120, 60*i),
						60, 60, "", Lines_window::cb,
						i, j);
				win1.attach(*board[i][j]);
				board[i][j]->window = &win1;
				board[i][j]->selected = 0;
				board[i][j]->cirle = new Circle(Point(60 *j + 150, 60*i + 30), 23);		//initialize all the circles
				board[i][j]->cirle->set_color(Color::black);
				board[i][j]->cirle->set_style(Line_style(Line_style::solid, 5));
				board[i][j]->board = &board;

				if((i + j) % 2){
					board[i][j]->set_fill_color(Color::white);
				}
				else{
					board[i][j]->set_fill_color(Color::green);
				}
			}
		}
		int human = 1;		//initializing all the buttons and pieces with colors based on team choice
		int machine = 2;
		Color primary=Color::blue;
		Color secondary=Color::yellow;
		if(team==1){
			primary=fl_rgb_color(253,208,35);
			secondary=fl_rgb_color(70,29,124);
		}
		if(team==2){
			primary=fl_rgb_color(204,204,204);
			secondary=fl_rgb_color(153,0,0);
		}
		if(team==3){
			primary=fl_rgb_color(255,74,0);
			secondary=fl_rgb_color(0,33,165);
		}
		board[0][0]->cirle->set_color(Color::white);
		board[0][0]->cirle->set_fill_color(fl_rgb_color(80,0,0));
		win1.attach(*board[0][0]->cirle);
		board[0][0]->selected = human;

		win1.attach(*board[7][1]->cirle);
		board[7][1]->cirle->set_color(primary);
		board[7][1]->cirle->set_fill_color(secondary);
		board[7][1]->selected = machine;

		board[7][3]->cirle->set_color(primary);
		board[7][3]->cirle->set_fill_color(secondary);
		win1.attach(*board[7][3]->cirle);
		board[7][3]->selected = machine;

		board[7][5]->cirle->set_color(primary);
		board[7][5]->cirle->set_fill_color(secondary);
		win1.attach(*board[7][5]->cirle);
		board[7][5]->selected = machine;

		board[7][7]->cirle->set_color(primary);
		board[7][7]->cirle->set_fill_color(secondary);
		win1.attach(*board[7][7]->cirle);
		board[7][7]->selected = machine;
		
		gui_main();
	}
//------------------------------------------------------------------------------

int main() {		//main function
	try { Initialization();		//The initialization window opens up the main menu and team choice
		  Game();				//Opens the game window and lets the user play the game
		}
	catch(exception& e) {
		cerr << "exception: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		cerr << "Some exception\n";
		return 2;
	}
}