#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char * str) {
  int n=0;
  int i=0;
  if ( str == NULL) {return;} 
  for (i=0;str[i]!= '\0';i++)
  {
      n++;
  }
 // printf("The length of the string is %d\n", n);
  char rev_str[n];
  
  for (i=0;i<n;i++)
  {
  rev_str[i]= str[(n-1)-i];
  //printf("%c\n", rev_str[i]);
  }
    for (i=0;i<n;i++)
  {
  str[i]=rev_str[i];
  //printf("%c\n", str[i]);
  }
  //printf("the reverse string is %s\n",str );

}

int main(void) {
    //char str7[] = {};
      char str0[] = "";
  char str1[] = "123";
  char str2[] = "abcd";
  char str3[] = "Captain's log, Stardate 42523.7";
  char str4[] = "Hello, my name is Inigo Montoya.";
  char str5[] = "You can be my wingman anyday!";
  char str6[] = "Executor Selendis! Unleash the full power of your forces! There may be no tomorrow!";
  char * array[] = {str0, str1, str2, str3, str4, str5, str6};
  for (int i = 0; i < 7; i++) {
    reverse(array[i]);
    printf("%s\n", array[i]);
  }
  return EXIT_SUCCESS;
}
