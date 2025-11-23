#include<stdio.h>
int arr[10][10];
int used[10][10];
int flag;
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
void route(int x,int y,int m,int n)
{
    int i,j;
    if(x==m&&y==n)
    {
        flag=1;
        return;
    }
    if(flag)
    return;
    for(i=0;i<4;i++)
    {
        int new_x=x+dx[i];
        int new_y=y+dy[i];
        if(new_x<=m&&new_y<=n&&new_x>=1&&new_y>=1&&used[new_y][new_x]==0&&arr[new_y][new_x]==1)
        {
            used[new_y][new_x]=1;
            route(new_x,new_y,m,n);
            used[new_y][new_x]=0;
        }
    }
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    used[1][1]=1;
    route(1,1,m,n);
    if(flag)
    printf("YES");
    else
    printf("NO");
    return 0;
}