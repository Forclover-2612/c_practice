#include <stdio.h>
#include <math.h>
struct Point
{
    int x;
    int y;
};
struct Pass
{
    double k;
    double b;
    int total_points[300];
    int total;
};
struct Pass memo[50000];

int main()
{
    int n;
    scanf("%d", &n);
    // int points[305][2];
    struct Point points[305];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &points[i].x, &points[i].y);
    }
    int count = 0;
    int max_points = 0;
    // int flag_break = 0;
    // 剪枝：要内层剪枝和外层剪枝
    for (int i = 0; i < n - 1; i++)
    {
        if (n - i <= max_points)
            break;
        for (int j = i + 1; j < n; j++)
        {
            if (n - j < max_points) // 不用继续再循环了，穿过点的数量一定小于前面的组合
            {
                // flag_break = 1;
                break;
            }
            double k, b;
            int flag = 0;
            int total_count = 2;
            // 逻辑漏洞：对斜率不存在的直线都统一处理，可以被视为一条直线
            if (points[i].x == points[j].x)
            {
                // k=0;
                // b=points[i].x;
                k = 1e9;
                b = points[i].x;
                // 检查是否重复
                for (int t = 0; t < count; t++)
                {
                    if (memo[t].k > 1e8 && fabs(b - memo[t].b) < 1e-6)
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag)
                    continue;
                memo[count].b = b;
                memo[count].k = k;
                memo[count].total_points[0] = i;
                memo[count].total_points[1] = j;
                for (int r = j + 1; r < n; r++)
                {
                    if (points[r].x == points[i].x)
                    {
                        memo[count].total_points[total_count] = r;
                        total_count++;
                    }
                }
                memo[count].total = total_count;
                count++;

                if (total_count > max_points)
                    max_points = total_count;
                // break;
                continue;
            }
            // 注意要转换成double
            k = (double)(points[i].y - points[j].y) / (points[i].x - points[j].x);
            b = points[i].y - k * points[i].x;
            for (int t = 0; t < count; t++)
            {
                // 必须取绝对值
                if (memo[t].k < 1e8 && fabs(k - memo[t].k) < 1e-6 && fabs(b - memo[t].b) < 1e-6)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag)
                continue;
            memo[count].b = b;
            memo[count].k = k;
            // 先把这两个点加入点集中
            memo[count].total_points[0] = i;
            memo[count].total_points[1] = j;
            for (int r = j + 1; r < n; r++)
            {
                if (fabs(points[r].y - k * points[r].x - b) < 1e-5)
                {
                    memo[count].total_points[total_count] = r;
                    total_count++;
                }
            }
            memo[count].total = total_count;
            count++;

            if (total_count > max_points)
                max_points = total_count;
        }
        // if (flag_break)
        //     break;
    }
    int sort[1000][300];
    int need_to_sort = 0;
    // 排序
    // 有必要吗
    for (int i = 0; i < count; i++)
    {
        if (memo[i].total == max_points)
        {
            // for(int j=0;j<max_points;j++)
            // {
            // sort[need_to_sort][j]=memo[i].total_points[j];
            printf("%d %d", memo[i].total_points[0], memo[i].total_points[1]);
            break;
            // }
            // need_to_sort++;
        }
    }
    // for(int i=0;i<need_to_sort;i++)
    // {
    //     int min=0;
    //     for(int j=i+1;j<need_to_sort;j++)
    //     {
    //         if()
    //     }
    // }
    return 0;
}