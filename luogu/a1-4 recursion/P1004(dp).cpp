#include<stdio.h>
long long f[20][20];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0&&j!=0)
            {
                // f[i][j]=f[i][j-1];
                //初始值为0，不是1
                f[i][j]=1;//所有元素已经入栈，已经生成一个合法序列
            }
            else if(j==0&&i!=0)
            {
                f[i][j]=f[i-1][j+1];//只能push
            }
            else
            {
                f[i][j]=f[i-1][j+1]+f[i][j-1];//push和pop
            }
        }
    }
    printf("%lld",f[n][0]);
    return 0;
}