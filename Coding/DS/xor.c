#include <stdio.h>

int main()
{
	int T = 0;
    	int n[10] = {0}; 
        long int res = 0 ;
        long int arr[100][100];

        scanf("%d",&T);
    
        for(int j=0;j<T;j++){
             scanf("%d",&n[j]);
    
             for(int i=0;i<n[j];i++) {
                scanf("%d",&arr[j][i]);
             }
        }
	
	
 	for(int k=0;k<T;k++) {
	    res = 0;
	    if(n[k] % 2 == 0) {
		printf("\nRes:%d\n",res);
	    } else {
		for(int i = 0 ; i < n[k] ; i++) {
			if(i%2 == 0) {
				res = res ^ arr[k][i];
			}
		}
	      printf("\nRes:%d\n",res);
	   }
	}		

	return 0;
}

