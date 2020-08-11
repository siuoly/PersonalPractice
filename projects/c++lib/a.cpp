#include<iostream>
#include<vector>
#include "t.h"
using namespace std;



int main(){
	
	vector<int> v;
	for(int i=0;i<10;i++)
		v.push_back(2*i);

	print(v);
}
