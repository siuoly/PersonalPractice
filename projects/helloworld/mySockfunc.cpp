#ifndef MY_SOCKET_FUNC
#define MY_SOCKET_FUNC

#include <stdio.h> 
#include <stdlib.h>
#include <netdb.h> 
#include <cstring>
#include <netinet/in.h> 
void error(const char* msg){
    perror(msg);
    exit(0);
}

//=====Server use=======================================
/* usage:

    //設定port
    if(argc!=2)     port = 1234;
    else port = atoi(argv[1]);

    int client = ServerAndAccept(port , backlog);
 */
int create(){
    int sockfd = socket(AF_INET ,SOCK_STREAM,0);
    if(sockfd == -1){
        error("create");
        exit(0);
    }
    else 
        return sockfd;
}


void bindServ(int sockfd  ,int port){
    struct sockaddr_in servaddr;

	memset(&servaddr,0 , sizeof(servaddr)); 

	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
	servaddr.sin_port = htons(port); 

	// Binding newly created socket to given IP and verification 
	if (bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) { 
        error("bind");
        exit(0);
	} 
}

void listenServ(int servSock , int backlog ){

	if ((listen(servSock, backlog)) != 0) {
        error("listen");
        exit(0);
    }
		printf("Server listening..\n"); 

}

int acceptServ(int servSock){
    int cliSock;
    // socklen_t : uint
    struct sockaddr_in cliAddr;
    socklen_t cli_len = sizeof(cliAddr) ;     //如果 client 地址長度改變，則顯現
                         // 為什麼要sockaddr_in ---> sockaddr 
    cliSock = accept(servSock , (struct sockaddr*)&cliAddr ,&cli_len);
    if(cliSock < 0){
        error("accept");
        exit(0);
    }
    else return cliSock;
    // 注: 無法得知是哪個階段的client接收失敗
    // 也無法得知cli_len的長度改變細節
}

int ServerAndAccept( int port ,int backlog){
    // create
    int servSock = create();
    // bind
    bindServ(servSock , port);
    //listen
    listenServ(servSock , backlog);
    //accept
    int cliSock = acceptServ(servSock);
    return cliSock;
}

//=====Client use=======================================
/* usage:

//設定ip port
strcpy(ip,"120.0.0.1"); port = 1234;
strcpy(ip,argv[1]); port = atoi(argv[2]);

//連線
int sockfd = create();
connectServ(sockfd ,ip , port);
 */


// int create() /   /server已有

int connectServ(int sock ,const char* ip ,int port){
    struct sockaddr_in servaddr;

    memset(&servaddr , 0 ,sizeof(servaddr));        // <string.h>
    servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	servaddr.sin_port = htons(port);                // <arpa/inet.h>

    if(connect(sock , (struct sockaddr*)&servaddr , sizeof(servaddr))!=0)   //卡住 直至成功
        error("connect");

}


#endif