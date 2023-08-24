//throw errors
//without fork
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
    int result =getaddrinfo(NULL, "1111", &hints,  &getaddrinfo_res);
    if(result !=0){
        fprintf(stderr, "getaddrinfo : %s\n", gai_strerror(result));
    }

//socket & bind
    int socket_res;
    //returns a socket descriptor
    int bind_res;
    for(p=getaddrinfo_res; p != NULL; p=p->ai_next){
        socket_res= socket(p->ai_family, p->ai_socktype, 0);
        if(socket_res==-1){
            perror("socket");
            continue;           
        }

        bind_res = bind(socket_res, p->ai_addr, p->ai_addrlen);
        //printf("resuts from bind is %d \n", bind_res);
        if(bind_res==-1){
            perror("bind");
            continue;
        }
        break;
    }
    if(p==NULL){
        perror("failed to bind");
    }

//listen
    int listen_res;
    listen_res= listen(socket_res, 10);
    if(listen_res==-1){
        perror("listen");
        return 1;
    }

    struct sockaddr_storage their_addr;
    int accept_res;
    while(1){ 
        //printf("sock_res is %d \n", socket_res);    
        socklen_t addr_size = sizeof their_addr;       
        accept_res = accept(socket_res,(struct sockaddr *)&their_addr, &addr_size );
        if(accept_res == -1){
            perror("accept");
            continue;
        }

        char message[10];
        int message_len = strlen(message);//dont do this!!!
        printf("message_len %d\n", message_len );
            //printf("accept_res is %d \n", accept_res); 
            int recv_res = recv(accept_res, message, 10, 0);
            if(recv_res<0){
                perror("recv");
                continue;
            }
            printf("resuts from recvis %d \n", recv_res);
            close(accept_res); 
//          break;   
    }
//close
    close(accept_res);
    return 0;
}
/*
//test in terminal
 nc -v -n ip 1112
*/


