#include<iostream>
using namespace std;


template<typename T>
void print(T& );

template<typename T>
void print(T& v)
{
	for(auto i= v.begin() ; i!=v.end();i++)
		cout << *i <<" ";
	cout << endl;
}

