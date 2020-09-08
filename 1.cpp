#include<iostream>
using namespace std;
// define TINS // test insortion

int main(){
	int a[100];int n=0;

	// input data
	while(cin >> a[n]) n++;

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

		#ifdef TINS
		for(int i=0;i<n;i++) cout <<a[i]<<' ';
		cout << endl;
		#endif
	}

	// output result
	for(int i=0;i<n;i++) cout << a[i] <<' ';
	cout << endl;
}

