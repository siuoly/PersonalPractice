#include<iostream>
#include<algorithm>
using namespace std;
void sol(){

}

int main(){
	int n,m;
	int a[20001] , b[20001]; // a:騎士 b:龍頭
	while(scanf("%d%d",&n ,&m) == 2)
	{
		if(n==0 && m==0) break;
		
		// 龍頭輸入
		for(int i=0;i<n;i++)
			cin >> b[i];
		// 騎士輸入
		for(int i=0;i<m;i++)
			cin >> a[i];
		sort(a,a+m);
		sort(b,b+n);
		int sum=0 , no=0;
		for(int i=0;i<n;i++)
		{
			if(a[no] >= b[i]){ sum+=a[no]; no++; }
			else { no++ ; i--;}  // i-- for loop again
			if(no==m) break;
		}
		
		if(no == m) cout << "Loowater is doomed!\n";
		else cout << sum <<'\n' ;
		
	}
}
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
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct PPair{
	int a,b;
	bool operator < (const PPair& x)const
	{	return a<x.a ;}
};
int main(){
	int n=3;
	vector<PPair> p;
	int a,b;
	for(int i=0 ; i<3; i++){
		cin >> a >> b;
		p.push_back( (PPair){a,b} );
	}
	sort(p.begin() , p.end() );

	for(int i=0 ; i<n ;i++)
		printf("%d: %d ,%d\n" , i ,p[i].a ,p[i].b);
}
#include<iostream>
#include<map>
using namespace std;
void sol(){
	int len=0,time=0 , num=0;
	cin >> len >> time >> num;
	int pos[10001];
	char dir[10001];
	char anpos[10000]={ 0 };
	for(int i=0;i<num;i++)
		cin >> pos[i] >> dir[i];
	for(int i=0;i<time;i++)
	{
		for(int j=0;j<num;j++)
		{
			if(dir[j]=='L') pos[j]--;
			else if(dir[j]='R') pos[j]++;
			else ;
			anpos[ posi[j] ] = j;
		}
		for(int =0;j<10000<j++)
		{
			
		}
	}
}

int main(){
	int kase=0;
	cin >>kase;

	while(kase--)
	{
		sol();
	}

}
