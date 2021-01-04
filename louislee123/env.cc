#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

void bye(){ printf("bye\n"); }


int main(){
	//pid_t pid = fork();
	//if( pid==0) printf("this is child\n");
	//else printf("this is parent\n");
	char **e = environ;
	for( int i=1 ; *e!= NULL; e++,i++ )
		printf("%d: %s\n\n",i , *e);
		
	return 0;
	exit(0);
}
