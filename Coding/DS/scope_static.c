#include<stdio.h>
#include <stdlib.h>

void func1_Str(char **ptrx);
char** func2_Str();

int main(void)
{
    char *ptr1 = NULL;
    char **ptr2 = NULL;

    func1_Str(ptr1);
    printf("\n [%s]",*ptr1);

    ptr2 = func2_Str();
    printf("\n [%s] :: func2_Str()address = [%p], its returned address is [%p]\n",*ptr2,(void*)func2_Str,(void*)ptr2);

    printf("\n [%s] [%p]\n",*ptr1,(void*)ptr1);

    return 0;
}

void func1_Str(char **ptr11)
{
    //char *p = "Linux";

    char *p = (char *)malloc(sizeof(char)*6);
    //strcpy(p,"Linux");

    **ptr11 = &p;
}

char** func2_Str()
{
    char *p = (char *)malloc(sizeof(char)*8);
    strcpy(p,"Windows");
    return &p;
}
