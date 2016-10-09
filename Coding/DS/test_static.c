#include<stdio.h>

char* func1_Str(char *);
//char** func2_Str();

int main(void)
{
    char *ptr1 = NULL;
    ptr1= (char *)malloc(sizeof(char)*4);
    strcpy(ptr1,"abc");
    ptr1[3]="\0";
    //*ptr1[3] = ;
    //char **ptr2 = NULL;

    ptr1 = func1_Str(ptr1);
    printf("\n [%c] :: func1_Str() address = [%p], its returned address is [%p]\n",*ptr1,(void*)func1_Str,(void*)ptr1);

/*
    ptr2 = func2_Str();
    printf("\n [%s] :: func2_Str()address = [%p], its returned address is [%p]\n",*ptr2,(void*)func2_Str,(void*)ptr2);

    printf("\n [%s] [%p]\n",*ptr1,(void*)ptr1);
*/
    return 0;
}

char* func1_Str(char *p1)
{
     char *p  = p1;
    //p =  (char *)malloc(sizeof(char)*4);
   // *p = 'abc';
    //*p = "abc";
    //strcpy(p,"abc");
    //p[3]='\0';
     printf("%c",*p);
    p++; 
   return p;
}

/*
char* func2_Str()
{
    char *p = "Windows";
    
    return &p;
}
*/
