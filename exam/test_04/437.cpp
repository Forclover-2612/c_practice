#include <stdio.h>
int N;
int map[12][12];
int used[12][12];
int min_len;
int target_x, target_y;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};
void route(int x, int y, int len)
{
    if (x == target_x && y == target_y)
    {
        if (len < min_len)
        {
            min_len = len;
        }
        return;
    }
    // 剪枝
    if (len >= min_len)
        return;
    for (int i = 0; i < 4; i++)
    {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if (new_x >= 0 && new_y >= 0 && new_x < N && new_y < N && used[new_x][new_y] == 0 && map[new_x][new_y] != 1)
        {
            used[new_x][new_y] = 1;
            route(new_x, new_y, len + 1);
            used[new_x][new_y] = 0;
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    N = n;
    int pos1[2];
    int pos2[2];
    int pos3[2];
    // 第i行第j列
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &map[i][j]);
            // 先标记2和3和4的地点
            if (map[i][j] == 2)
            {
                pos1[0] = i;
                pos1[1] = j;
            }
            else if (map[i][j] == 3)
            {
                pos2[0] = i;
                pos2[1] = j;
            }
            else if (map[i][j] == 4)
            {
                pos3[0] = i;
                pos3[1] = j;
            }
        }
    }
    // 类似于迷宫的解法
    // 先从2出发
    min_len = 1000;
    used[pos1[0]][pos1[1]] = 1;
    target_x = pos2[0];
    target_y = pos2[1];
    route(pos1[0], pos1[1], 0);
    // 再初始化
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            used[i][j] = 0;
        }
    }
    int len1 = min_len;
    min_len = 1000;
    used[pos2[0]][pos2[1]] = 1;
    target_x = pos3[0];
    target_y = pos3[1];
    route(pos2[0], pos2[1], 0);
    int len2 = min_len;
    printf("%d\n", len1 + len2);
    return 0;
}