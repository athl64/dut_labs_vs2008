#include <conio.h>
#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main() {
    float a=0,x=0,y=0;
    cout<<"enter number for calculating:";
    cin>>a;
    x=(a+1.6)/3.8;
    if(x>0 && x<8) {
        y=pow((2*x+4.5),3);
    } else if(x<=0 || x>20) {
        y=-(pow(x,3));
    } else if(x>=8 && x<=20) {
        y=sqrt(3*x+5);
    };
    cout<<"\ncalculating complete, results:\nx = "<<x<<"\ny = "<<y<<"\npress any key to exit...\n";
    getch();
    return 0;
}
