#include<stdio.h>
//贪心算法:利用扫描顺序是从左到右，从上到下
int room[1005][1005];
// int used[1005][1005];
int count;
//！注意是标记2而不是1（过道旁边也能坐人）
void calculate(int n,int m)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(room[i][j]==1)
            continue;
            if(j>0&&room[i][j-1]==2)
            continue;
            if(i>0&&room[i-1][j]==2)
            continue;

            room[i][j]=2;
            count++;
        }
    }
    printf("%d",count);
    return;
}
int main()
{
    int n,m;
    int i,j;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&room[i][j]);
        }
        //记录过道列
        // if(room[i][j]==1)
        // {
        //     for(j=0;j<m;j++)
        //     {
        //         used[n][j]=1;
        //     }
        // }
    }
    calculate(n,m);
    return 0;
}