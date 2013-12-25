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
  Simple_window win1(Point(100,200),width,400,"Initials AA");
  
  
  Rectangle red(Point(50,50),350,200);
   red.set_fill_color(Color::red);
  Rectangle white(Point(150,50),250,100);
   white.set_fill_color(Color::white);
  Rectangle blue(Point(50,50),100,200);
   blue.set_fill_color(Color::blue);
  
  win1.attach(red);
  win1.attach(white);
  win1.attach(blue);
  
  Closed_polyline star;
  // center(100,150);
  star.add(Point(80,140));
   star.add(Point(60,120));
   star.add(Point(87,120));
   star.add(Point(100,90));
   star.add(Point(113,120));
   star.add(Point(140,120));
   star.add(Point(120,140));
   star.add(Point(130,170));
   star.add(Point(100,150));
   star.add(Point(70,170));
  star.move(0,20);
  star.set_fill_color(Color::white);
 
  win1.attach(star);
 
  
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
