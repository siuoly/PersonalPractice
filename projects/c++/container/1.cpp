#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void run();

int main( int argc , char *argv[]){
	
	run();

}


void run()
{
	stack<string> stk;
	stk.push("Hello");
	stk.push("and");
	stk.push("I am louis.");
	
	cout << *stk.begin();
	
	cout << endl;

}
