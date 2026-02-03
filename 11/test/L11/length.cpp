#include<stdio.h>

int main()
{
    char *p=NULL;
    char s[]="abcdefgh";
    p=s;
    while(*p!='\0')
    {
        p++;
    }
    printf("the length is:%d\n",p-s);
    return 0;
}