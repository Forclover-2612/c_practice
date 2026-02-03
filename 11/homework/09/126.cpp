#include <stdio.h>

//定义一个极小值，代表此路不通
//如果走到死胡同，就返回这个值，告诉上层不要走这边
#define INF -10000000
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
//倒着想：为了求当前最大，必须知道后面的最大
int found_int(int x,int y,int n,int m)
{
    if(x==n&&y==m)
    {
        return arr[x][y];
    }
    int max_from_child=INF;//记录三个方向中，最好的结果
    int can_reach=0;//标记：是否至少有一个方向能通往终点

    for(int i=0;i<3;i++)
    {
        int new_x=x+dx[i];
        int new_y=y+dy[i];

        if (new_x <= n && new_x >= 1 && new_y <= m && new_y >= 1 && used[new_x][new_y] == 0)
        {
            used[new_x][new_y]=1;
            //去找到下层的回报
            int sub_res=found_int(new_x,new_y,n,m);
            // 【关键点理解 更新最大值】
            // 如果 sub_res 是 INF，说明那边是死路，不用管。
            // 如果 sub_res > max_from_child，说明找到了更赚钱的路，赶紧更新。
            if(sub_res!=INF)
            {
                can_reach=1;
                if(sub_res>max_from_child)
                {
                    max_from_child=sub_res;
                }
            }
            used[new_x][new_y]=0;
        }
    }

    if(can_reach==0)
    {
        return INF;
    }
    return  arr[x][y]+max_from_child;
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