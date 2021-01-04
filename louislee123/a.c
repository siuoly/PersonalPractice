#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int run1(int argc, char*argv[])
{
	char *buf = (char*)malloc(5*sizeof(char));	
	FILE* fp = fopen("a.txt", "a+");

	if( setvbuf(fp,buf,_IOFBF,5) != 0)
		printf( "error");

	fputs("123456789",fp);

	fclose(fp);

	/* after set buf , the order of output is diff */
	if( setvbuf(stdout,buf,_IOFBF,5) != 0)
		printf( "error");
	printf("prinf()");
	int n = write(1,"write()",7);
	printf("%d",n);


}

}

int main(){
	


}
