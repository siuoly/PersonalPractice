#include<iostream>
using namespace std;

class A{
	int a;
	public:
		A(int n=0):a(n){}
		A(string s ,int n=0 ):a(3){}
		A(initializer_list<int> l):a(5){}
		void p(){ cout << a <<endl;}
};

// trailing return type
// auto func(int i) -> int;

int main(){
	A a; a.p();					//constructor 
	A b{1}; b.p();					// initializer-list
	A c{"string",10}; c.p();	//constructor
	A d{1,2,3,4,5}; d.p();	// initializer-list
	//A e={"123","456"}; e.p();	// error invalid conversion
	//A f={1.0,2,3,4}; f.p();	// error narrow conversion
}

// initializer-list 優點:
// type檢查(narrow conversion)
// 轉型呼叫constructor
// 
