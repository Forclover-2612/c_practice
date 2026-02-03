#include<stdio.h>

int customOp(int x,int y)
{
    return x+y+x*y;
}

int customFastPower(int a,int n)
{
    int res=0;
    while(n>0)
    {
        if(n&1)
        {
            res=customOp(res,a);
        }
        a=customOp(a,a);
        n>>=1;
    }
    return res;
}
int main()
{
    printf("%d",customFastPower(1,5));
    return 0;
}