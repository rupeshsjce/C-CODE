#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node* left;
    struct node* right;
};


struct node* root,*temp;

struct node* insert(struct node* r, int data);

void inorder(struct node* r)
{
 if ( r==NULL) return;
 inorder(r->left);
 printf("%d\n",r->value);
 inorder(r->right);
 
}

void mirror(struct node* r)
{
 if ( r==NULL) return;
 temp = r->left;
 r->left = r->right;
 r->right = temp;

 mirror(r->left);
 printf("\nMirror\n");
 mirror(r->right);
}

int main()
{
    root = NULL;

    int n = 12 ;
    int v[12] = { 11,6,3,17,5,9,1,14,18,10,13,15};

    for(int i=0; i<n; i++){
        root = insert(root, v[i]);
    }

    inorder(root);
    mirror(root);
    inorder(root);
    return 0;
}

struct node* insert(struct node* r, int data)
{
    if(r==NULL) // BST is not created created
    {
        r = (struct node*) malloc(sizeof(struct node)); // create a new node
        r->value = data;  // insert data to new node
        // make left and right childs empty
        r->left = NULL;   
        r->right = NULL;
    }
    // if the data is less than node value then we must put this in left sub-tree
    else if(data < r->value){ 
        r->left = insert(r->left, data);
    }
    // else this will be in the right subtree
    else {
        r->right = insert(r->right, data);
    }
    return r;

}
