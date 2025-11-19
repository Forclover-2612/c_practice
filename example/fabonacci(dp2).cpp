#include<stdio.h>
//迭代法：用数组储存中间结果，从下到上计算
long long dp[10000];
long long fibBottomUp(int n)
{
    if(n==0)
    return 0;
    if(n==1)
    return 1;

    dp[0]=0;
    dp[1]=1;

    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }

    return dp[n];
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%lld",fibBottomUp(n));
    return 0;
}