#include<stdio.h>
#include<stdlib.h>

void printfp(){
	// 都是由小到大增長
	long p[30];
	for(int i=0;i<30;i++)
		printf("%2d: %p\n",i,&p[i]);

	int a,b;
	int c;
	printf("a: %p\n",&a);
	printf("b: %p\n",&b);
	printf("c: %p\n",&c);

	typedef char type;
	type *point = (type*)malloc(30*sizeof(type));
	for(int i=0;i<30;i++,point++)
		printf("%2d: %p\n",i,point);
}

void printx(){
	long x=30;
	for(int i=0;i<10;i++,x++)
		printf("%#lx\n", x);	
}

void print99(){
	int size = 20;
	for(int i=1;i<size;i++){
		for(int j=1;j<size;j++)
			printf("% 2d x% 3d=%4x\t",i,j,i*j);
		putchar('\n');
	}
}

// printf( " %'d ") 無效??
void printBig(){
	for(int i=1234;i<2000;i+=79)
		for(int j=1234;j<2000;j+=79)
			printf("%5d * %5d = %'6i\n",i,j,i*j);
}

void printe(){
	double d = 0.5;
	for(int i=0; i<10;i++,d/=2)
		printf("%f ",d);
}

int main(int argc, char*argv[])
{
	//printfp();	
	//printx();
	//print99();
	//printBig();
	printe();
}
