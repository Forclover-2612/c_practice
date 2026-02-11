#include<stdio.h>
#include<algorithm>
int price[2005];
long long dp[2005][2005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&price[i]);
    }
    // int temp[2005];
    for(int len=1;len<=n;len++)
    {
        //枚举左端点
        for(int left=1;left<=n-len+1;left++)
        {
            //算出右端点
            int right=left+len-1;
            //算出是第几天卖出的食物
            int age=n-len+1;

            //状态转移
            long long pick_left=(long long)price[left]*age+dp[left+1][right];
            long long pick_right=(long long)price[right]*age+dp[left][right-1];

            dp[left][right]=std::max(pick_left,pick_right);
        }
    }
    printf("%lld",dp[1][n]);
    return 0;
}