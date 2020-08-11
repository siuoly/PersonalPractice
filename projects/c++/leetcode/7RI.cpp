#include<iostream>
#include<vector>
#include<assert.h>
#include<climits>
using namespace std;

int reverse(int x){
	long res=0;	//return result
	
	while(x!=0){
		res *= 10;
		res+=  (x%10);
		x/=10;

	}
	if(res > INT_MAX) res =0;
	if(res < INT_MIN) res =0;
	return res;
}


//Test reverse
void Tre(){
	assert(reverse(123)==321);
	assert(reverse(-123)==-321);
	assert(reverse(120)==21);
	
	assert(reverse(2147483647)==0);
	assert(reverse(-2147483648)==0);
}

int main(){
	//Tre();

}
