#include <stdio.h>

void record(int ma[][30], int n, int m)
{
    ma[n][m] = 1;
    ma[n - 1][m - 2] = 1;
    ma[n - 2][m - 1] = 1;
    ma[n - 2][m + 1] = 1;
    ma[n - 1][m + 2] = 1;
    ma[n + 1][m + 2] = 1;
    ma[n + 2][m + 1] = 1;
    ma[n + 2][m - 1] = 1;
    ma[n + 1][m - 2] = 1;
}

int main()
{
    int b1, b2, m1, m2;
    scanf("%d %d %d %d", &b1, &b2, &m1, &m2);
    int ma[30][30] = {0};
    long long route[30][30]={0};
    // 分析：两个方向;
    // 在马的周围先标记
    // 越界问题怎么解决？
    record(ma, m1, m2);
    // route[1][0]=1;
    // route[0][1]=1;
    // 边界数值太多了
    //bug：对被标记的点的路径数量没有初始化
    for (int i = 0; i <= b1; i++)
    {
        for (int j = 0; j <= b2; j++)
        {
            if (ma[i][j] == 0)
            {
                if (i - 1 < 0 && j - 1 < 0)
                    route[i][j] = 1;
                else if (i - 1 < 0)
                    route[i][j] = route[i][j - 1];
                else if (j - 1 < 0)
                    route[i][j] = route[i - 1][j];
                else
                    route[i][j] = route[i - 1][j] + route[i][j - 1];
            }
        }
    }
    printf("%lld", route[b1][b2]);
    return 0;
}