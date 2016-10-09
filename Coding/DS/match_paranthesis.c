#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


char st[1000][1000];
int N,top=-1;
char stac[1000];

void push(char ch){
    //printf("%c",ch); 
    stac[++top] = ch;
}

int pop(char ch)
{
   //printf("%c",ch); 
   int ret = 1;
   char temp;
   if(top<0) return 0;
   temp = stac[top];
    if(temp == '(') temp = ')';
    if(temp == '}') temp = '}';
    if(temp == ']') temp = ']';
   if (temp != ch)
        ret = 0;
    
    top -- ;
    return ret;
}
int push_pop_stack(char ar[1000])
{
   char ch;
   int i = 0 , val=0,sum=0,ret=1;
    
   while(1) {
       ch = ar[i++];
       if(ch == '\0') break;
       
       if (ch == '(' || ch == '{' || ch == '[') {
           push(ch);
       } 
       
       if (ch == ')'|| ch == '}'|| ch == ']') {
           if(!pop(ch)) return 0;
       }
   } 
       
   
   return ret;
}

int main() {
    char ch;int k = 0;int res=0;
    scanf("%d",&N);
    //printf("%d\n",N);
    for(int i=0;i<N;i++)
    {
        scanf("%s",st[i]);
    }
  
    for(int i=0;i<N;i++)
    {
        //printf("%s\n",st[i]); 
        //printf("\n=====\n");
        res = push_pop_stack(st[i]);
        printf("%s\n",res?"YES":"NO");
        //printf("\n=====\n");
    }
    
    
    
    

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}

