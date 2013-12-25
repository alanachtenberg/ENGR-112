//Alan Achtenberg
//Engr 112-513
//HW3 PR4


#include "std_lib_facilities_3.h"
double mysqrt(double x){
	if(x < 0.0) error("mysqrt");
      if (x==0) return 0;
      if (x==1) return 1;
	  double z=(x*x*x*x+28*x*x*x+70*x*x+28*x+1)/(8*(1 + x)*(1 +6*x+x*x));;
	  return z;}

int main()
{
	double i=1;
	while (abs(mysqrt(i)-sqrt(i))/sqrt(i)<.01){
		cout<<mysqrt(i)<<"  "<<sqrt(i)<<"\n\n";
		i++;
	}
	cout<<mysqrt(i)<<"  "<<sqrt(i)<<"\n\n";
	cout<< i<< " is the smallest integer with error greater than 1 percent\n";
	keep_window_open();

return 0;
}
		

