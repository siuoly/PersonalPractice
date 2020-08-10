#include <stdio.h> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <fcntl.h>	//open file
#include <sys/stat.h>
#include <arpa/inet.h>

#define BUFF 1024
#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr 
#define MAX_TREE_HT 200 
#define BUFFSIZE 200

// A Huffman tree node 
struct MinHeapNode { 
  
    // One of the input characters 
    unsigned char data; 
  
    // Frequency of the character 
    unsigned char freq; 
  
    // Left and right child of this node 
    struct MinHeapNode *left, *right; 
}; 
  
// A utility function allocate a new 
// min heap node with given character 
// and frequency of the character 
struct MinHeapNode* newNode(unsigned char data, unsigned freq) 
{ 
    struct MinHeapNode* temp 
        = (struct MinHeapNode*)malloc
(sizeof(struct MinHeapNode)); 
  
    temp->left = temp->right = NULL; 
    temp->data = data; 
    temp->freq = freq; 
  
    return temp; 
} 
  

//for each str create a path on tree
void CreateTreePath( char* str , int data , struct MinHeapNode* root )
{
    for (int i = 0; str[i]!= 0 ; i++)
    {
        // 決定方向 //child是否存在
        //left go
        if(str[i]=='0')
        {
            if(!root->left)
                root->left = newNode(0,0);
            root = root->left;
        }
        else{   //right go
            if(!root->right)
                root->right = newNode(0,0);
            root = root->right;            
        }  
    }
    //assign number 
    root->data = data; root->freq = 1;
}

//make tree , decode encodeing file
struct MinHeapNode* Huffmantree( char* filename ){

    //open and read table
        FILE* ft = fopen( filename ,"r" );
        char *table[256];  
        for(int i =0;i<256;i++)
            table[i] = (char*)malloc( BUFFSIZE* sizeof(char));

        int idx =0;
        
        for(int i = 0 ; i<256 ; i++)
        {
            fscanf(ft , "%d: ",&idx);
            fscanf(ft , "%s\n", table[idx] );
        }
        fclose(ft);
    //table[256]

    //Create a tree
        char str[BUFFSIZE];
        struct MinHeapNode* root = newNode(0,0);
        for(int i=0; i<256 ; i++)
        {
            strcpy(str , table[i]);
            CreateTreePath( str, i , root );
        }
    //
    return root;
}

//give byte search path and print
struct MinHeapNode* HuffTreeTraversal(int path ,
                    struct MinHeapNode* cur ,
                    struct MinHeapNode* root, FILE* fd)
{
    for (unsigned char i = 0x80; i >0 ; i=i>>1 )
    {   // i=1000 0000 --> i=0100 0000 --> i = 0010 0000
    // path =0101 1101 , (i&path) can get the posi is 1 or 0.
        
        if ( (path&i) > 0 )
            cur = cur->right;
        else 
            cur = cur->left; 
        
        if (cur->freq == 1)
        {
            fputc(cur->data , fd);
            cur = root;
        }      
    }
    return cur;
}

//use the table decode the file
void HuffmanDecode(struct MinHeapNode* root,
                 char* defilename ,char* enfilename)
{
    
    //Decode file
    FILE* fd = fopen(defilename , "wb");
    FILE* fe = fopen(enfilename , "rb");
    struct MinHeapNode* cur = root; //record now posi
    int ch = 0;

    while( (ch = fgetc(fe)) != EOF )
    {
        //ch is the path of root
        //byte by byte search
        cur = HuffTreeTraversal(ch , cur , root, fd);
        ch = 0 ;
    }
    
	fclose(fe);
    fclose(fd);
    //
}

// Function designed for chat between client and server. 
void Transfer(int sockfd ) 
{ 
	char buff[BUFF] = {0}; 

	//trans file1
	read(sockfd , buff ,sizeof(buff));	//get filename
	char tablename[50]; strcpy(tablename , buff);
	if( strcmp(buff ,"exit") == 0)
	{
		printf("client end the connection\n");
		exit(0);
	}

	printf("%s accept...\n" , buff);
	int fd = open( buff, O_WRONLY | O_CREAT | O_TRUNC , S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH );
	if ( fd == -1)
        perror("File cannot be opened");
	bzero(buff ,BUFF);
    ssize_t num =BUFF ;
	int sum =0;
	while (num == BUFF)
	{
		num = read(sockfd ,buff , sizeof(buff)/sizeof(char));
		write(fd , buff, num) ;
		bzero(buff ,BUFF);
		sum+=num;
	}
	printf("Transfer success! %d byte\n" ,sum );
	close(fd);

	sleep(1);

	//trans file2
	read(sockfd , buff ,sizeof(buff));	//get filename
	char encodename[50]; strcpy(encodename , buff);

	printf("%s accept\n" , buff);
	fd = open( buff, O_WRONLY | O_CREAT | O_TRUNC , S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH );
	bzero(buff ,BUFF);
	if ( fd == -1)
        perror("File cannot be opened");
	bzero(buff ,BUFF);
	num =BUFF ;sum=0;
	while (num == BUFF)
	{
		num = read(sockfd ,buff , sizeof(buff)/sizeof(char));
		write(fd , buff, num) ;
		bzero(buff ,BUFF);
		sum+=num;
	}
	printf("Transfer success! %d byte\n" ,sum );
	close(fd);

	//create tree from table
    struct MinHeapNode* root = Huffmantree(tablename);
	//use the table decode the file
	char decodename[50]={0}; strncpy(decodename, tablename , strlen(tablename)-6 );
    HuffmanDecode(root , decodename ,encodename);
	struct stat st;
	stat(decodename, &st);
	int size = st.st_size;
	printf("Decode %s success , %d byte\n" ,decodename , size);
	printf("Waiting for another file...\n");
} 


// Driver function 
int main() 
{ 

	char* fname = "Wind Of Change.mp3";
	char tablename[50]={0};
	char encodename[50]={0};
	char decodename[50]={0};
	strcat( tablename , fname );strcat( tablename ,".table");
	strcat( encodename , fname );strcat( encodename ,".encode");
	strcat( decodename , fname );strcat( decodename ,".decode");

	int sockfd, connfd;
	int  len; 
	struct sockaddr_in servaddr, cli; 


// socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		printf("socket creation failed...\n"); 
		exit(0); 
	} 
	else
	{	
		// printf("Socket successfully created..\n"); 
	}
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
	servaddr.sin_port = htons(PORT); 

	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
		printf("socket bind failed...\n"); 
		exit(0); 
	} 
	else
	{	//printf("Socket successfully binded..\n"); 
	}

	// Now server is ready to listen and verification 
	
	if ((listen(sockfd, 5)) != 0) { 
		printf("Listen failed...\n"); 
		exit(0); 
	} 
	else{
		// printf("Server listening..\n"); 
	}
	len = sizeof(cli); 
	printf("Waiting for connection ..... the server's port is 8080 ......\n");

	// Accept the data packet from client and verification 
	connfd = accept(sockfd, (SA*)&cli, &len); 
	if (connfd < 0) { 
		printf("server acccept failed...\n"); 
		exit(0); 
	} 
	else{
		printf("A client “%s” has connected via port num %d using SOCK_STREAM (TCP)\n" , inet_ntoa(cli.sin_addr ) ,ntohs(cli.sin_port) ); 
	}
//
	while (1)
	{
		Transfer(connfd ); 
	}
	

	close(connfd);

//

    return 0; 
} 
