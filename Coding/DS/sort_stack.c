#include <stdio.h>
#include <stdlib.h>

struct stack {
	int data;
	struct stack *next;
};

struct stack *temp;

int pop(struct stack **start)
{
	
        int a = 0;
	if(*start == NULL) return (0);
 
	a = (*start)->data;
	*start = (*start)->next;

//	printf("\nPopped element:%d",a);
        return a;
}


void display(struct stack *start)
{
	printf("\n*****DISPLAYING*****\n");
	struct stack *curr = NULL;
	curr = start;
	
	if(curr == NULL) return;
	printf("\n");
	while(curr != NULL) {
		printf("%d ",curr->data);
		curr = curr->next;
	}
	printf("\n");
}

/* Add the node at the start/head */
struct stack *push(struct stack *head , int data)
{
//	printf("\npushing:%d",data);

	temp = (struct stack *)malloc(sizeof(struct stack *));
	if (temp == NULL) return (NULL);

	
	temp->data = data;
	if(head == NULL) 
	   temp->next = NULL;
	else 
	   temp->next = head;

	head = temp;

	return (head);
 
}

struct stack* SortedInsert(struct stack *start,int new)
{
	
	int tem;

	if(start == NULL || new > start->data)
	{	start = push(start,new);
//		printf("\npushed:%d",new);
		return(start);
	}

	tem = pop(&start);
//	printf("\ntemp:%d",tem);
	start = SortedInsert(start,new);
	start = push(start,tem);
	
  	return(start);
}

struct stack *sort(struct stack *start)
{
	int a;
	if(start == NULL) return (NULL);

	a = pop(&start);
//	printf("\na:%d",a);
//	display(start);
	start = sort(start);
//	display(start);
	start = SortedInsert(start,a);
//        display(start);	
 return (start);
}

int main()
{
	struct stack *head = NULL;

	head = push(head,10);
	head = push(head,20);
	head = push(head,5);
	head = push(head,1);
	head = push(head,50);	

	display(head);
/*
	printf("\npopped elem:%d\n",pop(&head));
	display(head);
*/

	head = sort(head);
	display(head);
	return 0;
}




















