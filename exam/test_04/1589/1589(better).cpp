#include <stdio.h>
#define M 2000
#define N 2000
/*
* next[x]  从格子 x 按方向能到达的下一个格子编号（-1 表示出界）
* ans[x]
以格子 x 为起点能访问到的最多格子数（包括自己）
* vis[x]   0 = 未访问, 1 = 在栈中, 2 = 已计算完毕
* stack[]  记录当前路径上的格子
* cyc[]
记录检测到的环上的格子
*/
int next[N * M];
int ans[N * M];
int vis[N * M];
int stack[N * M];
int cyc[N * M];
int main()
{
    // m = 列数，n = 行数
    int m, n;
    scanf("%d%d", &m, &n);
    /*
   读入网格并建立有向边
   *  i 为行号（0 ~ n-1）
   *  j 为列号（0~m-1）
   */
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            // orient 代表朝向，默认出界，置 -1
            int orient;
            scanf("%d", &orient);
            next[i * m + j] = -1;
            if (orient == 1 && j > 0) // 向左
                next[i * m + j] = i * m + j - 1;
            if (orient == 2 && j < m - 1) // 向右
                next[i * m + j] = i * m + j + 1;
            if (orient == 3 && i > 0) // 向上
                next[i * m + j] = (i - 1) * m + j;
            if (orient == 4 && i < n - 1) // 向下
                next[i * m + j] = (i + 1) * m + j;
        }
    }
    // 栈顶指针
    int top = 0;
    // 对每个格子尝试出发
    for (int i = 0; i < m * n; ++i)
    {
        int x = i; // 当前正在访问的格子
        // 沿着方向一直往前走，直到出界或遇到已处理过的格子
        while (x != -1 && vis[x] == 0)
        {
            vis[x] = 1;
            // 标记为正在访问
            stack[top++] = x; // 入栈
            x = next[x];
        }
        int length; // 从 x 继续往下能访问的格子数（不含 x 自己）
        if (x == -1 || vis[x] == 2)
        {
            // 出界 或 走到已经算好的点 → 直接继承答案
            length = (x == -1 ? 0 : ans[x]);
        }
        // 走到 vis[x]==1 的点 → 发现环
        else
        {
            int now = -1;
            int cyc_size = 0;
            // 从栈顶弹出直到回到环的入口点 x，形成完整的环
            while (now != x)
            {
                now = stack[--top];
                cyc[cyc_size++] = now; // 记录环上的格子
                vis[now] = 2;
                // 环上节点标记为已完成
            }
            // 环上所有点的答案都是环的大小
            for (int j = 0; j < cyc_size; ++j)
            {
                ans[cyc[j]] = cyc_size;
            }
            length = cyc_size; // 环作为后续路径的“可访问数量”
        }
        // 回溯栈中剩余的链（环之前的部分），从后往前依次计算答案
        while (top)
        {
            int x = stack[--top];
            ans[x] = ++length; // 比下一步多访问 1 个格子（自己）
            vis[x] = 2;
            // 计算完毕，出栈置 2
        }
    }
    // 找出全局最大值
    int max = 0;
    for (int i = 0; i < n * m; ++i)
    {
        if (ans[i] > max)
            max = ans[i];
    }
    // 按列优先、行次序输出所有达到最大值的起点（坐标从 0 开始）
    for (int j = 0; j < m; ++j)
    {
        // 先遍历列
        for (int i = 0; i < n; ++i)
        { // 再遍历行
            if (ans[i * m + j] == max)
            {
                printf("%d %d\n", j, i); // 输出：列 行
            }
        }
    }
    return 0;
}
