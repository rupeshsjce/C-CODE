/* 
 * Pythagorean triplet 
 */

#include <stdio.h>
#include <string.h>

int main()
{
 	int i ,j , k , n ;
	int a[10] = { 4, 9, 16, 25, 36, 41, 289, 576, 625, 900};
	n = 10;

#if 0      
	for(i=0; i<n; i++)
        {
		a[i] = a[i]*a[i];
	}
#endif

	for(i=0; i<n; i++)
	{
		for(j=i+1; j<n; j++)
		{
			k =  n - 1;
			if(a[i]+a[j] == a[k])
			{
				printf("\nTriplet[%d+%d=%d]\n",a[i],a[j],a[k]);
				break;
			}
			else if (a[i]+a[j] < a[k])
			{
				//continue; 
				k = k - 1;
			}
		}
	}


	return 0;
} 
