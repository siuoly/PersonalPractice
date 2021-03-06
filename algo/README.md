# quick reference

## [Sort](#sorts)
## [Algorithms](#algorithms)

<a name="sorts"/>

#### insertion sort
```c++
	int a[100];int n=0;

	// insertion sort
	for(int i=1;i<n;i++) // i: 2th ~ nth
	{
		int j=i-1, tmp=a[i];
		
		// left shift a[i] until a[i] is larger than all left;
		// equal to right shift elem which larger than a[i]
		while( j>-1&& tmp < a[j] )
		{ a[j+1]=a[j]; j--;	}
		
		// put a[i] to the correct posi
		a[j+1]=tmp; 
	}
```

#### quick sort
```c++
typedef vector<int> v;

// return quicksort
void quicksort( v &ary ,int left, int right)
{
	if(left >= right ) return;
	int i = left , j = right+1 ;


	do
	{
		do{ i=i+1;	}while( ary[i] < ary[left]	);
		do{ j=j-1;	}while( ary[j] > ary[left]	);
		if( i < j)
			swap( ary[i] , ary[j]) ;
	}while( i < j);

	if( i > j )	 swap( ary[left] , ary[j]);
  #ifdef TEST
	cout << "swap: " << left << " ~ " << right 
			 << "\tkey: " << ary[j] << endl ;
	for(auto a: ary)
		cout << a<<' '; cout << endl;
  #endif

	quicksort( ary , left , j-1 );
	quicksort( ary , j+1 , right );
}
```
### output
	case1:
	swap: 0 ~ 9     key: 23
	2 1 12 23 43 545 65 23 32 43
	swap: 0 ~ 2     key: 2
	1 2 12 23 43 545 65 23 32 43
	swap: 4 ~ 9     key: 43
	1 2 12 23 23 43 32 43 65 545
	swap: 4 ~ 6     key: 23
	1 2 12 23 23 43 32 43 65 545
	swap: 5 ~ 6     key: 43
	1 2 12 23 23 32 43 43 65 545
	swap: 8 ~ 9     key: 65
	1 2 12 23 23 32 43 43 65 545
[quicksort.cpp](./quicksort.cpp)


<a name="algorithms"/>

#### Matrix_Chain

 `s[i,j]` =  min{ s[i,i+k] + s[k+1, j] + v[i-1]*v[k]*v[j] &ensp;&ensp;&ensp;&ensp;&ensp; if i<j	&ensp;and   **i <= k < j**
 
`s[i,j]` = 0 &ensp;&ensp;&ensp;if i == j
      

```c++
typedef vector< vector<int>> vv;
typedef vector< int> v;
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
		}// for(int i=1 ...)
	}// for(int m=2...)
}// void Matrix
```

#### Print_Parents
```c++
void Print_Parents(vv& c, int i, int j){
	if( i==j) cout<<'A' ;

	else{
		cout <<'(' ;
		Print_Parents(c , i, c[i][j]);
		Print_Parents(c ,c[i][j]+1 , j);
		cout <<')' ;
	}
}
```
### output:
	s[i][j]:
    0     0     0     0     0     0     0
    0     0   200  1200   320  1320  4280
    0     0     0   400   240   640  3804
    0     0     0     0   200   700  3830
    0     0     0     0     0  2000  4620
    0     0     0     0     0     0  3300
    0     0     0     0     0     0     0
	((A(A(AA)))A)
[Matrix.cpp](./Matrix_chain.cpp)
