#include<stdio.h>
#define N 8
int attack[N][N];
char queen[N][N];
// int temp[N][N];
//注意：不能是全局变量
int n=8;
int nTotal;
//此方法需要一个备份数组
void output()
{
    printf("solution %d:\n",nTotal);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%c ",queen[i][j]);
        }
        printf("\n");
    }
}
void put_queen(int x,int y,int attack[N][N])
{
    static const int dx[]={-1,0,1,1,1,0,-1,-1};
    static const int dy[]={-1,-1,-1,0,1,1,1,0};
    attack[x][y]=1;
    //距离延伸和方向遍历
    //或者先遍历8个方向，再延伸距离，超出边界后就不用延伸？
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int nx=x+i*dx[j];
            int ny=y+i*dy[j];

            if(nx>=0&&nx<n&&ny>=0&&ny<n)
            {
                attack[nx][ny]=1;
            }
        }
    }

}
//k表示当前处理的行
void backtrack(int k,int attack[][N],char queen[][N])
{
    if(k==n)
    {
        nTotal++;
        output();
        return;
    }
    //局部变量，保证（每层递归）有独立的备份
    int temp[N][N];
    for(int i=0;i<n;i++)
    {
        if(attack[k][i]==0)
        {
            for(int j=0;j<n;j++)
            {
                for(int t=0;t<n;t++)
                {
                    temp[j][t]=attack[j][t];
                }
            }
            queen[k][i]='Q';
            put_queen(k,i,attack);
            backtrack(k+1,attack,queen);
            for(int j=0;j<n;j++)
            {
                for(int t=0;t<n;t++)
                {
                    attack[j][t]=temp[j][t];
                }
            }
            queen[k][i]='*';
        }
    }
}

int main()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            queen[i][j]='*';
        }
    }
    backtrack(0,attack,queen);
    printf("%d",nTotal);
    return 0;
}