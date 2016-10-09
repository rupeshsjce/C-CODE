#include <stdio.h>

int n;
double d;

int add(int a , int b)
{
 	 return (a+b);
}

void* add_int(void *px , void *py)
{
	 int *p1 = (int*) px;
	 int *p2 = (int*) py;
	 n = (*p1 + *p2);
	 return &n;
}

int sub(int a , int b)
{
	 return (a-b);
}

void* add_double(void *px , void *py)
{
	 double *p1 = (double*) px;
	 double *p2 = (double*) py;
	 d = (*p1 + *p2);
	 return &d;
}


void *func[100] = {
                   add_int,
                   add_double
                   };

void* processing(void *px, void *py, void* (*operation)(void*,void*))
{
	 void * res = (*operation)(px,py);
	 return res;
}

int main()
{
	 int (*foo)(int , int );
	 int res , input;

	 /* Module 1
	  * Basic Function Pointer.
	  */

	 printf("Enter add(1)/sub(0) : ");
	 scanf("%d",&input);
	 if (input)
	   foo = add;
	 else
	   foo = &sub;  /* a different way of passing */

	 res = foo(10,5);
	 printf("\n %d\n",res);


	 /* Module 2
	  * Calling Function Pointer using different ways.
	  */

	 void* (*op)(void*,void*);
	 op = func[0]; /* op = add_int; OR op = &add_int; */
	 int *ans;
	 int m1=10,m2=20;
	 ans = (int*) processing(&m1,&m2,op);
	 printf("\n value = %d\n",*ans);
 

	 double *ans1;
	 // op = add_double; /* op = func[1]; OR op = &add_double; */
	 double n1=10,n2=5;
	 ans1 = (double*) processing(&n1,&n2,add_double); /* a different way of passing */
	 printf("\n value = %f\n",*ans1);

	 return 0;
}
