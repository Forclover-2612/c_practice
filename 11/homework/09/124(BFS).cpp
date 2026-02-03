#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
// 逆向四位：从低往高爬
// 计算“入度”（依赖数量）：

// 对于每个点 (i, j)，看看周围有几个比它矮的邻居。
// 比如，如果 (i, j) 左边和下边的邻居都比它矮，那它的入度就是 2。这意味着：要想算出 (i, j) 的最长路径，必须先算出这两个矮邻居的路径。
// 入队（寻找起点）：

// 把所有 入度为 0 的点加入队列。
// 这些点就是“山谷”，它们没法往下滑了，所以路径长度初始化为 1。
// BFS 循环（向上攀爬）：

// 从队列拿出一个点 A（当前处理好的低点）。
// 看 A 周围比它 高 的邻居 B。
// 更新 B 的长度：B 的路径长度 = max(B当前长度, A的长度 + 1)。
// 解除依赖：因为 A 已经算好了，所以 B 的入度减 1。
// 新起点：如果 B 的入度变成了 0（说明 B 周围所有比它矮的点都算好了），就把 B 加入队列。
struct Point
{
    int x, y;
};
int height[55][55];
int degree[55][55]; // 入度：记录有几个比自己矮的邻居
int dist[55][55];   // 路径长度记录
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};
int main()
{
    int r, c;
    scanf("%d %d", &r, &c);

    // 1. 输入数据并初始化
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            scanf("%d", &height[i][j]);
            dist[i][j] = 1;   // 默认长度至少为1
            degree[i][j] = 0; // 初始化入度
        }
    }

    // 2.计算每个点的入度
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx >= 1 && nx <= r && ny >= 1 && ny <= c)
                {
                    if (height[nx][ny] < height[i][j])
                    {
                        degree[i][j]++;
                    }
                }
            }
        }
    }
    // 3.将所有入度为0的点加入队列
    queue<Point> q;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (!degree[i][j])
            {
                q.push({i, j});
            }
        }
    }
    // 记录最大值
    int global_max = 1;

    while (!q.empty())
    {
        // 先读再删
        Point cur = q.front();
        q.pop();

        if (dist[cur.x][cur.y] > global_max)
            global_max = dist[cur.x][cur.y];

        for (int k = 0; k < 4; k++)
        {
            int nx = cur.x + dx[k];
            int ny = cur.y + dy[k];

            // 记得先判断边界
            if (nx >= 1 && nx <= r && ny >= 1 && ny <= c)
            {
                if (height[nx][ny] > height[cur.x][cur.y])
                {
                    //1.更新高点的路径长度，取最大值
                    dist[nx][ny]=max(dist[nx][ny],dist[cur.x][cur.y]+1);
                    //2.减少高点的入度
                    degree[nx][ny]--;
                    //3.如果高点所有的低处的邻居都处理完了，就可以入队
                    if(!degree[nx][ny])
                    {
                        q.push({nx,ny});
                    }
                }
            }
        }
    }
    printf("%d",global_max);
    return 0;
}