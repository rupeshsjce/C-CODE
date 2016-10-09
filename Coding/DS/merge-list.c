#include <stdio.h>
#include  <stdlib.h> 

struct node {
  int info;
  struct node *next;
};

struct node* SortedMerge(struct node* a, struct node* b);

struct node *getnode()
{
  struct node *temp;
  temp = (struct node *) malloc(sizeof(struct node ));
  return temp;
}


void print_list(struct node *n)
{
 if ( n == NULL) return;
  printf("\n");
 while(n) {
  printf("%d ",n->info);
  n = n->next;
 }
 printf("\n");
}

int main()
{

 int n1= 4 , n2=5 , input;
 struct node *start1,*start2,*temp,*curr,*result;

 printf("\nEnter the value for first list\n");
 for(int i=0;i<n1;i++)
 {
   scanf("%d",&input);
   if(i == 0) {
     start1= getnode();
     start1->info = input;
     start1->next = NULL;
     curr = start1;
   } else {
   temp = getnode();
   temp->info = input;
   temp->next = NULL;
   curr->next = temp;    
   curr = temp;
   }
 } 

  print_list(start1);

 printf("\nEnter the value for second list\n");
 for(int i=0;i<n2;i++)
 {
   scanf("%d",&input);
   if(i == 0) {
     start2= getnode();
     start2->info = input;
     start2->next = NULL;
     curr = start2;
   } else {
   temp = getnode();
   temp->info = input;
   temp->next = NULL;
   curr->next = temp;    
   curr = temp;
   }
 } 


 print_list(start2);  


 /* Merge these two list */

 result = SortedMerge(start1,start2);
 print_list(result);

 return 0;
}

struct node* SortedMerge(struct node* a, struct node* b) 
{
  struct node* result = NULL;
 
  /* Base cases */
  if (a == NULL) 
     return(b);
  else if (b==NULL) 
     return(a);
 
  /* Pick either a or b, and recur */
  if (a->info <= b->info) 
  {
     result = a;
     result->next = SortedMerge(a->next, b);
  }
  else
  {
     result = b;
     result->next = SortedMerge(a, b->next);
  }
  return (result);
}
