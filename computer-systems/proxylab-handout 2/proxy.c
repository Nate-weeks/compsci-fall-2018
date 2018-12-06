//proxy.c a proxy server by nate weeks for the computer systems lab
// December 2018
// main guidelines taken from the cmu lab at http://csapp.cs.cmu.edu/3e/proxylab.pdf
// https://stackoverflow.com/questions/15472299/split-string-into-tokens-and-save-them-in-an-array
// https://stackoverflow.com/questions/2218290/concatenate-char-array-in-c
// https://stackoverflow.com/questions/30470505/http-request-using-sockets-in-c

#include <stdio.h>

/* Recommended max cache and object sizes */
#define MAX_CACHE_SIZE 1049000
#define MAX_OBJECT_SIZE 102400



/* You won't lose style points for including this long line in your code */
static const char *user_agent_hdr = "User-Agent: Mozilla/5.0 (X11; Linux x86_64; rv:10.0.3) Gecko/20120305 Firefox/10.0.3\r\n";

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <netdb.h>
#include "csapp.h"
#define PORT 12345

void doit(int clientfd);
int http_exchange(int clientfd, char* host, char* port, char* path);
char* build_header(char* host, char* path);
void clienterror(int clientfd, char *cause, char *errnum,
		 char *shortmsg, char *longmsg);

char header_body[MAXLINE];

int main(int argc, char **argv)
{
    int listenfd, connfd;
    char hostname[MAXLINE], port[MAXLINE];
    socklen_t clientlen;
    struct sockaddr_storage clientaddr;

    /* Check command line args */
    if (argc != 2) {
	fprintf(stderr, "usage: %s <port>\n", argv[0]);
	exit(1);
    }

    listenfd = Open_listenfd(argv[1]);
    while (1) {
	clientlen = sizeof(clientaddr);
	connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);
        Getnameinfo((SA *) &clientaddr, clientlen, hostname, MAXLINE,
                    port, MAXLINE, 0);
        printf("Accepted connection from (%s, %s)\n", hostname, port);
	doit(connfd);
  printf("closing connection \n");
	Close(connfd);
    }
}

void doit(int clientfd)
{
    char buf[MAXLINE], method[MAXLINE], uri[MAXLINE], version[MAXLINE];
    rio_t rio;
    char* http;
    char* split_uri[20];
    int i=0;
    int j=0;
    char* host;
    char* port;
    char* split_host[20];
    char* path;

    /* Read request line and headers */
    Rio_readinitb(&rio, clientfd);
    if (!Rio_readlineb(&rio, buf, MAXLINE))
        return;
    printf("%s", buf);
    sscanf(buf, "%s %s %s", method, uri, version);
    printf("method: %s uri: %s version: %s \n", method, uri, version);
    /* parse uri into hostname, port, url request*/
    http = strstr(uri, "http");   //check if there is an http or https preface

    split_uri[i] = strtok(uri,"/");  // split the address on /

    while(split_uri[i]!=NULL)
    {
      split_uri[++i] = strtok(NULL,"/");
    }

    if(http){                   //if there's an http, set host to be second entry
      host = split_uri[1];
      i=2;
      // start after the host name to generate the pathname
      path = malloc(1000);      //lazy assignment - should loop through and calculate size of path
      if(split_uri[i] == NULL){  // assign default path /
        strcat(path, "/");
      }
      while(split_uri[i]!=NULL){
        strcat(path, "/");              // add / inbetween each element of the path
        strcat(path, split_uri[i]);     // concatenate the path
        i+=1;
      }
    }
    else{
      host = split_uri[0];
      i=1;
      path = malloc(1000);      //lazy assignment - should loop through and calculate size of path
      if(split_uri[i] == NULL){
        strcat(path, "/");
      }
      while(split_uri[i]!=NULL){
        strcat(path, "/");
        strcat(path, split_uri[i]);
        i += 1;
      }
    }

    // path[strlen(path)-1] = 0;

    port = strstr(host, ":");        //if there's a port listing, split out the port
    if(port){
      split_host[j] = strtok(host, ":");
      while(split_host[j]!=NULL)
      {
         split_host[++j] = strtok(NULL,":");
      }
      port = split_host[1];
      host = split_host[0];
    } else {                          // else assign a default port 80
      port = "80";
    }

    printf("host: %s, port: %s, path: %s\n", host, port, path);

    if (strcasecmp(method, "GET")) {
        clienterror(clientfd, method, "501", "Not Implemented",
                    "proxy does not implement this method");
        return;
    }

    if((http_exchange(clientfd, host, port, path)) < 0){
      printf("error creating http connection\n");
    }
    return;
}

// takes the host, port, path and clientfd and initiates an http conversation
int http_exchange(int clientfd, char* host, char* port, char* path){
  int serverfd;
  int byte_count;
  char buf[MAXBUF];
  //open a socket connection to a server on the internet
  serverfd = open_clientfd(host, port);
  if(serverfd == -2){
    clienterror(clientfd, host, "400", "bad hostname or port", "unable to establish connectioin with host");
    return -1;
  }
  if(serverfd == -1){
    clienterror(clientfd, host, "400", "bad hostname or port", "unable to establish connectioin with host");
    return -1;
  }

  // build a properly formatted http request given the host and path
  char *request = build_header(host, path);
  rio_writen(serverfd,request,strlen(request));   // send it
  byte_count = recv(serverfd,buf,sizeof(buf),0);  // get a response
  printf("received %d bytes of data:\n",byte_count);
  printf("%.*s",byte_count,buf);
  if((rio_writen(clientfd, buf, byte_count)) < 0){    // forward response to client
    clienterror(clientfd, host, "400", "bad data", "error receiving data from server");
    return -1;
  }

  // get and send response a second time to get the object after the headers
  byte_count = recv(serverfd,buf,sizeof(buf),0);
  printf("received %d bytes of data:\n",byte_count);
  printf("%.*s",byte_count,buf);
  if((rio_writen(clientfd, buf, byte_count)) < 0){
    clienterror(clientfd, host, "400", "bad data", "error receiving data from server");
    return -1;
  }
  return 0;
}

char* build_header(char* host, char* path){

  /* build the http request */
  sprintf(header_body, "GET %s HTTP/1.0\r\n", path);
  sprintf(header_body, "%sHost: %s\r\n", header_body, host);
  sprintf(header_body, "%s%s", header_body, user_agent_hdr);
  sprintf(header_body, "%sConnection: close\r\n", header_body);
  sprintf(header_body, "%sProxy-Connection: close\r\n\r\n", header_body);
  return header_body;
}

void clienterror(int clientfd, char *cause, char *errnum,
		 char *shortmsg, char *longmsg)
{
    char buf[MAXLINE], body[MAXBUF];

    /* Build the HTTP response body */
    sprintf(body, "<html><title>Proxy Error</title>");
    sprintf(body, "%s<body bgcolor=""ffffff"">\r\n", body);
    sprintf(body, "%s%s: %s\r\n", body, errnum, shortmsg);
    sprintf(body, "%s<p>%s: %s\r\n", body, longmsg, cause);
    sprintf(body, "%s<hr><em>The Tiny Proxy server</em>\r\n", body);

    /* Print the HTTP response */
    sprintf(buf, "HTTP/1.0 %s %s\r\n", errnum, shortmsg);
    Rio_writen(clientfd, buf, strlen(buf));
    sprintf(buf, "Content-type: text/html\r\n");
    Rio_writen(clientfd, buf, strlen(buf));
    sprintf(buf, "Content-length: %d\r\n\r\n", (int)strlen(body));
    Rio_writen(clientfd, buf, strlen(buf));
    Rio_writen(clientfd, body, strlen(body));
}
/* $end clienterror */
