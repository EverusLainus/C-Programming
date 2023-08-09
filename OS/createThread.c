//let's create my first threading program
#include <stdio.h>
#include <pthread.h>

void * function(void *a){
    int* i = (int*) a;
    printf("I am  %d \n", *i);
    return 0;
}

int main(){
    int times =3;
    pthread_t my_thread[times];
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        printf("i is %d\n",i);
        int t= pthread_create(&my_thread[i], NULL, function, &i);
        if(t !=0){
            printf("something happened");
        }
        else{
            printf("t is %d\n",t);
        }       
    }
    return 0;   
}