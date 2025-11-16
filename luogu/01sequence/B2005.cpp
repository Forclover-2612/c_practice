#include<stdio.h>

int main()
{
    char ch;
    scanf("%c",&ch);//简化：char ch=getchar()
    printf("  %c  \n",ch);
    printf(" %c%c%c \n",ch,ch,ch);
    printf("%c%c%c%c%c\n",ch,ch,ch,ch,ch);
    return 0;
}