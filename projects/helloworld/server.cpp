#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include "errexit.c"  
#include<stdio.h>
#include<cstring>
#include<ctime>
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <fcntl.h>	//open file
#include <sys/stat.h>
#include <arpa/inet.h>
#include "mySockfunc.cpp"
using namespace std;
// 給主機,服務,port類型, 回傳socket
// host(local host)  servicr("tcp","udp"..) transport("tcp","udp"..)
int connectSock(const char *host , const char *service ,const char *transport)
{
    struct hostent *phe;    //pointer to hostent
    struct servent *pse;    // ..servent
    struct protoent *ppe;   // for prototent
    
    struct sockaddr_in sin; // address
    int s,type;             //sock descripter , socket type


}
unsigned sink;

int main(int argc, char const *argv[])
{
    int port;
    //預設port
    if(argc!=2)     port = 1234;
    else port = atoi(argv[1]);

    cout << "start connect";
    int client = ServerAndAccept(port , 5);
    cout << "connect success";


    // clock_t now = clock();
/*     clock_t start = clock();

    int a = socket(PF_INET , SOCK_STREAM , 0);
    clock_t end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC*1000;
 
    printf("for loop took %f mili seconds to execute \n", cpu_time_used);
 */
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
    // 取得server結構 , 在一個固定文件中查詢
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
