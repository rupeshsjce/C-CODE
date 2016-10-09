#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int arr[100][100];


//XOR from index for n elements.
int xor (int index, int n,int row)
{
    int res = 0, first =1;
    for(int i = index-1 ; i<(index+n-1) ; i++)
    {
       if(first) {
        res = arr[row][i]; first = 0 ;continue;
       }
       res = res ^ arr[row][i] ;

    }
 return (res);
}

/* Driver program to test above functions */
int main()
{
    int T = 0;
    int n[10] = {0}; 
    //int n = 4;
    int res = 0 ,first = 1 ;

    scanf("%d",&T);
    
    for(int j=0;j<T;j++){
        scanf("%d",&n[j]);
    
        for(int i=0;i<n[j];i++) {
          scanf("%d",&arr[j][i]);
        }
    }
    
    
for(int k=0;k<T;k++) {
  res = 0; first = 1;
  for(int j=1;j<=n[k];j++) {
    for(int i=1;i<=(n[k]-j)+1;i++)
    {
      if(first) {
        res =  xor(i,j,k); first = 0 ;continue;
      }
      res = res ^ xor(i,j,k);
    }
  }
    
printf("%d\n",res);
}
 
 return 0;
}

