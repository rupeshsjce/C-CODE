#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int val;
	int *rand;
	struct node *next;
}NODE;

NODE *start1,*start2; 

NODE * getnode(int value)
{
        printf("val:%d\n",value);
	NODE *temp;
	temp = (struct node *)malloc(sizeof(struct node *));
	temp->val = value;
        temp->next = NULL;
	temp->rand = NULL;
	return temp;
}


void print_list(NODE *start)
{
	if(start == NULL) return;
	while(start != NULL)
	{
		printf("%d ",start->val);
		start= start->next;
	}
	return;
}

int main() 
{
	auto int n = 4;
	int i = 0;
	int arr[4] = {10,20,30,40};
	NODE *start,*curr;

	while(i < n) {
		if (i ==0) {
 			start = getnode(arr[i]);
			curr = start;
		} else {
			curr->next = getnode(arr[i]);
		        curr = curr->next;
		}
		i++;
	}

        print_list(start);	


	return 0;
}
