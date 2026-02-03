#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 先判断：使用int，不需要used
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};
int map[102][102];
int memo[102][102];
int R, C;
int dfs(int x, int y)
{
    if (memo[x][y] != -1)
        return memo[x][y];
    // 注意递归起点的初始化
    memo[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= R || ny >= C || nx < 0 || ny < 0)
            continue;
        if (map[nx][ny] >= map[x][y])
            continue;
        int route = dfs(nx, ny) + 1;
        if (route > memo[x][y])
        {
            memo[x][y] = route;
        }
    }
    return memo[x][y];
}
int main()
{
    int r, c;
    scanf("%d %d", &r, &c);
    R = r, C = c;
    for (int i = 0; i < 102; i++)
    {
        // memset(memo[i],-1,102);不是元素个数
        memset(memo[i], -1, sizeof(memo[i]));
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    int max = 1;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            dfs(i, j);
            if (max < memo[i][j])
                max = memo[i][j];
        }
    }
    printf("%d", max);
    return 0;
}