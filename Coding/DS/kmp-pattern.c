#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define bool int


void print_val(int v[],int n)
{
	printf("\n");
	for (int i = 0 ; i < n ; i++ )
	{
        	printf("%d ",v[i]);
	}
	printf("\n");
}


void pattern(char p[10],int v[10],int n)
{

	int i = 1 , j = 0;

        while(i != n) {
                if(p[i] == p[j]) {
			printf("\nMatch[%d,%d]",i,j);
                        v[i] = j + 1;
                        i++ ; j++;
			printf("\nM[%d,%d] p[%c,%c]",i,j,p[i],p[j]);
                } else {
                        if (j>0) {
				printf("\nN1[%d,%d] p[%c,%c]",i,j,p[i],p[j]); 
                                j = v[j-1];
				printf("\nN2[%d,%d] p[%c,%c]",i,j,p[i],p[j]);
                        } else {
				printf("\nN3[%d,%d] p[%c,%c]",i,j,p[i],p[j]);
                                v[i] = 0;
                                i++;
				printf("\nN4[%d,%d] p[%c,%c]",i,j,p[i],p[j]);
                        }
                }


        }

}


bool kmp(char t[20],int m,char p[10],int v[10],int n)
{
	bool ret = FALSE;
	int j = 0;

	for(int i=0; i<m; i++)
	{
		if(t[i] == p[j]) {
			j++;
			if ( j == 5) ret = TRUE;
		} else {
			if(j > 0)
			 	j = v[j-1];
		}
	
	}

 return (ret);

}

int main()
{
	char p[10] = {'a','b','c','a','b','y'};
	int  v[10] = {0};
        char t[20] = {'a','b','x','a','b','c','a','b','c','a','b','y'};

	int n = 6; //size of pattern
        int m = 12;   //size of text
    
	pattern(p,v,n);
	print_val(v,n); 

        if(kmp(t,m,p,v,n))
		printf("\nPRESENT\n");
	else
		printf("\nNOT PRESESNT\n");



 return 0;
}
