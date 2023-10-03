// create and initalize a semaphore
//semaphore.h not supported in Max OS

#include <semaphore.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void function(int a){
    sem_wait(&sem);
    printf("Hi! semaphore. I'm thread - a\n");
    sem_post(&sem);
}

int main(){

//create a semaphore
    sem_t sem;

//initalise a semaphore
//allows max 10 threads
    sem_init(&sem, 0, 10);

//create two threads
    pthread_t t1,t2;
    pthread_create(&t1, NULL, function, 1);
    pthread_create(&t1, NULL, function, 2);

    return 0;
}