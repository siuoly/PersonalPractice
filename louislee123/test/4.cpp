#include<iostream>
#include<cstdlib>

using namespace std;

template<class Type, int n>
Type sum(Type x){ return n*x ;}

int main(){
	
	for( int i = 0 ;i<100000;i++)
			cout << sum<int, 10>(i);

}
