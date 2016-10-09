#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int T = 0, j,count = 0;
    int n[100] = {0};
    
    scanf("%d",&T);
    for(int k =0 ; k< T; k++) {
           scanf("%d",&n[k]);
    }
    
    j = T;
    while(j) {
      for(int i=0;i<32;i++) {
          //printf("\n%d\n",n[count]);
        n[count]  = n[count] ^ (1 << i);
      }
       
      printf("%d\n",n[count]); 
      count++; 
      j--;   
    }
    
    return 0;
}

