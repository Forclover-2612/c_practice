#include<stdio.h>
#include<string.h>

int arr[15][15];
int dp[15][15];//能到达就标记为1
//注意：如果是4个方向，必须使用DFS
//如果是两个方向（右下），才可以使用DP
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    //读取地图
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    memset(dp,0,sizeof(dp));
    dp[1][1]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(arr[i][j]==0)
            continue;

            if(i>1&&dp[i-1][j]==1)
            {
                dp[i][j]=1;
            }
            if(j>1&&dp[i][j-1]==1)
            {
                dp[i][j]=1;
            }
        }
    }
    //路径计算
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(arr[i][j]==0)
            continue;
            //如果是起点，跳过计算保持为1

            if(i>1)
            {
                dp[i][j]+=dp[i-1][j];
            }
            if(j>1)
            {
                dp[i][j]+=dp[i][j-1];
            }
        }
    }
    if(dp[n][m])printf("YES");
    return 0;
}