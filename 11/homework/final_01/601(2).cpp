#include<stdio.h>
int room[1004][1004];
// int used[1004][1004];
int arrange(int x,int y,int n,int m)
{
    //依然是从左到右，从上到下扫描
    int i,j;
    if(x>=n)
    {
        return 0;
    }
    //列号超出：进入下一行
    if(y>=m)
    {
        return arrange(x+1,0,n,m);
    }
    //和分配书籍不一样：这里是安排座位，一行不止一个
    // for(i=0;i<n;i++)
    // {
    //     for(j=0;j<m;j++)
    //     {

    //     }
    // }
    if(room[x][y]==1)
    {
        return arrange(x,y+1,n,m);
    }
    if(y>0&&room[x][y-1]==2)
    {
        return arrange(x,y+1,n,m);
    }
    if(x>0&&room[x-1][y]==2)
    {
        return arrange(x,y+1,n,m);
    }
    room[x][y]=2;
    return arrange(x,y+1,n,m)+1;
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
    }
    int max=arrange(0,0,n,m);
    printf("%d",max);
    return 0;
}