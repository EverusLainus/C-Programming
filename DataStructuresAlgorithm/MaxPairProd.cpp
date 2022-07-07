#include <stdio.h>
#include <stdlib.h>

int MaxPairwiseProduct(int * sequence, int n){
    int Max1 =-1;
    int max_index =0;
    int Max2 =-1;
    for(int i=0 ; i<n;i++){
        if((Max1=-1 )|| (sequence[i] > Max1)){
            printf("(sequence)[%d] is %d\n", i, (sequence)[i]);
            Max1 = (sequence)[i];
            max_index =i;
        }
    }
    printf("first max is %d at %d\n", Max1, max_index);
    for(int j=0 ; j<n;j++){
        
        if((Max2=-1 || sequence[j] > Max2) && (j!=max_index)){
            printf("2.  (sequence)[%d] is %d\n", j, (sequence)[j]);
            Max2 = sequence[j];
             printf("second max is %d \n", Max2);
        }
    }
    printf("second max is %d \n", Max2);
    return Max1 * Max2;

}
 
 int main()
 {
    int n;
    scanf("%d", &n);
    int sequence[n];
    for(int i=0; i<n ;i++){
        scanf("%d  ", (sequence[i]));
        printf("count i  is %d", i);
    }
    int result = MaxPairwiseProduct(sequence, n);
    printf("%d", result);
    return 0;
 }