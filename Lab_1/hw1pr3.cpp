#include "std_lib_facilities_3.h"

int main(){

	string operation=""; // initialize string and doubles.
	double operand1=0;
	double operand2=0;
	cout<< "Please input your first operand followed by your operator followed by your second operand.(must include space between objects)\n"; // prompt user for input
	cin>>operand1;
	cin>>operation;
	cin>>operand2;
	
	if (operation=="+"|operation=="plus"){
		cout<<operand1<<" "<<operation<<" "<<operand2<<"="<<operand1+operand2<<"\n";} //if statement combined with the or operator to output the 2 addition cases
	if (operation=="-"|operation=="minus"){
		cout<<operand1<<" "<<operation<<" "<<operand2<<"="<<operand1-operand2<<"\n";} //if statement combined with the or operator to output the 2 subtraction cases
	if (operation=="*"|operation=="mul"){
		cout<<operand1<<" "<<operation<<" "<<operand2<<"="<<operand1*operand2<<"\n";} //if statement combined with the or operator to output the 2 multiplication cases 
	if (operation=="/"|operation=="div"){
		cout<<operand1<<" "<<operation<<" "<<operand2<<"="<<operand1/operand2<<"\n";} //if statement combined with the or operator to output the 2 division cases
	keep_window_open();
	return 0;}