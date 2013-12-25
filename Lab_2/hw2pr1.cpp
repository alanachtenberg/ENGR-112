//Alan Achtenberg
//Engr 112-513
//HW2 PR1


#include "../../std_lib_facilities_3.h"

double discriminant (double a,double b, double c){//function to calculate the discriminant

	return (b*b)-(4*a*c);}

double residual (double a,double b,double c,double x){ //function to calculate the residual
	return a*x*x+b*x+c;}


int main(){
	double a;//created variables
	double b;
	double c;
	double x1;
	double x2;

	cout<<"please input values a b c to solve the function of the form ax^2+bx+c=0\na=";//prompt for user input of variables a b and c
	cin>>a;
	cout<<"b=";
	cin>>b;
	cout<<"c=";
	cin>>c;


	if (a==0&b==0&c==0){//if statement that outputs that every possible number is a root
		cout<<"every real and complex number is a root\n";
		keep_window_open();//stops the program
	return 0;}
	
	
	if (a==0&b==0&c!=0){//if statement that outputs the equation is inconsistent in other words it is not of the form ax^2+bx+c and has no roots
		cout<<"the equation is inconsistent\n";
	keep_window_open();//stops the program
	return 0;}
	
	if (discriminant(a,b,c)<0){//if statement that outputs the possible roots are complex
		cout<<"the roots are complex\n";
	keep_window_open();//stops the program
	return 0;}
	
	if (a==0&b!=0){//if statement that says there is only one root
		cout<<"there is one root\n";
	}

	if(discriminant(a,b,c)==0){//if statement that outputs there are two of the same roots
		cout<<"there is one double root\n";
	}

	x1=(-b+sqrt((b*b)-(4*a*c)))/(2*a);//calcution of the roots
	x2=(-b-sqrt((b*b)-(4*a*c)))/(2*a);
	double r1=residual(a,b,c,x1);//use of the function to calculate the residual of roots x1 and x2
	double r2=residual(a,b,c,x2);

cout<<"root1:"<<x1<<"\nroot2:"<<x2<<"\nresidual1:"<<r1<<"\nresidual2:"<<r2<<"\n"; //output of the roots and residuals

keep_window_open();
return 0;
}
