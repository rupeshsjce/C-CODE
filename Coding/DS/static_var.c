#include <stdio.h>


void call_s(int x,int y,int z)
{
 static int count = 1;
 //int count = 1; 
 printf("\nx:%d y:%d z:%d\n",x,y,z);
 
 while(count != 5) {
  printf("\nx:%d y:%d z:%d count:%d\n",x,y,z,count);
  count = count +1;
 }


}


int main()
{
 int a = 10;
 int b = 0;
 static int c = 20;
 //int c = 20;
 
 printf("\na:%d b:%d c:%d\n",a,b,c);

 ++a;++b;++c;
 printf("\na:%d b:%d c:%d\n",a,b,c);
 
 call_s(a,b,c);
 call_s(a,b,c);


 return 0;
}

