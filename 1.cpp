#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
	
typedef vector< vector<int>> vv;
typedef vector< int> v;

void Print_Parents(vv& c, int i, int j){
	if( i==j) cout<<'A' ;

	else{
		cout <<'(' ;
		Print_Parents(c , i, c[i][j]);
		Print_Parents(c ,c[i][j]+1 , j);
		cout <<')' ;
	}
}



// s[i,j] = { min{ s[i,i+k] + s[k+1, j] + v[i-1]*v[k]*v[j]  , if i<j
//																													// i <= k < j
//					{ 0																							, if i==j

void Matrix_Chain( v& p , vv& s , vv& c){		// s,c : empty ; s:matrix ; c:multi order
	int n = p.size();
	
	for( int i=0; i<=n; i++ ) //creat s[n][n] 	
	{	s.push_back({}); s[i].resize(n+1);
		c.push_back({}); c[i].resize(n+1); }
	
	for( int i=1 ;i <=n ;i++)	s[i][i] = 0;	

	for( int m=2; m<=n; m++)
	{
		for( int i=1; i<= n-m+1; i++)
		{
			int j= i+m-1;
			s[i][j] = s[i][i] + s[i+1][j] + p[i-1]*p[i]*p[j] ;
			c[i][j] = i;

			for(int k=i; k<= j-1; k++)
			{
				int r = s[i][k] + s[k+1][j] + p[i-1]*p[k]*p[j];
				if( r < s[i][j]){  
					s[i][j] = r;
					c[i][j] = k;
				} 
			}
		}

	}

	
}

void print_s( vv& s)
{
	cout << "s[i][j]:" << endl;	
	for( auto& v : s){
		for( auto& el: v)
			cout << setw(5) <<  el <<' ';
		cout << endl;
	}
}
int main(){
	v p = {10,4,5,20,2,50}; // Matrix size p0 ~pn
	vv s ,c ;  // record multiplication ; record order ;
		

	Matrix_Chain( p ,s ,c );
	print_s(s);
	Print_Parents(c,1,p.size()-1) ;	
	cout << endl;
}
