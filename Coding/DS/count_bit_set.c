#include <stdio.h>

int main(int arc,char *argv[])
{
long int n = 0xffffffff;
 long int half_oct = 0 ;int  count = 0;


 printf("\nsizeof_int:%lu\n",sizeof(int));
 while(n) {
	half_oct = n & 0xf;
	n = n >> 4;

	while(half_oct) {
		half_oct = (half_oct & (half_oct-1));
		count++;
	}
 }

 printf("\ncount:%d\n",count);
 return 0;
}
