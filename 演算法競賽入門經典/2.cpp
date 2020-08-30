#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Job{
	int j ,b;
	// 大於 小於 return type: bool
	// 物件Job 接 Job& x
	// 函數: const  
	// 此三項 是 sort自訂的關鍵點
	bool operator< (const Job& x) const
	{ return j > x.j; } // 欲使由大到小 排序
};
int main(){
	const int maxn = 10000 +5 ;
	int n ,kase =0;
	while( cin>>n && n)
	{
		vector<Job> v;
		int j , b;
		for(int i=0 ;i<n ;i++)
		{	cin >> b >> j;  v.push_back( (Job){ j ,b } ); }
		
		sort(v.begin() , v.end() );
		int s=0 ,ans=0 ;
		// 交代任務時間 由長到短 排序
		// 目前為止交代時間 + 任務時間:  為可能候補
		// 把上數答案 取最大值  即結果
		for(int i=0 ; i<n ; i++)
		{	
			s+= v[i].b;
			ans = max( ans ,s+v[i].j );
		}
		cout << "Case "<< ++kase <<": "<<  ans << endl ;
	}
}
