#include<iostream>
using namespace std;

int d[]={1,2,3,4};
int e[10]={1,2,3,4};
int c[]{1,2,3,4};
int f[10]={};

class A{
	int i=5;
	public:
		void p(){ cout << i  ;}
		A():i(10){}
};

class B{
	int i{7}; // OK, constructor
	int j=5;	// OK, need copy-constructor
	//int k(9); // error
	public:
		void p(){ cout << i  ;}
};


int main(){
	A a;
	a.p();
	cout << endl;
	B b;
	b.p();
}
// member initialization 優先於 in-class initializer
