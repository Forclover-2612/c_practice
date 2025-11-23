#include <stdio.h>
int dy[3] = {0, -1, 1};
int dx[3] = {1, 0, 0};
int arr[10][10];
int used[10][10];
int max = -100000;
void found(int x, int y, int n, int m, int sum)
{
    int i, j;
    if (x == n && y == m)
    {
        if (sum > max)
        {
            max = sum;
        }
        return;
    }
    for (i = 0; i < 3; i++)
    {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if (new_x <= n && new_x >= 1 && new_y <= m && new_y >= 1 && used[new_x][new_y] == 0)
        {
            used[new_x][new_y] = 1;
            found(new_x, new_y, n, m, sum + arr[new_x][new_y]);
            used[new_x][new_y] = 0;
        }
    }
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    used[1][1]=1;//注意起点！！！
    found(1, 1, n, m, arr[1][1]);
    printf("%d", max);
    return 0;
}