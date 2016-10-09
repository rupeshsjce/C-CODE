#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int side = 0; /* 0 is left , 1 is right */
int a[20] = {15,20,25,16,4,9,13,17,12,50};

int max(int a , int b)
{
 printf("\na=%d b=%d",a,b);
 if(a>b) {
  side = 0;
  return (a);
 } else {
   side = 1;
   return (b);
 }
}

int whatAmI(int num)
{
 printf("\nNumber:%d\n",num);
 int ret = 0;
 if((num-1)%2 == 0){
     printf("\nreturn here\n");
     return (ret);
 }
 
 ret = 1;
 return (ret);
}


void display_array(int b[10])
{
 printf("\n");
 for(int i=0;i<10;i++)
 { 
   printf("%d ",b[i]);
 }
 printf("\n");
}

void heapify(int a[20],int bound)
{
 int LR = 0; /* LR = 0 means left child and LR = 1 means right child */
 int max_val = 0, temp = 0;
 int i = 0;
 
 for(i=bound ; i>=0 ; i=i-2)
 {
        printf("\ni=%d\n",i);
        max_val = max(a[i],a[i+1]); /* Passing (left-child,right-right) always */
        printf("\nMAX-VAL:%d\n",max_val);

        if(a[i/2] < max_val)
        { printf("\nchild is greater than root\n");
          if(side) /* swap right with root */
            { printf("\nSwapping right\n"); 
              temp = a[i+1]; a[i+1] = a[i/2]; a[i/2] = temp; }
          else
            { printf("\nSwapping left\n");
              temp = a[i]; a[i] = a[i/2]; a[i/2] = temp; }

	}
        display_array(a);
 }
 
}


int main()
{
 int i = 0 , N = 0 , n = 0 , input = 10 ;
// int a[20] = {15,20,25,16,4,9,13,17,12,50};
 int o[20] = {0};

/*
 printf("\nEnter the size of the elements(max=20):");
 scanf("%d",&input);
 n = input;


 printf("\nEnter the elements\n");
 for(i = 0; i<n ;i++)
  scanf("%d",&a[i]); 
*/

 n = input;

 if(whatAmI(n-1)) /* right */
 {
    printf("\nI am here\n");
    a[n] = 0;   /* Suppose all numbers > 0 */ 
    n = n-1;
 }

 
 for(i=0 ; i<n ; i++)
 {
    N = n-1;
    heapify(a,N);
    o[i] = a[0];
    a[0] = a[(input-1)-i];
    a[(input-1)-i] = o[i];
    display_array(a);
    if(whatAmI(n-1)) /* right */
    {
     printf("\nam here\n");
     n = n-2; 
    }
    else 
     n = n-2;
 } 


 printf("\nThe elements in des order is ...\n");
 for(i = 0; i<input ;i++)
  printf("%d ",o[i]);

 return 0;
}
