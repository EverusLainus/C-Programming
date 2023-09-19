//calloc function
#include <stdio.h>
#include <stdlib.h>

int main(){
    int *a;
    a = calloc(3, sizeof a);
    
    printf("alocated address points to %d\n", a);
//calloc initialised the alocated space with 0.
    printf("contents of address %d\n", *a);
    *a = 13;
    printf("contents of address after initialising %d\n", *a);

//free eraise the contents to zero
    free(a);
    printf("contents of address after free() %d\n", *a);
    return 0;
}