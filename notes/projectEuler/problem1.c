#include <stdio.h>

int main()
{
    /* If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. 
    The sum of these multiples is 23.Find the sum of all the multiples of 3 or 5 below 1000 */

    // count from i =1 to 10. call it i.
    int i=1;
    int s=0;
    while (i<1000)  //if is a multiple of 3 or 5 

    {
if (i%3==0 || i%5 ==0)
{
    int a= i;
    printf("%d \n",a);
    s=s+a;
}
i++;
    }
    printf("The sum of multiples of 3 or 5 is %d", s);
    return 0;
}