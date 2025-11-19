#include<stdio.h>

const int fx[]={0,-1,-2,-2,-1,1,2,2,1};
const int fy[]={0,-2,-1,1,2,2,1,-1,-2};
int main()
{
    //防止越界，加上2
    int i,j;
    int bx,by,mx,my;
    scanf("%d %d %d %d",&bx,&by,&mx,&my);
    bx+=2;
    by+=2;
    mx+=2;
    my+=2;
    int s[40][40]={0};
    long long f[40][40]={0};
    f[2][1]=1;//至少初始化一个，使得2,2的位置是1
    for(i=0;i<=8;i++)
    {
        s[mx+fx[i]][my+fy[i]]=1;
    }
    for(i=2;i<=bx;i++)
    {
        for(j=2;j<=by;j++)
        {
            if(s[i][j])
            continue;
            f[i][j]=f[i-1][j]+f[i][j-1];
        }
    }
    printf("%lld",f[bx][by]);
    return 0;
}