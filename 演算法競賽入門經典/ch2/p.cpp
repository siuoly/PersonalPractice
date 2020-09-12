#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

struct Permutation{
	static const int NUM=6;
	bool use[NUM]; int a[NUM];
	
	Permutation()
	{	
		for(int i=0;i<NUM;i++) use[i]=false;
		backtrack(0 , NUM);	
	}
	
	void backtrack(int n, int N)
	{
		if(n==N){ // 列印字串	
			for(int i=0; i<N;i++) cout << a[i]; 
			cout << endl;
			return;
		}

	// use[i]會依序往後固定1->2->3->...
	// 並且倒回 1->2->3  ==>  1->2 ==> 1->2->3
	// 遞迴呼叫 
		for(int i=0; i<N; i++)
		{
			if(!use[i])  // 當下固定位置
			{
				use[i]=true;
				a[n]=i; 	// 決定要輸出ary內容
				backtrack(n+1,N); // 輸出下一輪ary
				use[i]=false; // 代表輸出完
			}
		}


	}	

};


int main(){

// 排列2 permutation
	struct Permutation a;	



// 排列 permutation
/*	int a,b,c,d,e,f,g,h,i;
	for(a=1;a<10;a=(a+1)%10+1)
	for(b=(a+1)%10; b!=a; b=(b+1)%10+1)
	for(c=(b+1)%10; c!=a && c!=b ; c=(c+1)%10+1)
	for(d=(c+1)%10; d!=a && d!=b && d!=c ; d=(d+1)%10+1)
	for(e=(d+1)%10; e!=a && e!=b && e!=c && e!=d ; e=(e+1)%10+1)
	for(f=(e+1)%10; f!=a && f!=b && f!=c && f!=d && f!=e ; f=(f+1)%10+1)
	for(g=(f+1)%10; g!=a && g!=b && g!=c && g!=d && g!=e && g!=f ; g=(g+1)%10+1)
	for(h=(g+1)%10; h!=a && h!=b && h!=c && h!=d && h!=e && h!=f && h!=g ; h=(h+1)%10+1)
	for(i=(h+1)%10; i!=a && i!=b && i!=c && i!=d && i!=e && i!=f && i!=g && i!=h ; i=(i+1)%10+1)
	{	
		int abc = (100*a + 10*b + c);
		int def = (100*d + 10*e + f);
		int ghi = (100*g + 10*h + i);  
		if( 2*abc==def && 3*abc==ghi ) 
			cout << abc <<':' <<def <<':' << ghi << endl ; 
	}
*/

/*
// 分數化小數 decimal
	int a ,b ,c ,kase=1 ;
	while( cin >> a >>b>>c && !(a==0 && b==0 && c==0 ) )
	{
		if( a>106 || b> 106 || c>100 )
		{	cout << "a or b or c is out range.\n"; continue; }
		double ans = (double)a/b ;
		cout << "Case " << kase++ <<": " << fixed << setprecision(c) 
																		<< ans << endl;
	}
*/	

/*
//子序列和 subsequence
	long m ,n;
	while( cin >> n >>m && m!=0 && n!=0)
	{
		if(n>m) { cout <<"n>m" << endl ; continue; }
		
		double sum =0;		
		for( ; n<=m ;n++)		sum+= 1/(double)(n*n) ;
		cout << fixed << setprecision(5) << sum << endl ;
	}
*/

/*
//倒三角形 triangle
	int n; cin >> n;

	if(n>19)	{ cout << "out range. n<20.\n"; exit(0); }
	
	for(int i=0 ;i<n; i++)
	{
		for(int j=0; j<i; j++) cout<<' ';
		for(int j=0; j< 2*(n-i)-1; j++)	cout << '*';
		cout << endl;
	}
*/

/*
//韓信點兵 hanxin
	int a ,b ,c;
	while( cin >>a >>b >>c)
	{
		for( int i= 10 ;i <100 ; i++)
		{
			if(i%3!=a || i%5!=b || i%7!=c) 
			{
				if(i== 99) cout <<"No answer" << endl; // 迴圈尾: 輸出問題
				continue;															//迴圈中: 下一次迴圈
			}
			cout << "人數: " <<  i << endl; break;
			
		}
	}
*/



/*
// 水仙花數 Narcissistic number
	int a ,b ,c , kase=1 ;
	for( int i = 100 ; i< 1000; i++)
	{
		a = i /100; b = (i/10)%10; c = i%10;  // that i = abc form
		if( pow(a,3) + pow(b,3) + pow(c,3) ==i ) 
			cout << "case" << kase++ << ": " << i <<endl; 
	}
*/


}
