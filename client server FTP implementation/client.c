#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define MAX_TREE_HT 200 
#define BUFFSIZE 200

#define BUFF 1024
#define MAX 1024 
#define PORT 8080 
#define SA struct sockaddr 

// A Huffman tree node 
struct MinHeapNode { 
  
    // One of the input characters 
    unsigned char data; 
  
    // Frequency of the character 
    unsigned freq; 
  
    // Left and right child of this node 
    struct MinHeapNode *left, *right; 
}; 
  
// A Min Heap:  Collection of 
// min-heap (or Huffman tree) nodes 
struct MinHeap { 
  
    // Current size of min heap 
    unsigned size; 
  
    // capacity of min heap 
    unsigned capacity; 
  
    // Array of minheap node pointers 
    struct MinHeapNode** array; 
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
  
// A utility function to create 
// a min heap of given capacity 
struct MinHeap* createMinHeap(unsigned capacity) 
  
{ 
  
    struct MinHeap* minHeap 
        = (struct MinHeap*)malloc(sizeof(struct MinHeap)); 
  
    // current size is 0 
    minHeap->size = 0; 
  
    minHeap->capacity = capacity; 
  
    minHeap->array 
        = (struct MinHeapNode**)malloc(minHeap-> 
capacity * sizeof(struct MinHeapNode*)); 
    return minHeap; 
} 
  
// A utility function to 
// swap two min heap nodes 
void swapMinHeapNode(struct MinHeapNode** a, 
                     struct MinHeapNode** b) 
  
{ 
  
    struct MinHeapNode* t = *a; 
    *a = *b; 
    *b = t; 
} 
  
// The standard minHeapify function. 
void minHeapify(struct MinHeap* minHeap, int idx) 
  
{ 
  
    int smallest = idx; 
    int left = 2 * idx + 1; 
    int right = 2 * idx + 2; 
  
    if (left < minHeap->size && minHeap->array[left]-> 
freq < minHeap->array[smallest]->freq) 
        smallest = left; 
  
    if (right < minHeap->size && minHeap->array[right]-> 
freq < minHeap->array[smallest]->freq) 
        smallest = right; 
  
    if (smallest != idx) { 
        swapMinHeapNode(&minHeap->array[smallest], 
                        &minHeap->array[idx]); 
        minHeapify(minHeap, smallest); 
    } 
} 
  
// A utility function to check 
// if size of heap is 1 or not 
int isSizeOne(struct MinHeap* minHeap) 
{ 
  
    return (minHeap->size == 1); 
} 
  
// A standard function to extract 
// minimum value node from heap 
struct MinHeapNode* extractMin(struct MinHeap* minHeap) 
  
{ 
  
    struct MinHeapNode* temp = minHeap->array[0]; 
    minHeap->array[0] 
        = minHeap->array[minHeap->size - 1]; 
  
    --minHeap->size; 
    // printf("")
    minHeapify(minHeap, 0); 
  
    return temp; 
} 
  
// A utility function to insert 
// a new node to Min Heap 
void insertMinHeap(struct MinHeap* minHeap, 
                   struct MinHeapNode* minHeapNode) 
  
{ 
  
    ++minHeap->size; 
    int i = minHeap->size - 1; 

    //子 小於 父 freq
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) { 
  
        //子被父取代
        minHeap->array[i] = minHeap->array[(i - 1) / 2]; 
        i = (i - 1) / 2; 
    } 

    minHeap->array[i] = minHeapNode; 
} 
  
// A standard function to build min heap 
void buildMinHeap(struct MinHeap* minHeap) 
  
{ 
    int n = minHeap->size - 1;              //??  為什麼要-1
    int i; 
  
    for (i = (n - 1) / 2; i >= 0; --i) 
        minHeapify(minHeap, i); 
} 
  
// A utility function to print an array of size n 
void printArr(int arr[], int n, FILE* fd) 
{ 
    int i; 
    for (i = 0; i < n; ++i){
        // printf("%d", arr[i]); 
        fprintf(fd , "%d", arr[i]);
    } 
    fprintf(fd,"\n");
    // printf("\n"); 
} 
  
// Utility function to check if this node is leaf 
int isLeaf(struct MinHeapNode* root) 
  
{ 
  
    return !(root->left) && !(root->right); 
} 
  
// Creates a min heap of capacity 
// equal to size and inserts all character of 
// data[] in min heap. Initially size of 
// min heap is equal to capacity 
struct MinHeap* createAndBuildMinHeap(unsigned char data[], int freq[], int size) 
  
{ 
    struct MinHeap* minHeap = createMinHeap(size); 
  
    for (int i = 0; i < size; ++i) 
        minHeap->array[i] = newNode(data[i], freq[i]); 



    minHeap->size = size; 

    buildMinHeap(minHeap); 

    return minHeap; 
} 
  
// The main function that builds Huffman tree 
struct MinHeapNode* buildHuffmanTree(unsigned char data[], int freq[], int size) 
  
{ 
    struct MinHeapNode *left, *right, *top; 
  
    // Step 1: Create a min heap of capacity 
    // equal to size.  Initially, there are 
    // modes equal to size. 
    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size); 
  
    // Iterate while size of heap doesn't become 1 
    while (!isSizeOne(minHeap)) { 
  
        // Step 2: Extract the two minimum 
        // freq items from min heap 
        left = extractMin(minHeap); 
        right = extractMin(minHeap); 

        // Step 3:  Create a new internal 
        // node with frequency equal to the 
        // sum of the two nodes frequencies. 
        // Make the two extracted node as 
        // left and right children of this new node. 
        // Add this node to the min heap 
        // '$' is a special value for internal nodes, not used 
        top = newNode('$', left->freq + right->freq); 

        top->left = left; 
        top->right = right; 
  
        insertMinHeap(minHeap, top); 
    } 
  
    // Step 4: The remaining node is the 
    // root node and the tree is complete. 
    return extractMin(minHeap); 
} 
  
// Prints huffman codes from the root of Huffman Tree. 
// It uses arr[] to store codes 
void printCodes(struct MinHeapNode* root, int arr[], int top , FILE* fd) 
  
{ 
  
    // Assign 0 to left edge and recur 
    if (root->left) { 
  
        arr[top] = 0; 
        printCodes(root->left, arr, top + 1 ,fd); 
    } 
  
    // Assign 1 to right edge and recur 
    if (root->right) { 
  
        arr[top] = 1; 
        printCodes(root->right, arr, top + 1 ,fd); 
    } 
  
    // If this is a leaf node, then 
    // it contains one of the input 
    // characters, print the character 
    // and its code from arr[] 
    if (isLeaf(root)) { 
        fprintf(fd ,"%d: " , root->data);
        // printf("%d: ", root->data); 
        printArr(arr, top, fd); 
    } 
} 
  
// The main function that builds a 
// Huffman Tree and print codes by traversing 
// the built Huffman Tree 
struct MinHeapNode* HuffmanCodes(unsigned char data[],
                             int freq[], int size ,FILE *fd) 
{ 
    // Construct Huffman Tree 
    struct MinHeapNode* root 
        = buildHuffmanTree(data, freq, size); 
  
    printf("buildHuffmanTree success\n");
    // Print Huffman codes using 
    // the Huffman tree built above 
    int arr[MAX_TREE_HT], top = 0; 
  
    printCodes(root, arr, top ,fd); 
    return root;
} 



void transfer(int sockfd , char* fname , char* fname2) 
{ 
	char buff[BUFF]={0};
	int fd = open( fname, O_CREAT|O_RDONLY );
	if ( fd == -1)
        perror("File cannot be opened");

    ssize_t num = BUFF ;
	printf("%s transfer \n" ,fname);
	write(sockfd , fname ,strlen(fname));
	sleep(1);
	int sum =0;
	while (num == BUFF)
	{
		num = read(fd ,buff , BUFF );
		write(sockfd , buff, num) ;
		bzero(buff ,BUFF); 
		sum+=num;
	}
	printf("Transfer %s success! %d byte\n" ,fname , sum);
	close(fd);

	sleep(1);

	fd = open( fname2, O_CREAT|O_RDONLY );
	if ( fd == -1)
        perror("File cannot be opened");
	
	printf("%s transfer \n" ,fname2);
	write(sockfd , fname2 ,strlen(fname2));
	sleep(1);
	num = BUFF ;
	sum = 0;
	while (num == BUFF)
	{
		num = read(fd ,buff , BUFF );
		write(sockfd , buff, num) ;
		bzero(buff ,BUFF);
		sum+=num;
	}
	printf("Transfer %s success! %d byte\n" ,fname2 , sum);
	close(fd);

} 

int creatConnectSock(char* IP , int port)
{
	int sockfd, connfd; 
	struct sockaddr_in servaddr, cli; 

	// socket create and varification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		printf("socket creation failed...\n"); 
		exit(0); 
	} 
	else{
		// printf("Socket successfully created..\n"); 
	}
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = inet_addr(IP); 
	servaddr.sin_port = htons(port); 

	// connect the client socket to server socket 
	if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
		printf("connection with the server failed...\n"); 
		exit(0); 
	} 
	else
		printf("The server with IP “%s” \
has accepted your connection\n" , IP ); 
	return sockfd;
}

int main() 
{ 
    //127.0.0.1
    char str[50] = {0};int sockfd=0;
	char fname[50] ={0} ;
        strcpy( fname , "Wind Of Change.mp3" ) ;
    int port = 8080;

    while(scanf("%s",str))
    {
        char IP[50]={0}; 

        if(strcmp(str,"connect") == 0)
        {
            scanf("%s" ,IP);
            // strcpy(IP ,"127.0.0.1");
            printf("Please enter the port:");
            scanf("%d" ,&port);
            sockfd = creatConnectSock(IP , port);
        }
        if(strcmp(str,"exit")== 0)
        {
            printf("See you next time\n");
        	write(sockfd , "exit" ,5);
            exit(1);
        }
    else if(strcmp(str,"upload")== 0)
    {
/*         if(sockfd == 0){
            printf("There is no connection\n");
            break;
        } */
        scanf("%s" ,fname);
	char tablename[50]={0};
	char encodename[50]={0};
	strcat( tablename , fname );strcat( tablename ,".table");
	strcat( encodename , fname );strcat( encodename ,".encode");

//Encode
    FILE* fd = fopen( fname ,"rb");
    FILE* ft = fopen( tablename ,"w" );
    unsigned char arr[256] ;     unsigned char buffer[1024]={0};
    int freq[256]={0};
    if(fd==0){
        perror("error");
        exit(1);
    }

//initial arr and freq
    for (int i = 0; i < 256; i++)
        arr[i] = (unsigned char)(i);

    while (!feof(fd))
    {
        int read_num = fread(buffer, sizeof ( char), 1024, fd); 
        
        for (int i = 0; i < read_num; i++)
            *(freq + (int)buffer[i]) += 1;        
    }
//

    printf("create Huffman tree...\n");
//create tree
    int size = sizeof(arr) / sizeof(arr[0]); 
  
    HuffmanCodes(arr, freq, size ,ft);
    fclose(fd);
    fclose(ft);
//
    printf("success\n");


    printf("create Huffman table ...\n");
//get table[256][buffsize] for .table file.  Need  table file
//cannot transfer as parameter 
    ft = fopen( tablename ,"r" );
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
//
    printf("success\n");


    printf("create Huffman encode ...\n");
//create encode file from table[][]
    fd = fopen( fname ,"rb");
    ft = fopen( encodename ,"wb");
    int ch =0 ;
    unsigned char bit =0 ;
    int count = 0 ;
    char str[BUFFSIZE];
    while( (ch=fgetc(fd)) != EOF )
    {
        // ch = fgetc(fd);
        strcpy(str , table[ch]);
        for(int i =0 ; str[i]!=0 ; i++)
        {
            bit = bit << 1;
            if(str[i]=='1')
                bit+=1;
            else bit+=0;
            count ++;
            if(count == 8){
                fputc(bit,ft);
                count = 0; bit^=bit;
            }
        }
    }
    if (count!=0)
    {
        //if any bit not be printed , add 0 , and print
        do{
            bit=bit<<1;
            count++;
        }while (count!=8);
        fputc(bit,ft);
        count = 0; bit^=bit;
    }
//
    printf("success\n");

    fclose(fd);
    fclose(ft);
//


	// function for chat 
	transfer(sockfd , tablename ,encodename); 
    
    }

    bzero(str , 50);
    }
} 
