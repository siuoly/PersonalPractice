#include<iostream>

using namespace std;

bool great(int a,int b)
{ return a>b; }

bool lesser(int a ,int b)
{ return a<b; }

void relation( int a ,int b ,bool (*cmp)(int , int) )
{
	cout << boolalpha <<  cmp(a,b);
}

int main(){
	//relation( 10 , 5 , great);
	

}
