#include<stdio.h>

const int MAXN = 105;
int arr[MAXN][MAXN];
int memo[MAXN][MAXN]; // 【1. 备忘录数组】
int n, m;
int dx[] = {0, 1}; // 假设只能向右和向下，防止死循环
int dy[] = {1, 0};
int found_memo(int x,int y)
{
    //第一步：查备忘录
    if(memo[x][y]!=-1)
    {
        return memo[x][y];
    }
    if(x==n&&y==m)
    {
        return arr[x][y];
    }
    //第二步：正常计算
    int current_max=-1e9;
    for(int i=0;i<2;i++)
    {
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        // 边界检查
        if (new_x <= n && new_x >= 1 && new_y <= m && new_y >= 1)
        {
            int sub=found_memo(new_x,new_y);
            if(sub!=-1e9)
            {
                //求最大路径
                if(current_max<sub)
                current_max=sub;
            }
        }
    }
    //这一步一定要进行记忆化
    if(current_max==-1e9)
    {
        return memo[x][y]=-1e9;
    }
    return memo[x][y]=arr[x][y]+current_max;
}
int main()
{

    return 0;
}