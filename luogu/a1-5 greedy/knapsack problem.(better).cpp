#include <stdio.h>
#include <algorithm> // for std::max

#define MAX_W 101 // 只定义最大容量即可

// 只需要一维数组
// dp[j] 表示：容量为 j 时，当前能拿到的最大价值
int dp[MAX_W]; 

int main()
{
    int n = 3;
    int w;
    int goods[10][2]; // 0:weight, 1:value

    // 输入
    scanf("%d", &w);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &goods[i][0], &goods[i][1]);
    }

    // 初始化 dp 数组 (全部为0)
    for(int j = 0; j <= w; j++) dp[j] = 0;

    // --- 核心代码开始 ---
    
    // 外层：遍历物品 (i)
    for (int i = 1; i <= n; i++)
    {
        int weight = goods[i][0];
        int value = goods[i][1];

        // 内层：遍历容量 (j)
        // 关键点 1: 必须是从 w 到 weight (倒序！)
        // 关键点 2: 循环条件写 j >= weight，因为如果 j < weight，肯定装不下，dp[j]维持原样，不用算
        for (int j = w; j >= weight; j--)
        {
            // 状态转移方程：
            // dp[j] (新值) = max( dp[j] (旧值，相当于二维的dp[i-1][j]), 
            //                     value + dp[j - weight] (旧值，相当于二维的dp[i-1][j-weight]) )
            dp[j] = std::max(dp[j], value + dp[j - weight]);
        }
    }
    // --- 核心代码结束 ---

    printf("%d", dp[w]);
    
    return 0;
}