#include<stdio.h>
#include<stdlib.h>

/* BUFSIZ = 8192 */
void Setbuf(FILE *restrict fp,char *restrict buf);

int main(int argc, char** argv){
	FILE* fp = fopen("a.txt", "w+");
	char *buf = (char*)malloc(BUFSIZ*sizeof(char));
	setbuf(fp,buf);
	fflush(fp);
	fclose(fp);

	// stdout rebuf
	char* b = (char*)malloc(BUFSIZ*sizeof(char));	
	Setbuf(stdout,b);
	printf("fgkhfkglj hsghskd\n");
	puts(b);
	fclose(stdout);

	printf("123123");

}

void Setbuf(FILE *restrict fp,char *restrict buf){
	if( buf == NULL ){
		buf = (char*)malloc(BUFSIZ*sizeof(char));
		setvbuf(fp,buf,_IONBF,BUFSIZ);	
	}
	else
		setvbuf(fp,buf,_IOFBF,BUFSIZ);	
}
