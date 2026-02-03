#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include<limits.h>
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};
int min_cost[22][22];
int map[22][22];
int used[22][22];
int N,M;
void dfs(int x, int y, int curr_cost)
{
    //剪枝
    if (curr_cost >= min_cost[x][y])
    {
        return;
    }
    min_cost[x][y]=curr_cost;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= N || ny >= M || nx < 0 || ny < 0)
            continue;
        
        if(curr_cost+map[nx][ny]<min_cost[nx][ny])
        {
            dfs(nx,ny,curr_cost+map[nx][ny]);
        }
    }
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    N=n,M=m;
    for (int i = 0; i < 22; i++)
    {
        memset(min_cost[i],10,sizeof(min_cost[i]));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    dfs(0,0,map[0][0]);
    printf("%d",min_cost[n-1][m-1]);
    return 0;
}