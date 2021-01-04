#include<iostream>
#include<unistd.h>
#include<string.h> // strerror
#include<fcntl.h>	//open
#include "openfunc.cc"
using namespace std;

/* 測試read只讀指定長度, 字串尾不設零, */
/* 直接輸出字串, 會輸出不確定長度, 直至記憶體遇到0為止 */

int main(int argc, char** argv)
{

	int fd=0; char str[100];

	// open
	if( (fd=open("txt", O_RDWR|O_CREAT, 755)) <0 ) err(); 
	// write
	int n=0;
	sprintf(str,"12345");
	Write(fd ,str ,strlen(str));
	Write(fd ,"12345", 5);
	Write(fd ,"12345", 5);

	lseek(fd,0,0);	
	char c[10]={0};
	read(fd,c,20);
	cout << "c內容:"<< c;
	cout << "\n\n";

	cout << "c安全空間內容:";
	for(int i=0; i<10 ;i++) cout << c[i];

	cout << "\n\n";

	cout << "c讀取長度內容:";
	for(int i=0; i<20 ;i++) cout << c[i];

}


