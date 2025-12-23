#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int map[205][205];
int land[105][2];//记录岛屿的坐标（对于原思路：不一定要严格写成矩阵形式）
int land_size=0;
int used[205][205];
int count1;
int count2;
int treasure[11][2];
int have = 0;
// 原来的写法是“在递归过程中检查下一步”，现在的写法是“在递归过程中检查当前步”。
// 后者能完美覆盖起始点，保证 treasure 数组里的坐标一个都不漏。
void search(int x, int y, int n, int m)
{
    //先记录当前点
    land[land_size][0]=x;
    land[land_size][1]=y;
    land_size++;
    // int flag = 0;
    // 1.先处理当前节点（保证起始点也能被记录到）
    if (map[x][y] == 2)
    {
        have = 1;
        treasure[count2][0] = x;
        treasure[count2][1] = y;
        count2++;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
        {
            continue;
        }
        if (used[nx][ny] || map[nx][ny] == 0)
        {
            continue;
        }
        used[nx][ny] = 1;

        // flag = 1;
        // if (map[nx][ny] == 2)
        // {
        //     have = 1;
        //     treasure[count2][0] = nx;
        //     treasure[count2][1] = ny;
        //     count2++;
        // }
        search(nx, ny, n, m);
    }
    // if (!flag)
    // {
    //     return;
    // }
    // 可以不用return，void运行到最后自然结束
}
int main()
{
    // freopen("error (5).in","r",stdin);
    int n, m;
    int energy = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    // search、
    // bug：没有判断当前是否是2，count2是否要++
    // 建议：标准DFS写法
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (used[i][j])
                continue;
            // used[i][j] = 1;
            if (map[i][j] == 1 || map[i][j] == 2)
            {
                used[i][j] = 1;
                have = 0;
                count2 = 0;
                land_size=0;
                search(i, j, n, m);
                if (have == 1)
                {
                    count1++;
                    int min=100000;
                    //错误的，是可以在岛上的任意点而不止藏宝点
                    // int max = 0;
                    // for (int t = 0; t < count2; t++)
                    // {
                    //     int temp1, temp2;
                    //     temp1 = treasure[t][0];
                    //     treasure[t][0] = treasure[0][0];
                    //     treasure[0][0] = temp1;
                    //     temp2 = treasure[t][1];
                    //     treasure[t][1] = treasure[0][1];
                    //     treasure[0][1] = temp2;
                    //     for (int r = 1; r < count2; r++)
                    //     {
                    //         int d1 = (treasure[r][0] - treasure[0][0]) * (treasure[r][0] - treasure[0][0]);
                    //         int d2 = (treasure[r][1] - treasure[0][1]) * (treasure[r][1] - treasure[0][1]);
                    //         int d = floor(sqrt(d1 * d1 + d2 * d2));
                    //         if (d > max)
                    //         {
                    //             max = d;
                    //         }
                    //     }
                    //     temp1 = treasure[t][0];
                    //     treasure[t][0] = treasure[0][0];
                    //     treasure[0][0] = temp1;
                    //     temp2 = treasure[t][1];
                    //     treasure[t][1] = treasure[0][1];
                    //     treasure[0][1] = temp2;
                    // }
                    // energy += max;
                    //遍历岛上的任何一个点为落脚点
                    //完全不用那么复杂的思路，当前点也算在里面
                    for(int t=0;t<land_size;t++)
                    {
                        int curr_x=land[t][0];
                        int curr_y=land[t][1];
                        int max=0;
                        //计算当前点到宝藏的距离
                        for(int r=0;r<count2;r++)
                        {
                            int tx=treasure[r][0];
                            int ty=treasure[r][1];
                            double d=sqrt((tx-curr_x)*(tx-curr_x)+(ty-curr_y)*(ty-curr_y));
                            int res=(int)d;
                            if(res>max)
                            max=res;
                        }
                        if(max<min)
                        min=max;
                    }
                    energy+=min;
                    
                }
            }
        }
    }
    printf("%d %d", count1,energy);
    return 0;
}