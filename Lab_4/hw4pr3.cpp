//Alan Achtenberg
//Engr 112-513
//HW4 PR3


#include "std_lib_facilities_3.h"

int main(){

	vector<int> cash={0,0,0,0,0,0,0};//created a vector of size 7 with integer types to store cash values
	vector<double> cash_value={1,2,5,10,20,50,100};
	
double change;
	cout<<"How much cash do you have?\n"; //query the user for input and input directly into vector cash
	cin>>change;
int i=6;
while (i!=0){
	double t=1;
	double rem=2;
	double x=(change/cash_value[i]);
		if (x>=1){
			if(x!=1){
		
			while (rem>1){
			++t;
			rem=change/(t*cash_value[i]);
				}
		cash[i]=(--t);
			}
			else cash[i]=1;
		
		}
		else cash[i]=0;
		if (cash[i]!=0)
		change=change-cash_value[i]*t;
		--i;
	cash[i]=t;
}
cash[0]=change;
cout<<"your change is\n";
if(cash[0]>0)
	cout<<cash[0]<<" dollar bills\n";//output in a list the number of bills
if(cash[1]>0)
	cout<<cash[1]<<" two dollar bills\n";
if(cash[2]>0)
	cout<<cash[2]<<"  five dollar bills\n";
if(cash[3]>0)
	cout<<cash[3]<<" ten dollar bills\n";
if(cash[4]>0)
	cout<<cash[4]<<" twenty dollar bills\n";
if(cash[5]>0)
	cout<<cash[5]<<" fifty dollar bills\n";
if(cash[6]>0)
	cout<<cash[6]<<" hundred dollar bills\n\n";
keep_window_open();
return 0;
}
