#include <stdio.h>
#define MAXN 2005
int grid[MAXN][MAXN];
int memo[MAXN][MAXN];
// 访问状态标记
// 0：未访问 1：正在当前的路径本子里 2：已经计算完毕
int vis[MAXN][MAXN];
// 记录每一步的x和y坐标
int path_x[MAXN * MAXN];
int path_y[MAXN * MAXN]; // 最坏情况：蛇形走位
// 方向数组：0无, 1左, 2右, 3上, 4下
// 注意题目给的坐标系：向右x增加，向下y增加
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};
int main()
{
    int m, n;
    scanf("%d %d", &m, &n); // n行m列
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &grid[i][j]);
            memo[i][j] = 0;
            vis[i][j] = 0;
        }
    }

    // 遍历每一个格子，计算它们的结果
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // 如果这个点之前已经算过了，直接跳过
            if (vis[i][j] == 2)
                continue;

            int curr_x = j;   // 列
            int curr_y = i;   // 行
            int path_len = 0; // 路径本子的当前页码

            while (1)
            {
                // 第一种情况：撞墙
                if (curr_x < 0 || curr_x >= m || curr_y < 0 || curr_y >= n)
                {
                    int value = 0;
                    for (int k = path_len - 1; k >= 0; k--)
                    {
                        value++;
                        // 每次都统计并标记返回路上的结果（因为已知有终点）
                        // 而且每条路径上的点只需要一次标记
                        int px = path_x[k]; // 列
                        int py = path_y[k]; // 行
                        memo[py][px] = value;
                        vis[py][px] = 2;
                    }
                    break; // 可以直接退出
                }
                // 第二种情况：碰到老路
                if (vis[curr_y][curr_x] == 2)
                {
                    int value = memo[curr_y][curr_x];
                    for (int k = path_len - 1; k >= 0; k--)
                    {
                        value++;
                        int px = path_x[k];
                        int py = path_y[k];
                        memo[py][px] = value;
                        vis[py][px] = 2;
                    }
                    break;
                }
                // 第三种情况：遇到环
                if (vis[curr_y][curr_x] == 1)
                {
                    // 找到环的入口在哪里
                    int loop_index = -1;
                    for (int k = path_len - 1; k >= 0; k--)
                    {
                        // 找到入口
                        if (path_x[k] == curr_x && path_y[k] == curr_y)
                        {
                            loop_index = k;
                            break;
                        }
                    }
                    // 计算环的长度
                    int loop_length = path_len - loop_index;
                    // 标记环上的元素（都是环的长度）
                    for (int k = path_len - 1; k >= loop_index; k--)
                    {
                        int px = path_x[k];
                        int py = path_y[k];
                        memo[py][px] = loop_length;
                        vis[py][px] = 2;
                    }
                    int value = loop_length;
                    // 剩下的尾巴：前面没有进入环的部分
                    for (int k = loop_index - 1; k >= 0; k--)
                    {
                        value++;
                        int px = path_x[k];
                        int py = path_y[k];
                        memo[py][px] = value;
                        vis[py][px] = 2;
                    }
                    break;
                }
                // 没有遇到上述的情况（vis==0而且下标没有越界）
                // 继续走
                // 记录现在的位置
                path_x[path_len] = curr_x;
                path_y[path_len] = curr_y;
                path_len++;
                // 标记为正在访问
                vis[curr_y][curr_x] = 1;
                int map = grid[curr_y][curr_x];
                curr_x += dx[map];
                curr_y += dy[map];
            }
        }
    }
    // 计算最大值
    int max_route = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (memo[i][j] > max_route)
                max_route = memo[i][j];
        }
    }
    // 输出坐标(列/行)
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (memo[j][i] == max_route)
            {
                printf("%d %d\n", i, j);
            }
        }
    }
    return 0;
}