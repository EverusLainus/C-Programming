// client that uses datagram socket

#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>

int main(int argv, char *argc[]){

    if(argv !=3){
        perror("not enough arguments");
        return 1;
    }

//addrinfo
    int rv;
    struct addrinfo hints, *servinfo, *p;
    memset(&hints, 0, sizeof hints);
    hints.ai_family=AF_INET6;
    hints.ai_socktype=SOCK_DGRAM;
    rv=getaddrinfo(argc[1], "1112", &hints, &servinfo);
    if(rv!=0){
        perror("addrinfo");
        return 1;
    }

//socket
    int sock_res;
    for(p=servinfo; p!=NULL; p=p->ai_next){
        sock_res = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if(sock_res == -1){
            perror("socket");
            continue;
        }
        break;
    }

//sendto
    int sendto_res;
    sendto_res = sendto(sock_res, argc[2], strlen(argc[2]), 0, 
    p->ai_addr, p->ai_addrlen);
    if(sendto_res == -1){
        perror("sendto");
        return 1;
    }
    return 0;
}