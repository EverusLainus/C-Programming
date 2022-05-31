#include <stdio.h>
#include <stdlib.h>

unsigned power(unsigned x, unsigned y)
{
    if(y==0){
        return 1;
    }
    else{
        return (x * power(x, y-1));
    }
}

int main ()
{
    unsigned c_1 = power(-1,2);
    printf("c_1=%u \n",c_1);

    unsigned c_2 = power(2,3);
    printf("c_2= %u \n",c_2); 
  
    unsigned c_3 = power(2,3);
    printf("c_3=%u \n",c_3);

    unsigned c_4 = power(0,3);
     printf("c_4= %u \n",c_4); 

    unsigned c_5 = power(-1,1);
    printf("c_5=%u \n",c_5);

    unsigned c_6 = power(2,64);
    printf("c_6=%u \n",c_6);

    unsigned c_7 = power(0,0);
     printf("c_7= %u \n",c_7);

    if (c_1!=1 || c_2!=8 || c_3!=8 || c_4!=0 ||c_5!= 4294967295 || c_6 != 0 || c_7 !=1){
        return EXIT_FAILURE; 
    }
    return EXIT_SUCCESS;
}
/*
test: power.c test-power.c 
        gcc  -pedantic -std=gnu99 -Wall -Werror -fsanitize=address -c test-power.c(convert test-power.c into object file)
        gcc  -pedantic -std=gnu99 -Wall -Werror -fsanitize=address -c power.c(convert power.c into object file)
        gcc  -pedantic -std=gnu99 -Wall -Werror -fsanitize=address  test power.o test-power.o -o test   (link two object files as test)
*/
