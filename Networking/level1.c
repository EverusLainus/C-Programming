#include <stdlib.h>
#include <stdio.h>

#include<sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h> 
#include <unistd.h>


int main(){
//addrinfo  
    struct addrinfo hints;//i come from netdb
    struct addrinfo *getaddrinfo_res, *p;
    memset(&hints, 0, sizeof hints);

    hints.ai_flags= AI_PASSIVE;
    hints.ai_family=AF_INET;
    hints.ai_socktype=SOCK_STREAM;

    //use getaddrinfo to fill the rest of the fields of addrinfo
    int result =getaddrinfo(NULL, "1112", &hints,  &getaddrinfo_res);
    printf("resuts from getaddrinfo is %d \n", result);

//socket & bind
    int socket_res;
    //returns a socket descriptor
    int bind_res;
    for(p=getaddrinfo_res; p != NULL; p=p->ai_next){
        socket_res= socket(p->ai_family, p->ai_socktype, 0);
        printf("resuts from socket is %d \n", socket_res);
        if(socket_res==1){
            continue;           
        }

        bind_res = bind(socket_res, p->ai_addr, p->ai_addrlen);
        printf("resuts from bind is %d \n", bind_res);
        if(bind_res==-1){
            continue;
        }
        break;
    }
    if(p==NULL){
        printf("failed to bind\n");
    }

//listen
    int listen_res;
    listen_res= listen(socket_res, 10);
    printf("resuts from listen is %d \n", listen_res);

//accept and send
    struct sockaddr_storage their_addr;
    int accept_res;
    while(1){       
        socklen_t addr_size = sizeof their_addr;       
        accept_res = accept(socket_res,(struct sockaddr *)&their_addr, &addr_size );
        printf("resuts from accept is %d \n", accept_res);

        char *message ="Jesus, i Trust in You";
        int message_len = strlen(message);
        int send_res = send(accept_res, message, message_len, 0);
        printf("resuts from send is %d \n", send_res);
    }

//close
    close(socket_res);
    return 0;
}
/*
//test in terminal
 nc -v -n ip 1112
*/

