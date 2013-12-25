//Alan Achtenberg
//Engr 112-513
//HW2 PR2


#include "../../std_lib_facilities_3.h"

double ctok(double c) //function that converts celsius to kelvin
{ double k= c+273.15;
return k;}
double ktoc (double k) //function that converts kelvin to celsius
{ double c= k-273.15;
return c;}

int main()
{cout<<"Please input value, then specify the unit(c or k)"; //request user for input

double v=0;
string unit;
cin>>v>>unit;

if (unit=="c"|unit=="celsius"){ //if else statement used to determine which unit is needed and which function to use
	cout<< ctok(v)<<"kelvin\n";}
else {cout<< ktoc(v)<<"celsius\n";}

keep_window_open();
return 0;
}
