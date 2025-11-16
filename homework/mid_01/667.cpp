#include<stdio.h>

int main()
{
    int m,n;
    int i;
    int a=0,b=0,c=0,d=0;
    scanf("%d %d",&m,&n);
    for(i=1;i<=m;i+=4)
    {
        if(i%n==0)
        {
            a++;
        }
    }
    for(i=2;i<=m;i+=4)
    {
        if(i%n==0)
        {
            b++;
        }
    }
    for(i=3;i<=m;i+=4)
    {
        if(i%n==0)
        {
            c++;
        }
    }
    for(i=4;i<=m;i+=4)
    {
        if(i%n==0)
        {
            d++;
        }
    }
    printf("%d %d %d %d",a,b,c,d);
    return 0;
}