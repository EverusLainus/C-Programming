#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n)
{
    if(n==0)
    {
        return 0;
    }
    int l=1;
    int a=1;
    int i;
    for(i=0; i<(n-1); i++)
    {
        if (array[i]< array[i+1])
        {
            a++;
            if (l<a)
            {
                l=a;
            }
        }
        if ((array[i]) >= (array[i+1]))
        {
            a=1;
        }
    }
    return l;
}

int main()
{
  int array0[] = {};  
  int array1[5] = { 0};
  int array2[8] = { 77, 33, 19, 99, 42, 6, 27, 4};
  int array3[5] = { 0, 1, 1, 2, 3};
  int array4[] = { -3, -42, -99, -1000, -999, -88, -77};
  int array5[] = { 425, 59, -3, 77, 0, 36};
  int array6[] = { 2,3,4,1,0,1,2,3,1,0,1,2,3,4,1,0,1,2,3,4,5};
  int array8[] = { 0,1,0, 1, 1, 0, 1, 1, 2, 0};
  
    int max0 = maxSeq(array0,0);
    int max1 = maxSeq(array1,5);
    int max2 = maxSeq(array2,8);
    int max3 = maxSeq(array3,5);
    int max4 = maxSeq(array4,7);
    int max5 = maxSeq(array5,6);
    int max6 = maxSeq(array6,21);
    int max8 = maxSeq(array8, 10);
    
    printf("max0=%d\n", max0);
    printf("max1=%d\n", max1);
    printf("max2=%d\n", max2);
    printf("max3=%d\n", max3);
    printf("max4=%d\n", max4);
    printf("max5=%d\n", max5);
    printf("max6=%d\n", max6);
    printf("max8=%d\n", max8);
    
    if(max0 !=0){
        return EXIT_FAILURE;
    }
    if(max1 !=1){
        return EXIT_FAILURE;
    }
        if(max2 !=2){
        return EXIT_FAILURE;
    }
        if(max3 !=5){
        return EXIT_FAILURE;
    }
        if(max4 !=4){
        return EXIT_FAILURE;
    }
            if(max5 !=2){
        return EXIT_FAILURE;
    }
            if(max6 !=6){
        return EXIT_FAILURE;
    }
            if(max8 !=2){
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
    
}