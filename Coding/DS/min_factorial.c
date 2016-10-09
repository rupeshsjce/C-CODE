#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int coeff[10] = {0};
int max_index = 0;

void calculate_coefficient(int x)
{
 int i = 0 , cv = 0 ;
  
 for (i=1 ; i<10; i++)
 {
   cv = pow(5,i-1) + coeff[i-1];
   if(cv <= x) coeff[i] = cv;
   else break;
 }
 max_index = i-1;
}

int main(int argc , char *argv[])
{
 int num_zeros = 0 , i = 0;
 int min_fact = 0 , num = 0 , rem = 0;

 printf("\nEnter the number of zero's:");
 scanf("%d",&num_zeros);
 rem = num_zeros; 

 calculate_coefficient(num_zeros);
 printf("\n");
 /* print coefficient */
 for (i = 1 ; i <=max_index ;i++)
   printf("%d ",coeff[i]);

 printf("\n"); 
 for(i=max_index ; i>=1 ;i--)
 {
   if (rem/coeff[i] <= 4){
      num = num + (pow(5,i) * (rem/coeff[i]));
      rem = rem - ((rem/coeff[i]) * coeff[i]); 
      if(!rem) break;
      //if( i == 2 && rem >4) 
   } else
   {
     printf("\nMin factorial doesnt exist for this number of zero:%d\n",num_zeros);
     exit(0);
   }
 }

 printf("zeros = %d min-fact-value=%d\n",num_zeros,num);
 return 0;
} 
