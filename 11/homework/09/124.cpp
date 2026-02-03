#include <stdio.h>
#include <algorithm>
int height[55][55];
int memo[55][55]; // 路径计算：记忆化
int used[55][55];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};
int r, c;
int max = -1;
void route(int x, int y, int length);
int route_better(int x, int y);
int main()
{
    // int r, c;
    scanf("%d %d", &r, &c);
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            scanf("%d", &height[i][j]);
        }
    }
    int ans = 0;
    // 标记一周
    // 更好的做法：直接进行边界判断
    // for (int i = 0; i <= r + 1; i++)
    // {
    //     used[i][0] = 1;
    //     used[i][c + 1] = 1;
    // }
    // for (int i = 1; i <= c; i++)
    // {
    //     used[0][i] = 1;
    //     used[r + 1][i] = 1;
    // }
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            // route(i,j,1);
            // route_better(x,y);
            // 可以用类似的写法
            ans=std::max(ans,route_better(i,j));
        }
    }
    // printf("%d", max);
    printf("%d",ans);
    return 0;
}
int route_better(int x, int y)
{
    if (memo[x][y] != 0)
    {
        return memo[x][y];
    }
    int max_len = 1;
    for (int i = 0; i < 4; i++)
    {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if (new_x >= 1 && new_y >= 1 && new_x <= r && new_y <= c)
        {
            if (height[new_x][new_y] < height[x][y])
            {
                // 递归调用自己：我能走的最远距离 = “我邻居能走的最远距离” + 1（我自己这一步）
                //能滑到new_x,new_y
                max_len = std::max(max_len, route_better(new_x, new_y) + 1); // 函数是整型类型才能比较
                // max_len不断更新，只保留最长的结果
            }
        }
    }
    // 存入结果并返回
    memo[x][y] = max_len;
    return max_len;
}
// void route(int x, int y, int length)
// {
//     int i;
//     int flag = 0;
//     for (i = 0; i < 4; i++)
//     {
//         int new_x = x + dx[i];
//         int new_y = y + dy[i];
//         if (used[new_x][new_y] == 0 && height[new_x][new_y] < height[x][y])
//         {
//             flag = 1;
//             break;
//         }
//     }
//     if (!flag)
//     {
//         if (length > max)
//         {
//             max = length;
//         }
//         return;
//     }
//     else
//     {
//         for (i = 0; i < 4; i++)
//         {
//             int new_x = x + dx[i];
//             int new_y = y + dy[i];
//             if (used[new_x][new_y] == 0 && height[new_x][new_y] < height[x][y])
//             {
//                 used[new_x][new_y] = 1;
//                 route(new_x, new_y, length + 1);
//                 used[new_x][new_y] = 0;
//             }
//         }
//     }
// }