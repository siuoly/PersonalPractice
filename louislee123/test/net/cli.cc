#include<iostream>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<cstring> //memset()

#define err(msg) \
	do{ perror(msg); exit(EXIT_FAILURE);} while(0)


using namespace std;
int main( int argv, char** argc)
{
	int fd;
	char buff[100];
	struct sockaddr_in addr;

	fd = socket(AF_INET, SOCK_STREAM, 0);
	if(fd < 0 ) err("socket");

	memset(&addr ,0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8000);
	
	if( inet_pton( AF_INET, "127.0.0.1" ,&addr.sin_addr) <=0) err("pton");

	if( connect( fd, (struct sockaddr*)&addr, sizeof(addr)) <0) err("connect");

	write(fd , "Hello socket", 100);
	close(fd);
}
