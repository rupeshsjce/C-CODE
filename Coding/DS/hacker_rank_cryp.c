#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


char fill_x(char a,char b)
{
    
 if(a == b) return '0';   
 
 return '1';
}    
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n, i, k,j=0;
    char s[2000000],o[2000000],X;
    
    scanf("%d %d",&n,&k);
    scanf("%s",s);
    
  //  printf("%d %d %s",n,k,s);
    for( i=0;i<n;i++)
    {
	//printf("\nHello[%d]",i); 
        if (i==0) {
            o[i] = s[i] ; 
	  //  printf("\no[%d]:%c",i,o[i]);
        } else {
 	    //printf("\nhelloooo");
            X = s[i]; 
	    //printf("\n%s[%d]",__FUNCTION__,__LINE__);
	    j =i-1;
	    //printf("\n%s[%d]",__FUNCTION__,__LINE__);
            do {
	      //  printf("\n%s[%d]",__FUNCTION__,__LINE__);
                X = fill_x(X,o[j]);
	        //printf("\n%s[%d]",__FUNCTION__,__LINE__);
                j--;   
		//printf("\n%s[%d]",__FUNCTION__,__LINE__);
                 
            } while (j >=0 && (((i-k)>0) ? (j > (i-k)) : 1) );
	   //printf("\n%s[%d]",__FUNCTION__,__LINE__);
	    o[i] = X;  
	    //printf("\n%s[%d]",__FUNCTION__,__LINE__);
            //if((X == 0))  o[i] = '0'; else  o[i] = '1' ;
            //printf("\no[%d]:%c",i,o[i]);
	    //printf("\n%s[%d]",__FUNCTION__,__LINE__);
       } 
    }
	//printf("\n%s[%d]",__FUNCTION__,__LINE__);
    o[i] = '\0';
    printf("\n%s\n",o);
    
    return 0;
}

