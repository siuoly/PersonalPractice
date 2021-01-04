#include<iostream>
#include<unistd.h>
#include<string.h> // strerror
#include<fcntl.h>	//open
#include "openfunc.c"
using namespace std;

int main(int argc, char** argv)
{

	int fd=0; char str[100];

	// open
	if( (fd=open("txt", O_RDONLY|O_TRUNC)) <0 ) err(); 

	// write
	int n=0;
	sprintf(str,"Hello world");
	cout << strlen(str)<<endl;
	//Write(fd ,str ,strlen(str)+1);

	// clear
	bzero(str,100);
	lseek(fd ,0,0);
	// read
	while( read(fd,str,100) !=0)	
		cout << str;
}



/*
	3) creat function
*/

/* <string.h> strerror(); */
