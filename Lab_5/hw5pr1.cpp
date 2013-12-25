//Alan Achtenberg
//Engr 112-513
//HW4 PR1
#include "std_lib_facilities_3.h"

int main()
{
 string web_file;
 
 cout<<"input the url of the web text file.\n";
 cin>>web_file;
 string temp=web_file.substr(0,7);
 if (temp!="http://") error("web file does not begin with http://\n");

 temp="wget "+web_file+" -O example.txt";
 system(temp.c_str());
 temp="pico example.txt";
system(temp.c_str());
 keep_window_open();
 return 0;
 
 
 }