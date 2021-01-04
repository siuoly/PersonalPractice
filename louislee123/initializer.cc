#include<iostream>
int sum(std::initializer_list<int> li){
	int s = 0;
	for(auto it = li.begin(); it != li.end(); it++)
		s += *it;
	return s;
}

int sum2(std::initializer_list<int> li){
	int s = 0;
	for(const auto& a:li)
		s += a;
	return s;
}

class A{
	int a;
	public:
		A(int n=0):a(n){}
		A(std::string s ,int n=0 ):a(3){}
		A(std::initializer_list<int> l):a(5){}
		void p(){ std::cout << a <<std::endl;}
};


int main(){
	std::cout << sum( {1,2,3,45,12} ) << '\n';
	std::cout << sum( {} ) <<'\n';
	std::cout << sum2( {1,2,3,45,12} ) << '\n';
	std::cout << sum2( {} );

	A a; a.p();
	A b{1}; b.p();
	A c{"string",10}; c.p();	//constructor
	A d{1,2,3,4,5}; d.p();	// initializer-list
}
