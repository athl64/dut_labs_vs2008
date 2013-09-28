#include <iostream>
#include "conio.h"//getch
#include "stdio.h"
#include "ctype.h"//isdigit

using namespace std;

int menu() {

	int in=0;
	char inc;
	cout<<"\n|---------------\n|  menu:\n";
	cout<<"|  1.write to file\n";
	cout<<"|  2.find max number\n";
	cout<<"|  3.print file content\n";
	cout<<"|  0.exit\n";
	cout<<"|  type your command:";
	cin>>inc;
	if(isdigit(inc)) { in=atoi(&inc); return in; } else { return -1; };
	cout<<"|---------------\n";
	
	//return in;
}

int f_max() {

	FILE *ff;
	int ps=0, max=0, tmp_max=0, i=0;
	char g;
	fpos_t pos;
	if( (ff = fopen("maxnum.txt","r")) ) { 
		while(!feof(ff)) { g=fgetc(ff); tmp_max = atoi(&g); if(tmp_max>max) {max = tmp_max; /*ps=fgetpos(ff,&pos);*/ }; };
		fseek(ff,0,SEEK_SET);
		while(!feof(ff)) { g=fgetc(ff); tmp_max = atoi(&g); if(tmp_max==max) {i++; ps=ftell(ff);} };
		fclose(ff);
		cout<<"file content "<<i<<" maximum digit, and it is "<<max<<", last position is "<<ps<<".\n";
		return ps;
	};//endif fopen
	return -1;
}

int main() {

	int tmp_menu=0;
	FILE *f;
	char readed = '0',ch;
	//if( (f = fopen("maxnum.txt","w+")) ) {
		do {tmp_menu = menu();
		switch (tmp_menu)
		{
		case 0: {exit(0); break;};
		case 3: { if( (f = fopen("maxnum.txt","r")) ) { cout<<"selected 3:\n"; cout<<"\n###file content:##########\n"; while(!feof(f)) {readed = fgetc(f); cout<<readed;}; cout<<"\n##########################\n"; fclose(f); break;}; };
		case 1: { if( (f = fopen("maxnum.txt","w")) ) { cout<<"selected 1:\n"; cout<<"type your digits or x when done:\n"; do{ch=getch(); if(isdigit(ch)) {fputc(ch,f); cout<<"writed "<<ch<<"\n";} } while(ch!='x'); fputc('\n',f); fclose(f); break;}; };
		case 2: { cout<<"selected 2:\n"; f_max(); break; };
		}//switch end
		} while(tmp_menu!=0);
	//}//if end

	//fclose(f);

	//getch();
	return 0;

}