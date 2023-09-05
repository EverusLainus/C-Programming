// client that uses datagram socket

#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>

int main(int argv, char *argc[]){

    if(argv !=4){
        perror("not enough arguments");
        return 1;
    }

//addrinfo
    int rv;
    struct addrinfo hints, *servinfo, *p;
    memset(&hints, 0, sizeof hints);
    hints.ai_family=AF_INET;
    hints.ai_socktype=SOCK_DGRAM;
    rv=getaddrinfo(argc[1], argc[2], &hints, &servinfo);
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
    int broadcast =1;
//broadcast
    // Lose the pesky "address already in use" error message
    int now =setsockopt(sock_res, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof broadcast);
    if(now ==-1){
        perror("setsockopt");
        return 1;
    }

//sendto
    int sendto_res;
    sendto_res = sendto(sock_res, argc[3], strlen(argc[3]), 0, 
    p->ai_addr, p->ai_addrlen);
    if(sendto_res == -1){
        perror("sendto");
        return 1;
    }
    else{
        printf("send\n");
    }
 close(sock_res);
    return 0;
}