#include<iostream>
using std::cout ;

//example3
int main(){
	const int i=5, &a=i ;
	auto b=i;  b++; cout <<"b="<<b<<'\n';
	decltype(i) c=i ; c++; cout <<"c="<<c<<'\n'; //error
	

}

//example2
/*
int main(){
	int a=3,b=4;
	decltype(a) c=a;  //int c=a, c=3
	decltype(a=b) d=a;// int &d=a ,1 a=b=4, 2 d=a=4, d=4
	cout << a;
}
*/

// example1
/* int main(){
	int a=3 ,b=4;
	decltype(a) c =a; //c=3
	decltype((b)) d=a; //int& d=a
	++c;   //c=4
	++d;  // d=4,a=4
	cout << a;
}
*/
