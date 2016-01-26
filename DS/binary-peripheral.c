#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG 1

#define d(fmt, ...) \
        do { if (DEBUG) { \
                fprintf(stderr,"%s[%d]:" fmt,__func__,__LINE__,##__VA_ARGS__); \
                fprintf(stderr,"\n"); \
             } \
           }while (0) \

struct node
{
    int value;
    struct node* left;
    struct node* right;
};


struct node* root;

struct node* insert(struct node* r, int data);
void pp1(struct node* r, int flag);
void pp2(struct node* r, int flag);

void inorder(struct node* r)
{
 if ( r==NULL) return;
 inorder(r->left);
 printf("%d\n",r->value);
 inorder(r->right);
 
}
int i = 1;

void pp1(struct node *r,int flag) 
{
  if ( r == NULL ) return;
  
  //printf("value is :%d i is:%d\n",r->value,flag);

  if(flag == 1) printf("val:%d\n",r->value);
  else if(r->left == NULL && r->right == NULL) printf("%d\n",r->value);
  
  pp1(r->left,1);
  if(r == root) return;
  pp1(r->right,2);
}


void pp2(struct node *r,int flag) 
{
  if ( r == NULL ) return;
  
  //printf("value is :%d i is:%d\n",r->value,i);

  if(flag == 1) printf("val:%d\n",r->value);
  else if(r->left == NULL && r->right == NULL) printf("%d\n",r->value);
  
  pp2(r->left,2);
  if(r == root) return;;
  pp2(r->right,1);
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
    d("New anwers");
    pp1(root,1);
    pp2(root->right,1);
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
