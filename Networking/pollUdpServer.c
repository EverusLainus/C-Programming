//dgram poll server that receives a message.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <poll.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void add_to_pfds(struct pollfd *pfds[], int newfd, int *p_counts, int *p_size){
    if(*p_counts == *p_size){
        *p_size *= 2;
        *pfds = realloc(*pfds, sizeof (**pfds) * (*p_size));
    }
    (*pfds)[*p_counts].fd= newfd;
    (*pfds)[*p_counts].events = POLLIN;
    (*p_counts)++;
}

void del_from_pfds(struct pollfd pfds[], int i, int *p_counts){
    (pfds)[i]=(pfds)[*p_counts-1];
    (*p_counts)--;
}

int get_listener(){

//addrinfo    
    int rv;
    struct addrinfo hints, *servinfo, *p;
    int sock_res;
    int bind_res;
    int listen_res;
    int yes=1;
    memset(&hints, 0, sizeof hints);
    hints.ai_flags = AI_PASSIVE;
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype= SOCK_DGRAM;

    rv =getaddrinfo(NULL, "1114", &hints, &servinfo);
    if(rv==-1){
        perror("addrinfo\n");
        return 1;
    }
//socket and bind
    
    for(p=servinfo; p!=NULL; p=p->ai_next){
        sock_res = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if(sock_res == -1){
            perror("socket");
            continue;
        }

        // Lose the pesky "address already in use" error message
        setsockopt(sock_res, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));

        bind_res = bind(sock_res, p->ai_addr, p->ai_addrlen);
        if(bind_res ==-1){
            perror("bind");
            continue;
        }
        break;
    }

    return sock_res;
}

int main(){

    int rv;
    struct addrinfo hints, *servinfo, *p;
    int sock_res;
    int bind_res;
    int listen_res;
    
    int p_size = 5;
    int p_counts =0;
    struct pollfd *pfds = malloc (sizeof (*pfds) * p_size);
    int poll_res;
    int listener = get_listener();
    printf("got a listener %d \n", listener);
    pfds[0].fd= listener;   
    pfds[0].events = POLLIN;
    p_counts =1; 

    for(;;){

        poll_res = poll(pfds, p_counts, -1);
        printf("ready no: %d", poll_res);
        if(poll_res == - 1){
            perror("poll");
            return 1;
        }
       
        for(int i=0; i< p_counts; i++){
            if(pfds[i].revents & POLLIN){
                    struct sockaddr_storage their_addr;
                    socklen_t len = sizeof their_addr;
                    if(pfds[i].fd==listener){
                        add_to_pfds(&pfds, pfds[i].fd, &p_counts, &p_size);
                    }
                    
                    char buff[10];
                    int recvfrom_res =recvfrom(pfds[i].fd, buff, 10, 0, (struct sockaddr *)&their_addr, &len);
                    if(recvfrom_res <=0){
                        perror("recv");
                        del_from_pfds(pfds, i, &p_counts);
                        continue;
                    }
                    else{
                        for(int j=0; j< recvfrom_res; j++){
                            printf("%c", buff[j]);
                        }
                        printf("\n");
                    }
            }//poll has it ready
        }
    }
}