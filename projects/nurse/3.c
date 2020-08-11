#include<stdio.h>

int main()
{
	int a37=1 ,b11=1;
	int i=3;
	while( i>0 )
	if( a37*37 > b11*11+3 ){
		b11++;
	}
	else if(b11*11+3 > a37*37)
	{
		a37++; 
	}
	else{
		printf("%d \n", a37*37);
		a37++;
		i--;
	}

	i=2; a37 = 1;
	int c55 = 1;
	while(i)
	{
		if( c55*55 + 52 > a37*37)
			a37++;
		else if( c55*55 + 52 < a37*37)
			c55++;
		else
		{
			printf("%d \n", a37*37);
			a37++; i--;
		}
	}

}
