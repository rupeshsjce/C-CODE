/* check if two integers are same without using comparison operator */

#include <stdio.h>

int main()
{
	int a,b,flag=0,count=0;
	printf("\nEnter the two numbers:");
	scanf("%d %d",&a,&b);

	do
	{
		if(a>>1 != b>>1) {
			flag = 1;
			break;
		}
	
		count++;
	} while(count > sizeof(int));

	if(!flag)
		printf("\nBoth are equal\n");
	else
		printf("\nBoth are not equal\n");


 return 0;
}
