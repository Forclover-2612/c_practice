#include <stdio.h>
#include<iostream>
#include <algorithm>
#define MAX_n 10
#define MAX_weight 100
int dp[MAX_n][MAX_weight];
// 只看前i个物品，背包容量为w的时候，能拿到的最大价值
int main()
{
    int n = 3;
    int w;
    int goods[4][2]; // weight&&value
    // int used[5]={0};
    // 0/1背包问题：动态规划
    scanf("%d", &w);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &goods[i][0], &goods[i][1]);
    }
    //不会写啊啊啊！！
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= i; j++)
    //     {
    //         // dp[j][w] = std::max(dp[j - 1][w], goods[j][1]+dp[j-1][w-goods[j][0]]); 
    //         dp[j][w]=dp[j-1][w];
    //         if(used[j]==0&&goods[j][1]+dp[i-1][w-goods[j][0]]>dp[j][w])
    //         {
    //             dp[j][w]=goods[j][1]+dp[i-1][w-goods[j][0]];
    //             used[j]=1;
    //         }
    //         if (w == 0) break;
    //     }
    //     for(int j=1;j<=n;j++)
    //     {
    //         used[j]=0;
    //     }
    // }
    for(int i=1;i<=n;i++)
    {
        //一定要把小容量的先算出来
        int current_weight=goods[i][0];
        int current_value=goods[i][1];
        for(int j=0;j<=w;j++)
        {
            if(j<current_weight)
            {
                dp[i][j]=dp[i-1][j];
            }
            else{
                int not_take=dp[i-1][j];
                int take=current_value+dp[i-1][j-current_weight];
                dp[i][j]=std::max(not_take,take);
            }
        }
    }
    printf("%d",dp[n][w]);
    return 0;
}