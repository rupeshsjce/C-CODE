#include <stdio.h>

int N =0;

void printPar(int l , int r , char str[N+1], int count)
{

	if(l< 0 || r < l) return; // invalid state

	if (l == 0 && r == 0) {
		str[N] = '\0';
		printf("\n%s",str); // found one, so print it 
	} else {
		if (l > 0) { // try a left paren, if there are some available 
			str[count] = '(';
			printPar(l - 1, r, str, count + 1);
		}
		if (r > l) { // try a right paren, if there’s a matching left
			 str[count] = ')';
			 printPar(l, r - 1, str, count + 1); 
		}
	}
 }



int main()
{
	int count = 0;
	printf("\nEnter the count for N-Pair paranthesis:");
	scanf("%d",&count);
	N = 2*count;
	char str[count*2 + 1];

	printPar(count, count, str, 0); 

	 printf("\n");
 return 0;

}
