#include "std_lib_facilities_3.h"
#include "Simple_window.h"
#include "Graph.h"
#include "GUI.h"

int main()
try {
	int width = 600;
	int old_width;
  if(H112 != 201206L)error("Error: incorrect std_lib_facilities_3.h version ",
		  	   H112);
  Simple_window win1(Point(100,200),width,400,"Olympic Rings");
  
  Line_style(Line_style::solid,2);
  Circle top_left(Point(25,25),23);
  Circle top_mid(Point(75,25),23);
  Circle top_right(Point(125,25),23);
  Circle bot_left(Point(50,50),23);
  Circle bot_right(Point(100,50),23);
  
  top_left.set_color(Color::blue);
  top_right.set_color(Color::red);
  bot_right.set_color(Color::green);
  bot_left.set_color(Color::yellow);
  
  top_left.set_style(Line_style(Line_style::solid,2));
  top_mid.set_style(Line_style(Line_style::solid,2));
  top_right.set_style(Line_style(Line_style::solid,2));
  bot_right.set_style(Line_style(Line_style::solid,2));
  bot_left.set_style(Line_style(Line_style::solid,2));
  
  win1.attach(top_left);
  win1.attach(top_mid);
  win1.attach(top_right);
  win1.attach(bot_left);
  win1.attach(bot_right);
  
  
  while(true){
	win1.redraw();
	width = win1.Fl_Widget::w();
	old_width = width;
	cout << old_width << endl;
    do{
	Fl::wait(1);	//wait up to 1 second
	width = win1.Fl_Widget::w();
    }while(width == old_width);
  }
  return 0;
}
catch(exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Some exception\n";
	return 2;
}
