#include<stdio.h>

int main()
{
    //寻找最大公因数
    int a,b;
    scanf("%d/%d",&a,&b);
    int minx=(a<b)?a:b;
    int maxx=(a>b)?a:b;
    int c=1;
    for(int i=minx;i>0;i--)
    {
        if(a%i==0&&b%i==0)
        {
            c=i;
            break;
        }
    }
    printf("%d/%d",a/c,b/c);
    return 0;
}