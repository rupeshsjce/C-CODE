/*
 * RUPESH KUMAR , 27th Jan 2016.
 * code : sum of left subtree and sum of right subtree
 * code : sum of left nodes and sum of right nodes.
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node* left;
    struct node* right;
};

int sl =0 , sr= 0;

int sumSubtree(struct node* r)
{
 if ( r==NULL) return 0;
 return(r->value + sumSubtree(r->left) + sumSubtree(r->right));
}

/*
 * SUM of left nodes and right nodes only . [ DON'T confuse with sum of left/right subtree]
 */
int sumLN(struct node* r, int add)
{
 if (r == NULL)  return 0;
 if(add) sl = sl + r->value;
 sumLN(r->left,1);
 sumLN(r->right,0);
 return 0;
}


int sumRN(struct node* r, int add)
{
 if (r == NULL)  return 0;
 if(add) sr = sr + r->value;
 sumRN(r->left,0);
 sumRN(r->right,1);
 return 0;
}

// A utility function to create a node
struct node* newNode( int data )
{
    struct node* temp = (struct node *) malloc( sizeof(struct node) );

    temp->value = data;
    temp->left = temp->right = NULL;

    return temp;
}

int main()
{

    // Let us construct the tree given in the above diagram
    struct node *root         = newNode(20);
    root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);
   
    if (root && root->left && root->right) 
     printf("\nSUM Left Subtree:%d Right Subtree:%d\n",sumSubtree(root->left),sumSubtree(root->right));
    else
     printf("\nPlease have at least one left and right node\n");

   if (root && root->left && root->right)  {
     sumLN(root,0);
     sumRN(root,0);
     printf("\nSUM Left Nodes:%d Right Nodes:%d\n",sl,sr);
    }
    else
     printf("\nPlease have at least one left and right node\n");

 return 0;
}
