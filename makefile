all: client server

CFLAG=-g -Wall

client: client.c
	gcc -g client.c -o client
server: server.c
	gcc -g server.c -o server
server.c:
	cd sdir 

