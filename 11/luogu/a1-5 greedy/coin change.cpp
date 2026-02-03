#include <stdio.h>
// 注意：当零钱为倍数时才能使用贪心算法
// 否则应该使用动态规划
int coin[] = {4,3,1};
#define coin_n 3
int dp[1000];
int dp_count[1000];
//如果考虑凑不出来的情况……
#define INF 99999
void dpCoin(int n)
{
    //dp[j]=min(dp[j]-coin[i]])(coin[i]<=j)
    for(int k=1;k<=n;k++)
    {
        dp[k]=INF;
    }
    //填表
    // for(int i=1;i<=n;i++)
    // {
    //     int min=dp[i-1]+1;
    //     for(int j=coin_n-1;j>=0;j--)
    //     {
    //         if(coin[j]>i)
    //         break;
    //         //如果不是从小到大的情况……
    //         if(dp[i-coin[j]]+1<min)
    //         {
    //             min=dp[i-coin[j]]+1;
    //         }
    //     }
    //     dp[i]=min;
    // }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<coin_n;j++)
        {
            if(coin[j]<=i)
            {
                //如果之前的状态有解，才能转移
                if(dp[i-coin[j]]!=INF)
                {
                    if(dp[i-coin[j]]+1<dp[i])
                    {
                        dp[i]=dp[i-coin[j]]+1;
                    }
                }
            }
        }
    }
}
int main()
{
    int n, sum = 0;
    scanf("%d", &n);
    int count[coin_n] = {0};
    // for (int i = 0; i < coin_n; i++)
    // {
    //     if (sum == n)
    //         break;
    //     while (sum + coin[i] <= n)
    //     {
    //         count[i]++;
    //         sum += coin[i];
    //     }
    // }
    // for (int i = 0; i < coin_n; i++)
    // {
    //     printf("%d ", count[i]);
    // }
    dpCoin(n);
    // printf("%d",dp[n]);
    if(dp[n]==INF)
    {
        printf("无法凑出\n");
    }
    else{
        printf("%d\n",dp[n]);
    }
    return 0;
}