#include<iostream>
#include<cstdlib>
#include<sstream>
#include<fstream>
#include<iomanip>
using namespace std;

// format string create s = file1 , file2 , ... , file100
void formatteString(){

	stringstream ss;
	string s = "file";
	// mission: integer to char to string
	for( int i=1 ;i<100;i++)
	{
		ss << "file" << i << ".cpp ";		
		ss >> s;
		cout <<  s << "\n";
		// ofstream os(s);
		// os.close();
	}
}
int main(){
	// print the string 
	formatteString();	


}

