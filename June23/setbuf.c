#include <stdio.h>
#include <string.h>

/*
The C <stdio.h> BUFSIZ is a macro constant that expands 
to an integral expression with the size of the buffer 
used by the setbuf() function


*/

//if we use any integral value for size of buff program aborts.

//setbuf writes the contents of the buff with stdout

int main(){
    char buff[BUFSIZ];
    memset(buff, 0, BUFSIZ);
    setbuf(stdout, buff);

//nothing in buff this printf step    
    //printf("%s\n", buff);

    printf("It's a windy cold day\n");
//buff contains the output characters
    printf("%s\n", buff);
    
    //fclose(stdout);
//works fine without fclose
    return 0;

}