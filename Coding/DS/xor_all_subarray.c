// C program to print all permutations with duplicates allowed
#include <stdio.h>
#include <string.h>

int arr[4]= {1,2,3};
 

//XOR from index for n elements.
int xor (int index, int n)
{
    int res = 0, first =1;
    for(int i = index-1 ; i<(index+n-1) ; i++)
    {
       if(first) {
        res = arr[i]; first = 0 ;continue;
       }
       res = res ^ arr[i] ;
       
    }
 return (res);
}
 
/* Driver program to test above functions */
int main()
{
   // int arr[4] = {1,2,3,4};
    int n = 3;
    int res = 0 ,first = 1 ;

    for(int i=0;i<n;i++)  {
       printf("\n%d",arr[i]);
    }  
    printf("\n");

  for(int j=1;j<=4;j++) {
    for(int i=1;i<=(n-j)+1;i++)
    {
      if(first) {
        res =  xor(i,j); first = 0 ;continue;
      }
      res = res ^ xor(i,j);
    }
  }
 
 printf("\nResult:%d\n",res);
    return 0;
}
