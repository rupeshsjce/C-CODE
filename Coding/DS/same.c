#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


char st[1000][1000];
int N,top=-1;
char stac[1000];

void push(char ch){
    printf("\npush:%c\n",ch); 
    stac[++top] = ch;
}

int pop(char ch)
{
   printf("\npop:%c\n",ch); 
   int ret = 1;
   char temp;
   if(top<0) {
     printf("\nINVALID\n");
     return 0;
   }
   temp = stac[top];
   printf("\nTOP of the stack is:%c\n",temp);	
    if(temp == '(') temp = ')';
    if(temp == '{') temp = '}';
    if(temp == '[') temp = ']';
   if (temp != ch) {
        printf("\nINVALID RET\n");
        ret = 0;
   }    
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
    char ch;int k = 0;int res=0,fin=0;
    scanf("%d",&N);
    //printf("%d\n",N);
    for(int i=0;i<N;i++)
    {
        scanf("%s",st[i]);
    }
  
    for(int i=0;i<N;i++)
    {
        top = -1; fin = 0;
        printf("%s\n",st[i]); 
        printf("\n=====\n");
        res = push_pop_stack(st[i]);
	printf("\nret is :%d\n",res);
        if(res == 1 && top < 0)
        {   printf("\n setting fine to 1\n");
            fin = 1;
        }
        if(fin == 1) printf("here YES\n");
        else printf("here NO\n");
        printf("\n=====\n");
    }
    
    
    
    

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}

