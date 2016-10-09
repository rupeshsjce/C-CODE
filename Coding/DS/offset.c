#include <stdio.h>

#define offsetof(s,m) (size_t)&(((s *)0)->m)


typedef struct
{

   	int	i;
   	float	f;
   	char	c;
} SFOO;

int main()
{

 printf("\nOffset of 'f' is %zu\n", offsetof(SFOO, f));


 return 0;
}
