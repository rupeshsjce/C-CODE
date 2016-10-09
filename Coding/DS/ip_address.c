#include <stdio.h>

union ip {

   unsigned int int_val;
   unsigned char c[4];
};


int
 main()
 {
   union ip p;
   p.int_val = 3232235786; //int val for 192.168.1.10
   
   printf("%u.%u.%u.%u\n", p.c[3], p.c[2], p.c[1], p.c[0]);
 
   return 0;
 }
