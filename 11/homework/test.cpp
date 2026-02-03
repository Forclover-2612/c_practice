#include<stdio.h>

int main()
{
    int x;
    scanf("%d",&x);
    int i = 1;
    double s = 1;
    if (x == 0)
        printf("1");
    else
    {
    for (i = 1; i <= x; i++)
    {
        s *= i;
    }
    printf("%lf",s);
    }
    
    return 0;
}