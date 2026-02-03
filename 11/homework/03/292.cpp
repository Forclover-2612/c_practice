#include<stdio.h>
#include<math.h>

int main()
{
    double x,t,y;
    scanf("%lf",&x);
    if(fabs(x)<=1)
    {
        t=fabs(x-1)-2;
    }
    else
    {
        t=1.0/(1+x*x);
    }
    if(fabs(t)<=1)
    {
        y=fabs(t-1)-2;
    }
    else
    {
        y=1.0/(1+t*t);
    }
    printf("%.2lf",y);
    return 0;
}