#include <iostream>
#include <conio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

using namespace std;

int menu() {
    char in=' ';
    int a=0;
    cout<<"\n+++++++++++++++++++++++++++++++++++++\nmenu:\n";
    cout<<"1 - write to file in append mode\n";
    cout<<"2 - read from file\n";
    cout<<"3 - calculate count of numbers that bigger than inputed\n";
    cout<<"4 - exit\n";
    cout<<"type your command:";
    in = getch();
    if(isdigit(in) && (in=='1' || in=='2' || in=='3' || in=='4') ) {
        a = atoi(&in);
        cout<<"\n";
        return a;
    } else {
        cout<<"wrong command\n\n";
        return -1;
    }
}

int inputed_number() {
    char in = ' ';
    int a=0;
    cout<<"enter number for scan:";
    do {
        in = getch();
    } while(!isdigit(in));
    a = atoi(&in);
    cout<<"\nentered "<<a<<"\n";
    return a;
}

int print_file(char *name) {
    char c;
    FILE *f;
    if( (f = fopen(name,"r"))!=NULL ) {
        cout<<"\n###############-file contetn start-###################\n";
        while( !feof(f) ) {
            c = fgetc(f);
            cout<<c;
        }//while
        cout<<"\n################-file contetn end-####################\n";
        fclose(f);
        cout<<"\n";
    }//if fopen
    return 0;
}

int write_file(char *name) {
    string c;
    FILE *f;
    if( (f = fopen(name,"a+")) ) {
        cout<<"enter numbers for writing:";
        cin>>c;
        fputs(c.data(),f);
        fclose(f);
        cout<<"\nwrited\n";
    }//if fopen
    return 0;
}

int counter(char *name, int a=0) {
    char c;
    int b=0,count=0;
    FILE *f;
    if( (f = fopen(name,"r"))!=NULL ) {
        while( !feof(f) ) {
            c = fgetc(f);
            if(isdigit(c)) {
                b=atoi(&c);
            }
            if(b>a) {
                count++;
            }
            cout<<"\ncount = "<<count<<"\n";
        }//while
        fclose(f);
    }//if fopen
    return count;
}

int main() {
    int menu_i=0,inputed_for_scan=0;
    do {
        menu_i = menu();
        switch (menu_i) {
            //write to file
        case 1: {
            cout<<"chosed writing to file\a\n";
            write_file("SourceCount.txt");
            break;
        }
            //show file content
        case 2: {
            cout<<"chosed showing file content\a\n";
            print_file("SourceCount.txt");
            break;
        }
            //scan file for inputed number and calculate count of it
        case 3: {
            cout<<"chosed scaning for inputed number\a\n";
            inputed_for_scan = inputed_number();
            cout<<"there are "<<counter("SourceCount.txt",inputed_for_scan)<<" numbers that bigger than "<<inputed_for_scan<<"\n";
            break;
        }
            //exit
        case 4: {
            cout<<"chosed exit\n\nbye\a\a\n";
            exit(0);
            break;
        }
        default: {
            break;
        }
        }//switch
    } while(1);
    return 0;
}
