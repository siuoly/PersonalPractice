#include<iostream>
#include<vector>
#include"t.h"

template<typename T>
void print(T& v)
{

	for(auto i= v.begin() ; i!=v.end();i++)
		std::cout << *i <<" ";
	std::cout << std::endl;
}

template void print<std::vector<int> >(std::vector<int>& v );

