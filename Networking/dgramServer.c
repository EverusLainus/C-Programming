#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <errno.h>
#include <sys/types.h>
#include<sys/socket.h>
#include <netdb.h>
#include <netinet/in.h> 
#include <arpa/inet.h>


int main(){
//addaddrinfo
    int rv;
    struct addrinfo hints, *servinfo, *p;

    memset(&hints, 0, sizeof hints);
    hints.ai_flags= AI_PASSIVE;
    hints.ai_family=AF_INET6;//use only ipv6
    hints.ai_socktype= SOCK_DGRAM;

    rv =getaddrinfo(NULL, "1112", &hints, &servinfo);
    if(rv!=0){
        perror("addrinfo");
    }

//socket and bind
    int sock_res;
    int bind_res;
    for(p=servinfo; p!= NULL; p=p->ai_next){
        sock_res=socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if(sock_res == -1){
            perror("socket");
            continue;
        }
        bind_res = bind(sock_res, p->ai_addr, p->ai_addrlen);
        if(bind_res == -1){
            perror("socket");
            continue;
        }
        break;
    }

//recvfrom
    int recvfrom_res;
    char message[10];
    struct sockaddr_storage their_addr;
    socklen_t addr_len = sizeof their_addr;
    recvfrom_res = recvfrom(sock_res, message, 10, 0, 
    (struct sockaddr *)&their_addr, &addr_len);
    if(recvfrom_res == -1){
        perror("recvfrom");
        return 1;
    }
    for(int i=0; i< (sizeof message-1); i++){
        printf("%c", message[i]);
    }

    message[recvfrom_res]='\0';
//close
    close(sock_res);

    return 0;
}
