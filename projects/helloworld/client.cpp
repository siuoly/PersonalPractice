#include<iostream>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<stdio.h>
#include<cstring>
#include<arpa/inet.h>
#include "mySockfunc.cpp"

using namespace std;





#define BLEN 120 // buffer length to use
int main(int argc, char const *argv[])
{
    int sockfd , confd ;    char ip[16]; int port;
    struct sockaddr_in servaddr , cli;

    // 預設ip port
    if(argc!=3){
        strcpy(ip,"120.0.0.1"); port = 1234;
    }
    else {strcpy(ip,argv[1]); port = atoi(argv[2]); }

    //創立
    sockfd = create();

    //連線
    connectServ(sockfd ,ip , port);
    // cout << "connect success";


    return 0;
}


/* 
#include<netdb.h>
    struct hostent *hptr;
    const char *examplename = "code.visualstudio.com";    // dot or colon or name
    if( hptr = gethostbyname(examplename) ){
        // ip adder is now useful
        cout << hptr-> h_name;
    }
    else {
        cout << "get failed";
    }
 */

/* 
    // https://linux.die.net/man/3/getservbyname
    // 取得server結構
    struct servent *sptr;
    if(sptr = getservbyname("http","tcp"))      
        cout <<"syccess port:" << sptr->s_port ;
    else
        cout << "failure" ;
    // stmp http ftp可用
 */

/* 
    struct protoent *pptr;
    if(pptr = getprotobyname("Tcp"))    // tcp<--大小寫皆可
        cout << "name:" << pptr->p_name <<"\t port:"<< pptr->p_proto;
    else
        cout << "getprotobyname false";
 */