#include <stdio.h>
#include <stdlib.h>
int main()
{
 char ptr1[] = "Hello world";
 char *ptr2 = malloc(5);
 ptr2= ptr1; 

return 0;
}
