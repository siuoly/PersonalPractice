#include<stdio.h>

int main(int arc ,char**argv){
	char str[100];

	while(fgets(str, sizeof(str),stdin))
		fputs(str,stdout);
	

}
