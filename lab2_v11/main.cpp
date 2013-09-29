#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

const double x = 11.0;

int main() {
    cout<<"start calculating summ for series of numbers...\n\n";
    double y=0,y1=0,tmp=0;
    for(int i=0;i<=20;i++) {
        tmp+=( pow((-1),i+1)*( pow(x,2*i+1)/(2*i+1) ) );
        cout<<"sum for n"<<i<<" = \t"<<tmp<<"\n";
    }
    y=(M_PI/2)+tmp;
    y1=atan(x);
    cout<<"y = "<<y<<"\ny1 = "<<y1<<"\n\npress any key to exit...";
    getch();
    return 0;
}
