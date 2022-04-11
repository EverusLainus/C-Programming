#include <stdio.h>

//integer power of a integer
int power(int x, int k)
{
    int y=1;
    int i;
    for(i=1; i<=k ; i++)
    {
        y=y*x;

    }
    return y;
}

int main ()
{
    int x;
    int k;
    printf("Enter a integer: \n");
    scanf("%d", &x);
    printf("Enter power of %d: \n", x);
    scanf("%d", &k);
    int y = power(x,k);
    printf("%d power %d is %d", x,k,y);
    return 0;

}