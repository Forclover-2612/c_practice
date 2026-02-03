#include<stdio.h>

int main()
{
    int a=1;
    int b=1;
    int sum=0;
    int i=0;
    scanf("%d %d",&a,&b);
    // scanf("%d",&n);
    // while(a<=n)
    // {
    //     // sum+=a;
    //     a++;
    // }
    //求1到n的和
    // for(i=0;i<=n;i++)
    // {
    //     sum+=i;
    // }
    // printf("%d",sum);
    //求两个整数的最小公倍数
    int max=(a>b)?a:b;
    int min=(a<b)?a:b;
    int n=max;
    while(n%min!=0)
    {
        n+=max;
    }
    printf("%d",n);
    return 0;
}