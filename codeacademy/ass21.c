#include <stdio.h>
#include <stdlib.h>

void printDigits(int x) {
  if (x == 0) {
    printf("0");
  }
  else if (x < 0) {
    printf("-");
    printDigits(-x);
  }
  else {
    int a = x/10;
    int b = x %10;
    printf("a=%d, b=%d\n",a,b);
    if (a != 0) {
      printDigits(a);
    }
    printf("b=%d",b);
  }
}


int main(void) {
  printDigits(297);
  printf("\n");
  return EXIT_SUCCESS;
}

/*
x=297
printDigits(297)
a=29
b=7
print a,b

call printDigits(29)
a=2
b=9
print a,b

call printDigits(2)
a=0
b=2
print a,b and b
return to printDigits(29)

print b
return to printDigits(2)
print b
output
a=29, b=7
a=2, b=9
a=0, b=2
297
*/
