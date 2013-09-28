#include <iostream>
#include "conio.h"
#include "math.h"

const double x=4;

using namespace std;

int main() {

	double y=0,y1=0,tmp=0;
	cout<<"starting thinking...\n";
	for(int i=0;i<=20;i++) {
	tmp = pow((-1.0),i)*(1.0/((2*i+1)*pow(x,(2*i+1))));
	y+=tmp;
	cout<<"y("<<i<<")= \t"<<tmp<<"\n";
	if(i==20) {cout<<"---------------------------------------------\n...and this is it, looking for summ:\n\n";};
	};
	y1=atan(x);
	cout<<"x = "<<x<<"\ny = "<<y<<"\ny1 = "<<y1<<"\n\nthat's all, press enter";
	getch();

	return 0;

}