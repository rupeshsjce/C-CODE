// C program to print all permutations with duplicates allowed
#include <stdio.h>
#include <string.h>
 
/* Function to swap values at two pointers */
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 
/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(char *a, int l, int r)
{
   int i;

   if(r == 0 ) return;

   if (l == r)
     printf("%s\n", a);
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          permute(a, l+1, r);
          swap((a+l), (a+i)); //backtrack
       }
   }
}
 
/* Driver program to test above functions */
int main()
{
    char str[] = "1234";
    char str1[10];
    int n = strlen(str);

    memset(str1, '\0', sizeof(str1));   

    for(int i=0;i<n;i++)  {
       printf("\n%c",str[i]);
    }  
     printf("\n");

    for(int i=1;i<=n;i++)
    {
        strncpy(str1,str,i);
	permute(str1, 0, i-1);
    }
    return 0;
}
