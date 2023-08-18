#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#include<netdb.h>
#include<sys/socket.h>
#include<sys/types.h>

int main(int argc, char *argv[]){
    if(argc!=2){
        perror("not enough arguments");
        return 0;
    }

//addrinfo
    int fd;
    struct addrinfo hints, *servinfo, *p;
    memset(&hints, 0, sizeof hints);
    hints.ai_family=AF_INET;
    hints.ai_socktype=SOCK_STREAM;

    fd=getaddrinfo(argv[1], "1111", &hints, &servinfo);
    if(fd== -1){
        perror("getaddrinfo");
    }
//socket and connect
    int socket_res;
    int connect_res;
    for(p=servinfo; p!=NULL;p=p->ai_next){
        socket_res= socket(p->ai_family, p->ai_socktype, 0);
        if (socket_res == -1){
            perror("socket");
            continue;
        }
        connect_res=connect(socket_res,p->ai_addr,p->ai_addrlen );
        if(connect_res== -1){
            perror("connect");
            continue;
        }
        break;
    }

//recv
    int recv_res;
    
    char message[100];
    recv_res = recv(socket_res, message, 100, 0);
    if(recv_res ==-1){
        perror("recv");
        return 0;
    }
    printf("message is ");
    //clear the space
    for(int i=0; i< sizeof message; i++){
        printf("%c", message[i]);
    }
    message[recv_res]='\0';

//close
    close(socket_res);
    return 0;      
}