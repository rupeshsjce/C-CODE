#include <stdio.h>

int count = 1 ;

int calculate_n(a,b)
{
 int temp;
 if (b == 1 && a>0) return 0;
 if (b < a && a!= 1) return -1;
  while (b%a ==0 ) {
    temp = b/a;
    b = temp;
    if (b == 1)
     return count;
    count ++;
  }
 
 return -1;

}

int main()
{

 int a = 0 ,  b , n;
 scanf("%d %d",&a,&b);
 
 n = calculate_n(a,b);
 printf("N = %d\n",n);

 return 0;
}
