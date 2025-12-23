#include<stdio.h>
int map[8][8];
int used[8][8];
int max_joy[8][8];
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
int R,C;
int joy=0;
void route(int x,int y,int sum)
{
    if(sum>joy)
    joy=sum;
    //停止：旁边的格子都小于等于0//错误的
    //可行性的判断
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0||ny<0||nx>=R||ny>=C)
        continue;
        if(used[nx][ny]==1)
        continue;
        //允许负数
        // if(map[nx][ny]<0)
        // continue;
        //如果正的，才继续往下走？
        used[nx][ny]=1;
        route(nx,ny,sum+map[nx][ny]);
        used[nx][ny]=0;
    }
    //没有继续递归了
    //还有逻辑错误
    // if(sum>joy)
    // {
    //     joy=sum;
    // }
    //要在开头马上更新
}
int main()
{
    int r,c;
    scanf("%d %d",&r,&c);
    R=r,C=c;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&map[i][j]);
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            //先加上当前的数字
            used[i][j]=1;
            route(i,j,map[i][j]);
            used[i][j]=0;
        }
    }
    printf("%d",joy);
}