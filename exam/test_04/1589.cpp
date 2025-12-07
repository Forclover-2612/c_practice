#include <stdio.h>
#include <algorithm>
int arr[2000][2000];
int memo[2000][2000];
int visited[2000][2000]; // 标记是否走过
bool is_cycle;
// 逻辑有问题，照着void函数写的
// 如果这是一个“根据箭头指示走”的问题（通常称为“模拟”或“带记忆化的搜索”），那么每个格子只有一个确定的后继。
// 目前的 visited 数组在递归返回时重置为 0，这在有环的情况下会导致无限递归（栈溢出）。
// 对于这种确定性路径，通常需要检测环，或者利用记忆化数组 memo 来避免重复计算。
int route(int x, int y, int m, int n)
{
    if (x >= m || y >= n || x < 0 || y < 0)
    {
        return 0;
    }
    if (memo[y][x] != 0)
    {
        return memo[y][x];
    }
//修复建议
//你需要引入一个机制：如果当前路径是因为撞到 visited 而结束（即遇到了环），则不要保存 memo。
//这样下次从别的点进入这个环时，会重新计算正确的长度。
    // 成环的判断
    if (visited[y][x] == 1)
    {
        is_cycle=true;
        return 0;
    }
    visited[y][x] = 1;
    int len = 1;
    // 注意和滑雪类题目的区别
    if (arr[y][x] == 1)
    {
        // len=std::max(len,route(x-1,y,m,n)+1);
        len += route(x - 1, y, m, n);
    }
    else if (arr[y][x] == 2)
    {
        // len=std::max(len,route(x+1,y,m,n)+1);
        len += route(x + 1, y, m, n);
    }
    else if (arr[y][x] == 3)
    {
        // len=std::max(len,route(x,y-1,m,n)+1);
        len += route(x, y - 1, m, n);
    }
    else if (arr[y][x] == 4)
    {
        // len=std::max(len,route(x,y+1,m,n)+1);
        len += route(x, y + 1, m, n);
    }
    // 只有当路径没有遇到环时，才进行记忆化
    // 如果遇到了环，说明这个 len 是受起点影响的“截断值”，不能通用，所以不存
    // memo[y][x] = len;
    if(!is_cycle)
    memo[y][x]=len;
    visited[y][x] = 0;
    return len;
}
int main()
{
    int i, j;
    int m, n;
    int bestroute = 0;
    int ans[100][2];
    int count = 0;
    scanf("%d %d", &m, &n); // m列n行的矩阵
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            is_cycle=false;//每次都回到false
            int res = route(i, j, m, n); // 第i列第j行
            if (res > bestroute)
            {
                count = 0;
                ans[count][0] = i;
                ans[count][1] = j;
                bestroute = res;
                count = 1;
            }
            else if (res == bestroute)
            {
                ans[count][0] = i;
                ans[count][1] = j;
                count++;
            }
        }
    }
    for (i = 0; i < count; i++)
    {
        printf("%d %d\n", ans[i][0], ans[i][1]);
    }
    return 0;
}
// int route(int x, int y, int m, int n, int length)
// {
//     if (x >= m || y >= n || x < 0 || y < 0)
//     {
//         return length;
//     }
//     if (arr[y][x] == 1)
//     {
//         return route(x - 1, y, m, n, length + 1);
//         if(x>0)
//         visited[y][x-1]=1;
//     }
//     else if (arr[y][x] == 2)
//     {
//         return route(x + 1, y, m, n, length + 1);
//     }
//     else if (arr[y][x] == 3)
//     {
//         return route(x, y - 1, m, n, length + 1);
//     }
//     else if (arr[y][x] == 4)
//     {
//         return route(x, y + 1, m, n, length + 1);
//     }
//     return 0;
// }
//路径唯一，可以不用递归回溯
//环上所有格子的食物数量和起点是一致的