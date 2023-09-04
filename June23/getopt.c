//try getopt function

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    if(argc <2){
        printf("not enough arguments\n");
    }
    int option;
    //int option =getopt(argc, argv, "a:");
    //printf("option is %d\n", option);
    while((option = getopt(argc, argv, ":l:p:f:d:hq")) != -1){
        printf("option is %d\n", option);
        switch(option){
            case 'p':
            printf("got a\n");
            break;
            case 'f':
            printf("got f\n");
            break;
            case 'd':
            printf("got d\n");
            break;
            case 'h':
            printf("got h\n");
            break;
            case '?':
            printf("what???");
            break;
        }
    }
    return 0;
}