// server echo protocal
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

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
    printf("resuts from getaddrinfo is %d \n", result);

//socket & bind
    int socket_res;
    //returns a socket descriptor
    int bind_res;
    for(p=getaddrinfo_res; p != NULL; p=p->ai_next){
        socket_res= socket(p->ai_family, p->ai_socktype, 0);
        printf("resuts from socket is %d \n", socket_res);
        if(socket_res==-1){
            perror("socket");
            continue;           
        }

        bind_res = bind(socket_res, p->ai_addr, p->ai_addrlen);
        printf("resuts from bind is %d \n", bind_res);
        if(bind_res==-1){
            perror("bind");
            continue;
        }
        break;
    }
    if(p==NULL){
        printf("failed to bind\n");
        perror("failed to bind");
    }

//listen
    int listen_res;
    listen_res= listen(socket_res, 10);
    if(listen_res==-1){
        perror("listen");
        return 1;
    }

//accept and send
    struct sockaddr_storage their_addr;
    int accept_res;
    char s[INET6_ADDRSTRLEN];
    while(1){       
        socklen_t addr_size = sizeof their_addr;       
        accept_res = accept(socket_res,(struct sockaddr *)&their_addr, &addr_size );
        if(accept_res == -1){
            perror("accept");
            continue;
        }

        //inet_ntop(their_addr.ss_family, get_in_addr((struct sockaddr *)&their_addr),
        //s, sizeof s);
        //printf("server: got connection from %s\n", s);

        char from_client[10];
        char message[10];
        int message_len = 10;
        //creates a child process using fork
        if(!fork()){
            close(socket_res);
            int recv_res =recv(accept_res, from_client, 10, 0);
            if(recv_res==-1){
                perror("recv");
                continue;
            }
            printf("receiving\n");
            for(int i=0; i< sizeof from_client; i++){
                printf("%c", from_client[i]);
                message[i]=toupper(from_client[i]);
            } 



           int send_res = send(accept_res, message, message_len, 0);
            if(send_res==-1){
                perror("send");
                continue;
            }
 //           printf("resuts from send is %d \n", send_res);
            
            
            from_client[recv_res]='\0';           
            close(accept_res);
            return 0;//without written it loops
        }       
    }
//close
    close(accept_res);
    return 0;
}

/*
//test in terminal
 nc -v -n ip 1112
*/

