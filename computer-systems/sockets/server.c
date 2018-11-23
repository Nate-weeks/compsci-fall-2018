// Sever Side program in C to demonstrate socket programming
// Nate Weeks November 2019
// Code modeled on https://www.geeksforgeeks.org/socket-programming-cc/
// and https://www.csd.uoc.gr/~hy556/material/tutorials/cs556-3rd-tutorial.pdf

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 12345

int main(){
  int serverSock;
  struct sockaddr_in addrport;
  int addrlen = sizeof(addrport);
  char buffer[1024] = {0};
  int new_socket;
  char socket_message;

  serverSock = socket(AF_INET, SOCK_STREAM, 0);

  addrport.sin_family = AF_INET;
  addrport.sin_addr.s_addr = INADDR_ANY;
  addrport.sin_port = htons( PORT );

  if(bind(serverSock, (struct sockaddr *) &addrport, sizeof(addrport)) < 0){
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

    printf("Server: listening on port %d\n", PORT);

  if(listen(serverSock, 1) < 0){
    perror("listen failed");
    exit(EXIT_FAILURE);
  }

  if((new_socket = accept(serverSock, (struct sockaddr *) &addrport, &addrlen)) < 0){
    perror("failed to accept socket");
    exit(EXIT_FAILURE);
  }

  socket_message = read(new_socket , buffer, 1024);
  printf("Server: Received message from client:\n");
  printf("Server: %s\n",buffer );
  printf("Server: sending message from server\n");
  send(new_socket , "hello from server" , strlen("hello from server") , 0 );
  printf("Server: closing server \n");
  close(serverSock);
  return 0;
}
