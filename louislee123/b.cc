#include<iostream>
#include<iomanip>
using namespace std;

int i=5,j,k;
namespace{
	int n1,n2,n3;
	double d1=3.2,d2;
}
static int s;

int main(){
	cout << n1 << n2<< n3;
	cout << i << j << k;
	cout << d1 << d2;
	cout << s;
	extern int g; // compiler 過 linker不會過
	cout << g;
}

// function 以外宣告變數(variable)自動 initialize
// 其他地方需要 手動initialize

// extern 可用外部檔案定義的 object
// static 宣告並定義的檔案不會被外部所用
