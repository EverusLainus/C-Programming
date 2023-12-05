//to find the length of buffer of unknown length
#include <stdio.h>
#include <string.h>

int main() {
    char buffer[100];  // Assuming a buffer of size 100

    // Assume data has been received into the buffer
    // and the length is unknown.
    for(int i=0; i<32; i++){
        buffer[i]=1;
    }

    // Find the length based on the first null character
    size_t length = strnlen(buffer, sizeof(buffer));

    printf("Length of the filled part: %zu\n", length);

    return 0;
}
