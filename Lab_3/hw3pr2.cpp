#include "std_lib_facilities_3.h"

class BadArea{};
class overflow{};

int area(int length, int width){
	if(length <= 0 || width <=0) throw BadArea();
	if(length*width<0||(((length*width)/length)!=width)) throw overflow();
	return length*width;
}

double mysqrt(double x){
	if(x < 0.0) error("mysqrt");
	//Use 3 iterations of the Newton-Raphson method for mysqrt
      if (x==0) return 0;
      if (x==1) return 1;
	  double z=((x*x*x*x)+28*(x*x*x)+70*(x*x)+28*x+1)/(8*(1+x)*(1+6*x+(x*x)));
	return z;
		
}

int main(){
	int a=0;
	while(a==0){
	try{cout<<"input length and width as integers\n";
	int length=0;
	int width=0;

	if (cin>>length>>width)
	{
	cout << area(length,width) << '\n';
	cout << mysqrt(area(length,width)) << '\n';
	}
	else return 0;

	}
	catch(overflow){
		cerr<<"Exception: overflow\n";
	}
	catch(BadArea){
		cerr << "Exception: bad area\n";
	}
	catch(exception& e){
		cerr << "Exception: " << e.what() << '\n';
	}
	catch(...){
		cerr << "Exception occurred\n";
	}
	}
}