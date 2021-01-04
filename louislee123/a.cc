#include<iostream>
class A{
	public:
	int n;
	virtual A foo(){ A a; return a;}
	virtual void call(){ std::cout << "A";}
};

class B:public A{
	virtual A foo()override{ std::cout<<"bfoo"; B b; return b;}
	virtual void call()override{ std::cout << "B";}
};

int main(int argc, char*argv[])
{
	B b; A &a=b;
	A&& a2 = a.foo();
	//A& a3=b;
	//a3.call();
	a2.call();
}
