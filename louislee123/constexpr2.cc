#include <stdio.h>
constexpr int fib(int n)
{
	if (n <= 0) {
		return 1;
	}
	return fib(n - 1) + fib(n - 2);
}
constexpr int factor(int n)
{
	if( n==1)
		return 1;
	return n*factor(n-1);
}
enum FIB_ENUM {
	a = fib(5),
	b = fib(10),
	c = fib(20),
	dummy = fib(0)
};

int main()
{
	FIB_ENUM my_fib = a;
	printf("%d %d %d\n", my_fib, FIB_ENUM::b, FIB_ENUM::c);
	// 8 89 10946
	printf("%d" , factor(5));
}
