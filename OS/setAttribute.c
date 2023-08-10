// the second parameter of pthread is attribute. 
//if set to NULL- we get default attributes

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *function(void *arg){
    printf("I am a function\n");
    return NULL;
}

int main(){
    pthread_t my_thread;
    pthread_attr_t my_attr;
    pthread_attr_init(&my_attr);
    //set state to detached
    pthread_attr_setdetachstate(&my_attr, PTHREAD_CREATE_DETACHED);
    //make scope as system scope
    pthread_attr_setscope(&my_attr, PTHREAD_SCOPE_SYSTEM);

    pthread_create(&my_thread, &my_attr, function,NULL);
    printf("created\n");
    return 0;
}