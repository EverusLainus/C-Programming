#include <stdio.h>

int main()
{
    unsigned int bigNum = 100; 
    int littleNum = -100;

  printf("unsigned integer value of 100 is %u \n", bigNum); 

  printf("integer value of -100 is %u \n", littleNum);
  
  if (bigNum > littleNum) 
  {
  printf("Obviously, 100 is bigger than -100!\n"); 
  }
else 
{
  printf("Something unexpected has happened!\n");
}
return 0;
}
