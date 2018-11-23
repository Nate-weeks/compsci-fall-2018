// Client side C program to demonstrate Socket programming
// Nate Weeks November 2019
// Code modeled on https://www.geeksforgeeks.org/socket-programming-cc/
// and https://www.csd.uoc.gr/~hy556/material/tutorials/cs556-3rd-tutorial.pdf

#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 12345

int main(){
  int clientSock;
  struct sockaddr_in serveraddr;
  int addrlen = sizeof(serveraddr);
  char buffer[1024] = {0};
  char server_message;

  serveraddr.sin_family = AF_INET;
  serveraddr.sin_port = htons( PORT );

  if((inet_pton(AF_INET, "127.0.0.1", &serveraddr.sin_addr))<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

  if ((clientSock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
      printf("\n Socket creation error \n");
      return -1;
  }

  if (connect(clientSock, (struct sockaddr *) &serveraddr,
  sizeof(serveraddr)) < 0){
  printf("\n Socket connect error \n");
  return -1;
}
  printf("Client: sending message to port: %d\n", PORT);
  send(clientSock , "hello from client" , strlen("hello from client") , 0 );
  printf("Client: receiving message from server\n");
  server_message = read( clientSock , buffer, 1024);
  printf("Client: received message: %s\n",buffer );
  printf("Client: closing clientSocket\n");
  close(clientSock);
  return 0;
}
