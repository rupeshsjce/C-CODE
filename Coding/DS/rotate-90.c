#include <stdio.h>
int n = 5;
void print(char m[n][n])
{
 for(int i=0;i<n;i++)
 {
   for(int j=0;j<n;j++)
   {
     printf("%c ",m[i][j]);
   }
   printf("\n");
 } 
}

void rotate(char matrix[5][5], int n) 
{
 for (int layer = 0; layer < n / 2; ++layer) {
      int  rst = layer; 
      int last=n-1-layer;
	for(int i =  rst; i < last; ++i) {
		int offset = i -  rst;
		int top = matrix[ rst][i]; // save top
		// left -> top
		matrix[ rst][i] = matrix[last-offset][ rst];
		// bottom -> left
		matrix[last-offset][ rst] = matrix[last][last - offset];
		// right -> bottom
		matrix[last][last - offset] = matrix[i][last];
		// top -> right
		matrix[i][last] = top; // right <- saved top 
	}
 }


 printf("\nNEW ROTATION ...\n");
 print(matrix);
 
}


int main()
{
 char m[5][5] = { '*', '#', '^', '$', '@',
                  '*', '#', '|', '$', '@',
                  '*', '#', '|', '$', '@',
                  '*', '#', '|', '$', '@',
                  '*', '#', '|', '$', '@'
                 };


 char m2[5][5] = { '3', '1', '0', '1', '1',
                  '0', '1', '0', '0', '2',
                  '0', '0', '0', '1', '3',
                  '1', '1', '1', '1', '4',
                  '9', '8', '7', '6', '5'
                 };

 
 char m1[5][5];

 int i =0 , j =0 , k =0;
 
for (i=0;i<n;i++)
{
 for (j=0;j<n;j++)
 {
   k = (n-1)-i;
   m1[j][k] = m2[i][j];
 }
}

 printf("\nOriginal Matrix\n");
 print(m2);
 printf("Matrix after rotation\n\n");

 print(m1);
  
 rotate(m2,5);

 return 0;
}
