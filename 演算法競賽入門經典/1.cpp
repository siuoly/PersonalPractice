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
