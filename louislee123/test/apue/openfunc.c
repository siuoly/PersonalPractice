#include<iostream>
#include<unistd.h>
#include <fcntl.h>
#include<string.h> // strerror()
#define err() errp(__LINE__)

using namespace std;

// err() micro
void errp(int line)
{ 
	printf("line:%d: %s\n", line, strerror(errno));
}

// strerror()
void printErrorno(int n)
{
	for(int i =0 ;i<n;i++)
		cout << "erorr"<<i<< ": "<< strerror(i) << endl;
}

void openN(int n)
{
	int fd=0;
	char name[10];
	for(int i=0; i< n; i++){
		sprintf(name,"c%d", i);	
		if( (fd=open(name, O_WRONLY|O_CREAT, 755)) <0 )
			err(); 
	}
}

ssize_t Write(int fd, const void *buf, size_t count)
{ 
	ssize_t n=0; if((n = write(fd,buf,count)) != (int)count) err();
	return n;
}
