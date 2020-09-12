#include<iostream>
#include<stdlib.h>
using namespace std;

int main(){
	//input string
	string str;	getline(cin,str);	//each char - 7 output string 
	for(int i=0 ; i< str.size();i++) 
	{	
		if(str[i]!=0)
			str[i]-=7;
	}
	cout << str;
}
