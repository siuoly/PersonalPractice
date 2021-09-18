#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int MAX=1000;
int num[MAX];

int main(){
	int n,q,x,a[MAX],kase=0;
	while( scanf("%d%d", &n ,&q) ==2 ){
		printf("CASE# %d:\n",++kase );
		for( int i=0 ; i<n ; i++)  scanf("%d", &a[i]) ;
		sort(a , a+n);
		while( q--){
			scanf("%d" ,&x);
			// 在以排序陣列中找x
			int p = lower_bound( a,a+n, x ) -a;
			if( a[p]==x)	printf("%d found at %d\n", x, p+1 );
			else printf( "%d not found\n" , &x);
		}
		
	}
	return 0;
	//case 1 2 3 .....

	//read number stream

	//sort series 

	//search
}
