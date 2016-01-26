#include <stdio.h>

int main()
{

 int arr[10] = { -2 , 4 , -3 , 5 , 6 , -9 , 0 , 2 , 4 , -3 };
 int max_sum_so_far = 0 , sum_till_now = 0;
 int i = 0;

 for (i = 0 ; i <10 ; i++ ) {
  
      sum_till_now  = sum_till_now + arr[i];
      if (sum_till_now < 0 ) sum_till_now = 0;
      if (max_sum_so_far < sum_till_now ) {
          max_sum_so_far = sum_till_now;
      }
 }
 printf("\n Maximum Sum = %d\n",max_sum_so_far);
 return 0;
}
