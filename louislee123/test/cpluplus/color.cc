#include<stdio.h>

void colorRed(){
	printf("\033[31m");
}

void colorGreen(){
	printf("\033[32m");
}

void colorYellow(){
	printf("\033[33m");
}

void colorBlue(){
	printf("\033[34m");
}

void colorMagenta(){
	printf("\033[35m");
}

void colorCyan(){
	printf("\033[36m");
}

void colorreset(){
	printf("\033[0m");
}

bool isPrime(int n)
{
	for(int i=2;i<=n/2;i++)
		if(n%i == 0) return false;
	if( n < 2 ) return false;
	return true;
}


int main(int argc, char*argv[])
{
	int n;
	for(int i=100;i<200;i++){
		for(int j=1;j<11;j++){
			n = i*10+j;
			if(isPrime(n))colorYellow(); 
			printf("%6d", n);
			colorreset();	
		}
			printf("\n");
	}
}
