/*
 * Longest common subsequence problem using DP .
 * Author : Rupesh Kumar
 * Date   : Feb 12 , 2016
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max(int a , int b)
{
 	return (a>b ? a : b);
}


void print_matrix(int v[6][7],int n ,int m)
{


        int i , j ;

	printf("\n");
        for(i=0; i<=m ; i++)
        {
                for(j=0;j<=n;j++)
                {
			printf("%d ",v[i][j]);
		}
		printf("\n");
	}

}

int main()
{
	char s1[10] = {'a','b','c','d','a','f'};
	char s2[10] = {'a','c','b','c','f'};

	int n , m , i , j,N,M ;
	n = 6;N = n+1; 
	m = 5;M = m+1;
	int v[6][7] = {0};

	for(j=0; j<m ; j++)
	{
		for(i=0;i<n;i++)
		{
			if(s2[j] == s1[i])
				v[j+1][i+1] = v[j][i] + 1;
			else
				v[j+1][i+1] = max(v[j+1][i],v[j][i+1]);
		}
	}
	

	print_matrix(v,n,m);

 return 0;
}

