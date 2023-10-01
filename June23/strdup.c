#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){
    char *strPtr="Hey there!";
    int strPtr_len = strlen(strPtr);
    printf("string Pointer is \"%s\" with length %d\n", strPtr, strPtr_len);

//print each byte
    for(int i=0; i<strPtr_len; i++){
        printf("%c", strPtr[i]);
    }
    printf("\n");

//make a character array
    char char_arr[3]={'h', 'e', 'y'};
    printf("char array is .%s.\n", char_arr);

//make the null-terminated byte string
    strdup(strPtr);
    int strdup_strPtr_len = strlen(strPtr);
    printf("string Pointer is \"%s\" with length %d\n", strPtr, strdup_strPtr_len);

    strdup(char_arr);
    printf("char array is .%s. with length %lu\n", char_arr, strlen(char_arr));

    return 0;
}