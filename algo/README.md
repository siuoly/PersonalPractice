# quick reference

## [Sort](#sorts)

<a name="sorts"/>

### `insertion sort`
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
