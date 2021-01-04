#include<iostream>
#include<functional>
using namespace std;

int j = 10;
class A{
	public:
		int operator()(int i){ return i;}
};

void f2(){ };
void copyfunc(){cout <<"function copy";}

int main(){
	// static, global variable not need "capture list"
	auto add = [](int a, int b){ return j+a+b; } ;
	cout << add( 1,1) << endl;	

	// local variable need "capture list"
	int j = 5;
	auto l_add = [j](int a, int b){ return j+a+b; } ;
	cout << l_add( 0 , 0) << endl;

	// call lambda
	[](){}; //ok
	[]{};		//ok
	[](){cout << "this is call lambda";} ;	// ok

	// evaluate return type
	[](int i){ return i<0 ? -i : i;} ;			// OK
	[](int i){ ++--i; return i<0 ? -i : i;} ; // OK, ??
	auto f = [](int i){ if(i < 0) return -i;	// OK
		else return i;} ;
	cout << sizeof(f) << endl;

	// bind use
	auto f2 = bind(f,5);
	cout << sizeof(bind(f,1)) << endl;
	cout << sizeof(f2) << endl;
	
}
