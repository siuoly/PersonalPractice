#include<iostream>
#include "tree.h"
using namespace std;

int main(){
	Node n1('a');
	cout << n1.data;
	n1.addData('b');
	cout << n1.next->data;



}
