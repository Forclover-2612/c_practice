#include<stdio.h>

int main()
{
    char ch;
    int n;
    scanf("%d",&n);
    if(n<10)
    {
        ch='0'+n;
    }
    else
    {
        ch='A'+n-10;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            printf(" ");
        }
        for(int j=0;j<2*(n-i)-1;j++){
            printf("%c",ch);
        }
        printf("\n");
    }
    return 0;
}