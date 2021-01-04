#include<iostream>
#include<cstdlib>
#include<sstream>
#include<locale>
using namespace std;

void localset(){
		istringstream is;	
		cout << cout.getloc().name() << '\n';
		locale loc("");	
		cout << "Hello  こんにちわ我是李彥銀樓" << '\n';	
		
		cout.imbue(loc);
		cout << cout.getloc().name() << '\n';
		cout << "Hello  こんにちわ我是李彥銀樓" << '\n';	

}
int main(){

	
	cout << "ios";

}
