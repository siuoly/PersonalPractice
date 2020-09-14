#include<iostream>
#include<vector>
#include<cassert>
#define TEST
using namespace std;

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

int main()
{
	v ary; int t , kase=1 ;
  freopen("in" ,"r" , stdin) ;

  while( cin >> t)
  {
    cout << "case" << kase++ << ": " << endl;
    ary.push_back( t);

	  while( cin >> t ){
		  ary.push_back( t );	
      if(getchar()=='\n') break; 
    }
    quicksort( ary , 0 ,ary.size() -1 );
    ary.resize(0);
    cout << "\n\n";
  }



}
