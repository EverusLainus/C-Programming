#include <stdio.h>


int prime (int a)
{
    int i;
    int c=0;
for (i=1; i<= a; i++)
{
    if (a%i == 0)

    {
    c++;
    }
}
return c;
}
int main()
{
   /* The prime factors of 13195 are 5, 7, 13 and 29.*/

   int i;
   int b;
   int N;
   
   printf("Enter a integer:");
   scanf("%d", &N);

for (i=1; i<= N; i++)
{
if(N%i == 0)
{
   int b= prime(i);
    if (b==2){
    printf("%d is a prime factor of  %d\n",i,N);
    }
}
}
   return 0;
}