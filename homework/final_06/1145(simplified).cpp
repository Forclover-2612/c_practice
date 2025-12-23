// [1145.cpp](http://_vscodecontentref_/18)#include <stdio.h>
#include<stdio.h>
#include <math.h> // 需要引入 math.h 使用 fabs

struct Point
{
    int x;
    int y;
};
//数据量比较小，可以直接暴力枚举
int main()
{
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    struct Point points[305];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    // 如果点数少于2个，直接处理
    if (n < 2) {
        return 0; 
    }

    int max_points = 0;
    // 记录构成最佳直线的两个点的下标，用于输出
    int best_p1 = 0; 
    int best_p2 = 1;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // 优化：如果当前已找到的最优解比剩余可能的所有点都多，可以剪枝
            // 但为了逻辑安全，建议先不加，或者只在 i 循环层级加：
            // if (max_points >= n - i) break; 

            int current_count = 0;
            
            // 处理垂直线
            if (points[i].x == points[j].x)
            {
                for (int r = 0; r < n; r++)
                {
                    if (points[r].x == points[i].x)
                    {
                        current_count++;
                    }
                }
            }
            else
            {
                // 1. 修复整数除法
                double k = (double)(points[i].y - points[j].y) / (points[i].x - points[j].x);
                double b = points[i].y - k * points[i].x;

                for (int r = 0; r < n; r++)
                {
                    // 2. 修复点在直线上的判断公式和绝对值
                    if (fabs(points[r].y - (k * points[r].x + b)) < 1e-6)
                    {
                        current_count++;
                    }
                }
            }

            if (current_count > max_points)
            {
                max_points = current_count;
                best_p1 = i;
                best_p2 = j;
            }
        }
    }

    // 输出结果
    // 注意：题目可能要求输出具体的点坐标或者下标，这里按你原代码意图输出下标对应的点
    // 但原代码逻辑是输出 memo 中的前两个点。
    // 如果题目要求输出构成直线的任意两个点，这里输出 i 和 j 即可。
    // 如果题目要求输出所有在直线上的点，需要重新遍历一次。
    
    // 假设只需输出确定该直线的两个基准点（题目通常要求）：
    printf("%d %d", best_p1, best_p2); 
    // 或者如果是输出坐标：
    // printf("%d %d %d %d\n", points[best_p1].x, points[best_p1].y,points[best_p2].x, points[best_p2].y)
    return 0;
}