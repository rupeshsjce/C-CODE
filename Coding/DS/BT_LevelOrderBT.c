/* program to check if a tree is height-balanced or not */
#include<stdio.h>
#include<stdlib.h>
#define bool int
 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
  int data;
  struct node* left;
  struct node* right;
};
 
/* The function returns true if root is balanced else false
   The second parameter is to store the height of tree.  
   Initially, we need to pass a pointer to a location with value 
   as 0. We can also write a wrapper over this function */
void PrintLevelOrder(struct node *root, int level)
{
 
	if(root == NULL) return;
	
	if (level == 1) {
		printf("%d ",root->data);
		return;
	}

	PrintLevelOrder(root->left,level-1);
	PrintLevelOrder(root->right,level-1);
  printf("\n");
 return;
 
}
 
 
/* UTILITY FUNCTIONS TO TEST isBalanced() FUNCTION */
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
    struct node* node = (struct node*)
                                malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return(node);
}
 
int max(int a,int b)
{
 return (a>b ? a:b);
}

int FindHeight(struct node *r)
{
  if (r == NULL) return 0;
 
  return(1+max(FindHeight(r->left),FindHeight(r->right)));  

}

int main()
{
  int height = 0;
    
  /* Constructed binary tree is
             1
           /   \
         2      3
       /  \    /
     4     5  6
    /
   7
  */   
  struct node *root = newNode(1);  
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->left->left->left = newNode(7);
 
  height = FindHeight(root);

 
  printf("Height=%d\n",height);
  for(int i=1;i<=height;i++)
   PrintLevelOrder(root,i);

  printf("\n");

  return 0;
}






#if 0

/* Returns the height of a binary tree */
int height(struct node* node);
 
/* Returns true if binary tree with root as root is height-balanced */
bool isBalanced(struct node *root)
{
   int lh; /* for height of left subtree */
   int rh; /* for height of right subtree */ 
 
   /* If tree is empty then return true */
   if(root == NULL)
    return 1; 
 
   /* Get the height of left and right sub trees */
   lh = height(root->left);
   rh = height(root->right);
 
   if( abs(lh-rh) <= 1 &&
       isBalanced(root->left) &&
       isBalanced(root->right))
     return 1;
 
   /* If we reach here then tree is not height-balanced */
   return 0;
}
 
/* UTILITY FUNCTIONS TO TEST isBalanced() FUNCTION */
 
/* returns maximum of two integers */
int max(int a, int b)
{
  return (a >= b)? a: b;
}    
 
/*  The function Compute the "height" of a tree. Height is the
    number of nodes along the longest path from the root node
    down to the farthest leaf node.*/
int height(struct node* node)
{
   /* base case tree is empty */
   if(node == NULL)
       return 0;
 
   /* If tree is not empty then height = 1 + max of left
      height and right heights */
   return 1 + max(height(node->left), height(node->right));
} 
 


#endif
