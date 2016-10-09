#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>




int main() {
    
    int max_sum_so_far = 0 , sum_till_now = 0 , max_sum = 0;
    int i,j,k ,T ,max,neg;
    scanf("%d",&T);
    int size[T];
    int *arr[T];
    
    for(j = 0; j< T ;j++){
        scanf("%d",&size[j]);
        arr[j] = (int *)malloc(size[j] * sizeof(int));
        for(k = 0; k< size[j] ;k++)  {
            scanf("%d",&arr[j][k]);
        }   
    }

    for(j = 0; j< T ;j++){
        max_sum_so_far = 0;sum_till_now=0,max_sum=0,max = -10000,neg=0;
        for (i = 0 ; i <size[j] ; i++ ) {
             if(arr[j][i] > 0) max_sum +=  arr[j][i];
             else {
                 ++neg;
                 if(max < arr[j][i]) max = arr[j][i];
                 if(neg == size[j]) {
                     max_sum_so_far = max_sum = max;
                     break;
                 }    
             }
             sum_till_now  = sum_till_now + arr[j][i];
             if (sum_till_now < 0 ) sum_till_now = 0;
             if (max_sum_so_far < sum_till_now ) {
                 max_sum_so_far = sum_till_now;
             }
         }
          printf("%d %d\n",max_sum_so_far,max_sum);
    }


    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}

