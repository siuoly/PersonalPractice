#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef vector<char> vc;

// get pattern prefix function
vc prefix_fun( vc& pat)
{
	vc pre(pat.size());
	pre[0]=0;
	int k = -1;
	for(int i=1;i<pat.size();i++)
	{
		// i next hit,
		while(k>-1 && pat[k+1]!=pat[i] )
		k = pre[k];
		// not hit ,check until
		if(pat[k+1] == pat[i] )
			k = k+1 ;
		pre[i] = k;
	}
	return pre;
}
int main(){
	// rean string
	vc pattern = { 'a','b','a','b','a','a'};
	// get prefix_function
	vc pre = prefix_fun(pattern);
	// using prefixfunction to find matched string
	

}
