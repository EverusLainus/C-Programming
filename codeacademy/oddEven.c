#include <stdio.h>

int main ()
{
    int a;
    printf("Enter a number: ");
    scanf("%d", &a);
     if (a%2 == 0)
    { 
       printf("%d is even", a);
    }
     else
     {
        printf("%d is not odd", a); 
     }
     return 0;
}
