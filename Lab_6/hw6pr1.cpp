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
  
  
  Lines A1;
  A1.add(Point(50,300),Point(100,150));
  A1.add(Point(100,150),Point(150,300));
  A1.add(Point(75,225),Point(125,225));
  A1.set_color(Color::blue);
  A1.set_style(Line_style(Line_style::solid,4));
  win1.attach(A1);
  
  Lines A2;
  A2.add(Point(50,300),Point(100,150));
  A2.add(Point(100,150),Point(150,300));
  A2.add(Point(75,225),Point(125,225));
  A2.set_color(Color::red);
  A2.set_style(Line_style(Line_style::solid,4));
  A2.move(150,0);
  win1.attach(A2);
  
 
  
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
