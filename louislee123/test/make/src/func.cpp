#include "FILE.h"
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<fstream>
#include<sstream>
using namespace std;



void manipuUsage(){

	// cout << showbase << showpos << hex << fixed << setfill('_') ;
	cout.setf( ios_base::showbase|ios_base::showpos|ios::hex|ios::fixed );
	cout.fill(65);
	for(int i= 1;i<10;i++)
	{
		for(int j = 1 ;j<10 ;j++)
		{	cout.width(5);	cout << i*j << ' '; }
		cout << endl;
	}
}

void stringstreamUseage(){
	stringstream s1("your name is Fun");
	stringstream s2("my name is louis");
	string s("file");
	
	cout << "Before move s1: " << s1.str() << '\n' ;
	s1 = std::move(s2) ; 
	cout << "After move s1=std::move(s2);\n  \t   s1: " <<  s1.str() << '\n';
	
	cout  <<"end\n";
}


