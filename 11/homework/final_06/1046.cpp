#include<stdio.h>
struct Point{
    int x;
    int y;
};
Point map[12][12];
int used[12][12];
int flag=0;
//储存坐标
int points[144][2];
int count;
//设置了成环的判断？
int search(int xx,int yy,int n)
{
    if(xx==n-1&&yy==n-1)
    {
        points[count][0]=xx;
        points[count][1]=yy;
        count++;
        return 1;
    }
    if(xx==-1&&yy==-1)
    {
        flag=1;
        return 0;
    }
    if(used[xx][yy]==1)
    {
        flag=1;
        return 0;
    }
    int nx=map[xx][yy].x;
    int ny=map[xx][yy].y;
    //不要操作nx、ny
    used[xx][yy]=1;
    int res=search(nx,ny,n);
    if(res==1)
    {
        // printf("%d %d\n",xx,yy);
        points[count][0]=xx;
        points[count][1]=yy;
        count++;
        return 1;
    }
    return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&map[i][j].x);
            scanf("%d",&map[i][j].y);
        }
    }
    // used[0][0]=1;
    search(0,0,n);
    if(flag==1)
    {
        printf("no\n");
    }
    else{
        for(int i=count-1;i>=0;i--)
        {
            printf("%d %d\n",points[i][0],points[i][1]);
        }
    }
    return 0;
}