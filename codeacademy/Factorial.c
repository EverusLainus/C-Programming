#include <stdio.h>

int main ()

{
    int a;
    int b =1;
    int i;

    printf("Enter a Number: \n");
    scanf("%d", &a);
    for (i=0; a >= 1 && i<=a-1 ; i++)
    {
b= b *  (a-i);
    }

    printf("Factorial of %d is %d", a, b);

return 0;

}
