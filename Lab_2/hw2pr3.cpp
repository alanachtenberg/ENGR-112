//Alan Achtenberg
//Engr 112-513
//HW2 PR3


#include "../../std_lib_facilities_3.h"

int main(){

	vector<int>cash(7);//created a vector of size 7 with integer types to store cash values

	

	cout<<"How many one dollar bills do you have?\n"; //query the user for input and input directly into vector cash
	cin>>cash[0];
	cout<<"How many two dollar bills do you have?\n";
	cin>>cash[1];
	cout<<"How many five dollar bills do you have?\n";
	cin>>cash[2];
	cout<<"How many ten dollar bills do you have?\n";
	cin>> cash[3];
	cout<<"How many twenty dollar bills do you have?\n";
	cin>>cash[4];
	cout<<"How many fifty dollar bills do you have?\n";
	cin>> cash[5];
	cout<<"How many Hundred dollar bills do you have?\n";
	cin>> cash[6];

	int total;// find total value by adding the components of the vector multiplyed by their corresponding cash value
	total=cash[0]+cash[1]*2+cash[2]*5+cash[3]*10+cash[4]*20+cash[5]*50+cash[6]*100;

	cout<<"You have "<<cash[0]<<" dollar bills\n";//output in a list the number of bills
	cout<<"You have "<<cash[1]<<" two dollar bills\n";
	cout<<"You have "<<cash[2]<<"  five dollar bills\n";
	cout<<"You have "<<cash[3]<<" ten dollar bills\n";
	cout<<"You have "<<cash[4]<<" twenty dollar bills\n";
	cout<<"You have "<<cash[5]<<" fifty dollar bills\n";
	cout<<"You have "<<cash[6]<<" hundred dollar bills\n\n";
	cout<<"the value of all of your bills is "<<total<<" dollars.\n";//output the total
keep_window_open();
return 0;
}
