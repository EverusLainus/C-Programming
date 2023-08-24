#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    int res1;
    res1=fork();
    if(!res1){
        
        printf("res1 is %d \n", res1);

    }

    //child fork reads even after if block;
    printf("b: res1 is %d \n", res1);
    return 0;
}

/*
Definition:
The C fork() function returns three integers as the return value. 
The three integers are like a positive value (it contains the process ID),
 a negative value (when the child process fails), 
 or a zero (when the child process is created successfully).

 The value of n represents the number of fork() system calls.
 So the process will be forked in the form of 2 power of n. 

 the child and parent will execute every line of code after the fork (each separately)
*/