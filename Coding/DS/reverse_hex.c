#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int num = 0x1234abde;
	printf("\nnum:%0x\n",num);
	int num1 =0,i = 0,num2=0,j=7,add_num=0xf;

	for(i=7;i>=0;i--) {
		num2 = num & add_num;
		add_num = add_num << 4;
		num1  = (i>=4) ? (num1 | (num2 << (j*4))) : (num1 | (num2 >> (abs(j)*4)));
		j = j-2; 
	}
	
        printf("\nnum1:%0x\n",num1);

        int val = 0 ; num1 = num ; long int sum = 0;
	for(i=0;i<8;i++) { 
        val = ( num1 & 0xf ); //printf("\nval=%0x",val);
	num1 = num1 >> 4;
	sum  = sum + (val * pow(16,7-i)); //printf("\nsum=%d",sum);
	}
 	
	printf("\nnum1:%0x\n",sum);//conver dec to hex

 return 0;
}
