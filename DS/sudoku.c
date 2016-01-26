#include <stdio.h>
#include <string.h>

 /* N X N SUDOKU */
 int n = 9;

#define boolean int
#define TRUE  1
#define FALSE 0
int maxi ,maxj;

boolean f1(int a)
{
 if (a) return TRUE;
 else return FALSE;

}


boolean InBox(int grid[n][n],int i,int j,int num)
{

 /* Get the box number first */
 if(j==0 || j==1 || j==2) {
    if (i==0 || i==1 || i==2) {
        maxi = 2; maxj=2;
    } else if (i==3 || i==4 || i==5) {
        maxi=5; maxj=2;
    } else {
        maxi=8; maxj=2;
    }
 } else if (j==3 || j==4 || j==5){
    if (i==0 || i==1 || i==2) {
        maxi = 2; maxj=5;
    } else if (i==3 || i==4 || i==5) {
        maxi=5; maxj=5;
    } else {
        maxi=8; maxj=5;
    }    
 }  else {
     if (i==0 || i==1 || i==2) {
        maxi = 2; maxj=8;
     } else if (i==3 || i==4 || i==5) {
        maxi=5; maxj=8;
     } else {
        maxi=8; maxj=8;
     }   
  }

 /* Search in the box */
 for (int p = maxi-2 ; p<=maxi ; p++)
  for (int q = maxj-2 ; q<=maxj; q++)
   if(grid[p][q] == num) return FALSE;

 return TRUE;
}

boolean InRow(int grid[n][n], int row , int num)
{
 for (int j=0;j<n;j++)
  if(grid[row][j] == num) return FALSE;

 return TRUE;
}


boolean InCol(int grid[n][n], int col, int num)
{
 for (int i=0;i<n;i++)
  if(grid[i][col] == num) return FALSE;

 return TRUE;
}

boolean IsSafe(int grid[n][n],int i,int j,int num)
{
 if (InBox(grid,i,j,num) && InRow(grid,i,num) && InCol(grid,j,num))
  return TRUE;

 return FALSE;
}

boolean findAvailCell(int grid[n][n],int *row,int *col)
{
    for (int i=0;i<n;i++)
     for(int j=0;j<n;j++)
      if(grid[i][j] == 0) {
        *row = i; 
        *col = j;
        return TRUE;
      }
 return FALSE;
}

boolean sudokuSolver(int grid[n][n])
{
   int m1=0,m2=0;
   if(!findAvailCell(grid,&m1,&m2)) return TRUE;
   
    for(int i=1; i<=n; i++)
    {
        if(IsSafe(grid,m1,m2,i))
        {
          grid[m1][m2] = i;

          if(sudokuSolver(grid))
            return TRUE;
        
  
         /* Unassign the just assigned value */
         grid[m1][m2] = 0;
        }
    }
    return FALSE;
}

void printSolution(int grid[n][n])
{
  for (int i=0;i<n;i++)
  { 
     for(int j=0;j<n;j++)
     {
       printf("%d ",grid[i][j]);
       if(!((j+1)%3)) printf("  ");
     }
  
     printf("\n");
     if (!((i+1)%3)) printf("\n");
   }
} 

int main()
{

#if 0
  int n = 10;
  boolean flag = FALSE;
  flag = f1(n);
  printf("\nFLag=%d\n",flag);;
#endif


 int grid[9][9] = { 0, 1, 0, 7, 3, 0, 0, 0, 4,
                    0, 0, 2, 0, 0, 0, 0, 5, 9,
                    0, 0, 0, 9, 2, 0, 3, 0, 0,
                    0, 5, 0, 0, 9, 1, 0, 0, 0,
                    0, 0, 0, 4, 0, 8, 0, 0, 0,
                    0, 0, 0, 5, 7, 0, 0, 9, 0,
                    0, 0, 9, 0, 1, 2, 0, 0, 0,
                    8, 6, 0, 0, 0, 0, 7, 0, 0,
                    2, 0, 0, 0, 5, 7, 0, 4, 0
                  };

 printf("\nOriginal Sudoku\n");
 printSolution(grid); 
 printf("\n\n");
 sudokuSolver(grid);
 printf("\nPrinting the solution\n");
 printSolution(grid);
  
 return 0;
} 
