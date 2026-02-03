#include<stdio.h>

int main()
{
    int a,b,x,y;
    scanf("%d %d",&a,&b);
    for(x=0;x<=100;x++)
    {
        for(y=0;y<=100;y++)
        {
            if(a*x+b*y==0)
            {
                printf("%d %d\n",x,y);
            }
        }
    }
    return 0;
}