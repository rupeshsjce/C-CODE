#include <stdio.h>

#define my_sizeof(type) (char *)(&type+1)-(char*)(&type)

struct node {
	int a;
	char b;
};


void my_sizeof1(int type) 
{
	printf("%d %d\n",(&type+1),(&type));
	int val;
	val = (char *)(&type+1) - (char *)(&type);
	printf("\nval:%d\n",val);
}


int main()
{
    int x;
    printf("\nmy_sizeof:%d\n", my_sizeof(x));
    //my_sizeof1(x);
    struct node n1;
    printf("my_sizeof:%d sizeof:%d\n",my_sizeof(n1),sizeof(n1));
    return 0;
}
