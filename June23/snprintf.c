//program to try snprintf function in c

#include <stdio.h>

int main(){
    char buffer[36];
    char *s ="Glory to Jesus, King of all Kings";
    
    printf("i am a buffer with size 20\n");

    //copies 15 characters from s and put it in buffer
    int j = snprintf(buffer, 15, "%s/n", s);

    //writen the max possible value it can written
    printf("value returned by snprintf() is %d\n", j);

    printf("value writtened on buffer is %s\n", buffer);
    return 0;

}