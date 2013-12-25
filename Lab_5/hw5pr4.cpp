//Alan Achtenberg
//Engr 112-513
//HW4 PR4

#include "std_lib_facilities_3.h"

int main()
{
 string web_file;
 
 cout<<"input the url of the web text file.\n";
 cin>>web_file;
 string temp=web_file.substr(0,7);
 if (temp!="http://") error("web file does not begin with http://\n");
 int size=web_file.size();
 size=size-3;
 temp=web_file.substr(size,3);
 if (temp=="pdf"||temp=="PDF"){ 

 temp="wget "+web_file+" -O example.pdf";
 system(temp.c_str());
 temp="/pub/daugher/ubuntu/10.04LTS/xpdf.bin webfile.pdf example.pdf";
system(temp.c_str());
 }
 else error("web file is not a pdf\n");
 keep_window_open();
 return 0;
 
 
 }