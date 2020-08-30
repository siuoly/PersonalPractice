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
