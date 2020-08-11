#include<iostream>
using namespace std;

int main(){
	//input string
	char str[100];
	cin >> str;
	//each char - 7 output string
	for(int i=0 ; i< 100;i++)
	{	
		if(str[i]!=0)
			str[i]-=7;
	}
	cout << str;
}
