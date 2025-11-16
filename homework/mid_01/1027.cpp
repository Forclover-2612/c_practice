#include<stdio.h>

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    int count=0;
    for(int i=a;i<=b;i++)
    {
        if((i%4==0&&i%100!=0)||i%400==0)
        {
            count++;
            i+=3;
        }
    }
    printf("%d",count);
    return 0;
}