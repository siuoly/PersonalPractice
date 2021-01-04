#include<iostream>
#include<cassert>
using namespace std;

constexpr int fac(size_t n){ return n*fac(n-1); }
constexpr int add(size_t n){ return n * 5; }

int main(){
	int a = 5;
	int b = a*add(5);
}
// assert 不能輸出recursion 位置
// 但是自訂的功能 不能取代 assert
// 優點在於可以輸出資料結構
