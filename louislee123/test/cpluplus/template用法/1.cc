#include<iostream>
#include"h.h"
using namespace std;
extern template int  func(int n);

int main(int argc, char*argv[])
{
	cout << func(10); 
}
