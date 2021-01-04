#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

void readcpp(){
	// read 1.cpp
	string tmp;
	ifstream ifs("1.cpp");
	if(!ifs.is_open())	cerr <<"open fail";

	while( ifs >> tmp)
		cout << tmp << endl;


	// write to {2..100}.cpp
}

int main(){
	char cmd[50];	

	for( int i=2; i< 100 ;i++)
	{
		sprintf(cmd , "cp 1.cpp file%d.cpp" ,i);
		system(	cmd ); 
	}
}
