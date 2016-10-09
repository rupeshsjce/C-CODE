#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 /* N X N MATRIX */
 int n = 4;

#define boolean int
#define TRUE  1
#define FALSE 0



boolean IsSafe(int grid[n][n],int row,int col)
{
  int i =0 , j =0;
 
  //row
  for(i=0;i<n;i++)
   if(grid[row][i] == 1) return FALSE;

  //column
  for(i=0;i<n;i++)
   if(grid[i][col] == 1) return FALSE; 

  //diagonal
  for(i=0;i<n;i++)
  {
     for(j=0;j<n;j++)
     {
         if(i == row && j == col) 
         {
            continue;
         } else {
            if(grid[i][j])
            {
              if(abs((row-i)) == abs((col-j))) return FALSE;
            }
         }
     }
  }
   
  return TRUE;
}

boolean Nqueen(int grid[n][n],int row)
{
  for(int i=row;i<n;i++)
  {
   for(int j=0;j<n;j++)
   {
      if(IsSafe(grid,i,j))
      {
         grid[i][j] = 1;
         if(Nqueen(grid,i+1)) return TRUE;

         grid[i][j] = 0;
      }
   }
   return FALSE;

  }
 return TRUE;
}


void print(int grid[n][n])
{
 for (int i=0;i<n;i++)
 {
   for(int j =0;j<n;j++)
   {
     printf("%d ",grid[i][j]);
   }
   printf("\n");
 }

}

int main()
{
  int grid[4][4] = { 0, 0, 0, 0,
                     0, 0, 0, 0,
                     0, 0, 0, 0,
                     0, 0, 0, 0
                   };

   Nqueen(grid,0);
   printf("\n Solution\n");
   print(grid);

 return 0;
} 
