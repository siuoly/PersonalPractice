#include<iostream>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h> //inet_pton()
#include<cstring> //memset()

#define err(msg) \
	do{ perror(msg); exit(EXIT_FAILURE);} while(0)

using namespace std;

int main( int argv, char** argc)
{
	int listfd;
	char buff[100];
	struct sockaddr_in addr;

	listfd = socket(AF_INET, SOCK_STREAM, 0);
	if( listfd == -1) err("socket");


	memset(&addr, 0, sizeof(addr));
	addr.sin_port = htons(8000);
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl( INADDR_ANY);	

	if( bind( listfd, (struct sockaddr*)&addr , sizeof(addr)) <0 ) err("bind");

	if( listen( listfd ,10) <0) err("listen");

	int confd	= accept( listfd, 0 ,0);
	while( read(confd, buff, strlen(buff)) >0)
			printf("%s" , buff);

	close(confd);

}
