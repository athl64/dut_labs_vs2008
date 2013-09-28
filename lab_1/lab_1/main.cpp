#include <iostream>
#include "math.h"
#include "conio.h"

using namespace std;

int main() {
	float a,x,y;
	cout<<"Enter some natural number:";
	cin>>a;
	x=(a+3.2)/2.5;
	cout<<"you entered number "<<a;
	if(a<(-2)) {y=x*x*x*x; cout<<" that < -2, so:\n"; } else if(a>=(-2) && a<0) 
	{y=6-x; cout<<" that > -2 and < 0, so:\n"; } else 
	{y=2*sin(x); cout<<" that > 0, so:\n"; };
	cout<<"x= "<<x<<"\ny= "<<y<<"\n\nthanks for watching";
	getch();
	return 0;
};