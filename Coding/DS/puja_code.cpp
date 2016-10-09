#include <iostream>
using namespace std;

/*
 * count = Final output ; number of jumps
 * jump = the height of the jump
 * slip = a person a slip 
 * wall = is an array which contains height of the walls.
 * n = total number of walla
 */



int calculate_jump(int walls[1000],int n, int jump,int slip)
{

	int jump_value = 0, remaining_height = 0;

         for (int i=0; i<n; i++)
         {
                remaining_height = walls[i];

                while (remaining_height > 0)
                {
                        jump_value++;
                        if(remaining_height == jump)
                        {
                                remaining_height = 0;
                        }
                        else {
                                remaining_height = remaining_height - (jump-slip);
                        }
                }
        }

 return jump_value;
}

int main()
{
	int jump,slip,count = 0,n ;
	int walls[1000];

	/* Test case 1  */
	  n = 1;
	  walls[0] = 10;
	  slip = 1;
	  jump = 5;
	 
          count = calculate_jump(walls,n,jump,slip);
	  cout<<"\n Total jump:"<<count<<"\n";



        /* Test case 2  */
          n = 2;
          walls[0] = 10; walls[1] = 9;
          slip = 1;
          jump = 5;

          count = calculate_jump(walls,n,jump,slip);
          cout<<"\n Total jump:"<<count<<"\n";



        /* Test case 3  */
          n = 6;
          int wall_arr[6] = {10,9,4,34,17,14};
          slip = 1;
          jump = 5;

          count = calculate_jump(wall_arr,n,jump,slip);
          cout<<"\n Total jump:"<<count<<"\n";


 return 0;
}
          

