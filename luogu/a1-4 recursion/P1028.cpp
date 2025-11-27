#include<stdio.h>
#include<string.h>
long long count[1005];//一边递归一边储存
long long calculate(int n)//第一项的数字
{
    if(n==1)
    return 1;
    else if(count[n]>1)
    return count[n];
    for(int i=1;i<=n/2;i++)
    {
        count[n]+=calculate(i);
    }
    return count[n];
}
int main()
{
    // memset(count,1,sizeof(long long));
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        count[i]=1;
    }
    printf("%lld",calculate(n));
    return 0;
}