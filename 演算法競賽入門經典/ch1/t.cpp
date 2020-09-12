// 學習到:
// 使用<iomanip>
// fixed && setprecision(int n) << defaultfloat
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<cmath>
using namespace std;

int main(){
	unsigned int sum=1;
	for(int i=1 ; i<33; i++)
//	{ sum*=2; cout <<sum-1 << endl; }
	{sum*=2; 	printf("%f\n", sum);}
	int s=-1;
	for(int i=1 ; i<33; i++)
	{ s*=2; printf("%f\n" , s); }


}


/*
 
	printf("%d\n", 8.0/5.0);
	cout <<sqrt(9) << endl;
 */

/*
	const double PI=3.14159;
	double r ,h;
	cin >> r>> h ;
	cout <<"圓柱表面積: " << (2*PI*r*h) + ( 2*PI*r*r ) << endl;
*/
/*
	// 三位數反轉
	int a , ans=0;
	cin >> a;
	while( a>0 ){
		ans = ans*10 + a%10;
		a /= 10 ;
	}
	//cout  << ans <<endl;
	printf("%03d\n" , 3222) ;

*/

/* 實驗A
	printf("%f \n" ,1.1111*1.1111);
	printf("%.10f \n" ,1.11111*1.1111);
	printf("%f\n" ,sqrt(-10) );
	printf("%f \n" ,1.0/0.0);
	printf("%f \n" ,0.0/0.0);
	printf("%d \n" ,1/0);
*/
/*
	int a ,b;
	scanf("%d%d" ,&a ,&b );
	printf("%d %d \n" ,a ,b) ;
*/
/* 如何輸出 %d 文字
	printf("%%d\n") ;
*/

/* 三數平均值
	int a,b,c;
	cin >> a >> b >> c;
	cout << fixed << setprecision(3) << (a+b+c)/3.0 <<endl ;
*/
/* 華氏轉攝氏溫度
	int f;
	cin >> f;
	cout <<fixed << setprecision(3) <<  (f-32)*(5.0/9.0) << endl;
*/
/* 連續和問題
	int n ,sum=0;
	cin >> n;
	for(int i=1 ; i<=n ;i++)
		sum+=i;
	cout << sum <<endl;
*/
/*
	double n , deg; cin >> n;  deg=n*3.14/360.0;
	cout <<"sin of " << n <<": " << fixed <<setprecision(3) << sin(deg) << endl;
	cout << defaultfloat 
			 <<"cos of " << n <<": " << fixed <<setprecision(3) << cos(deg) << endl;
*/
/* 打折
	int n; cin >> n;
	int sum = n*95;
	if( sum> 300)
		cout << fixed << setprecision(2) 
				 <<  sum*0.85 << endl;
	else cout << setprecision(2) 
				 << sum << endl;
	return ;

*/
/* 三角形
	int a[3];
	cin >> a[0] >> a[1] >> a[2] ;
	sort( a,a+3);
	if(a[0]+a[1] <= a[2] ) // Is triangle?
		cout << "not a triangle\n";
	else if( a[0]*a[0] + a[1]*a[1] != a[2]*a[2] ) // Is 直角?
		cout << "no\n";
	else 
		cout << "yes\n";
*/
/*
	// 潤年: 每百不潤 , 每四百再潤
	int y ; cin >> y;
	if( y%400==0 ) cout <<"yes\n" ;
	else if ( y%100==0) cout <<"no\n" ;
	else if ( y%4 ==0 ) cout <<"yes\n" ;
	else cout << "no\n" ;

*/
/*
	// a && b || c 等效於 (a && b) || c
	int a=1 , b=0, c=0 ;
	if( a && b || c)
		cout <<"true\n";
	else 
		cout <<"false\n";
*/
/*
	if(true)
		if(false)
			cout <<"in\n";
		else
			cout <<"in f\n" ;

*/

/*

*/
/*

*/
/*

*/
/*

*/


