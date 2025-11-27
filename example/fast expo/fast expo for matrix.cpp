#include<stdio.h>
int flag;
const int MOD =10000;
typedef struct{
    int mat[2][2];
}Matrix;//定义矩阵的类型
// typedef int Matrix [2][2];//但如果这样写是不能返回数组的，必须写成一个结构体
Matrix multiply(Matrix a,Matrix b)
{
    Matrix c;
    //c矩阵的第i行第j列
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            c.mat[i][j]=0;
            for(int k=0;k<2;k++)
            {
                c.mat[i][j]=(c.mat[i][j]+a.mat[i][k]*b.mat[k][j])%MOD;
            }
        }
    }
    return c;
}
// void Fib(int i,int n,long long a11,long long a12,long long a21,long long a22)
// {
//     if(i==n-1)
//     {
//         flag=1;
//         printf("%d",)
//     }
// }
//矩阵快速幂函数
Matrix power(Matrix a,int n)//底数a（一直用于相乘的矩阵
{
    Matrix res;//单位元，这里是单位矩阵
    res.mat[0][0]=1;
    res.mat[0][1]=0;
    res.mat[1][0]=0;
    res.mat[1][1]=1;

    while(n>0)
    {
        if(n&1)
        res=multiply(res,a);
        a=multiply(a,a);
        n>>=1;
    }
    return res;
}
int main()
{
    int n;
    scanf("%d",&n);
    Matrix base;
    base.mat[0][0]=1;
    base.mat[0][1]=1;
    base.mat[1][0]=1;
    base.mat[1][1]=0;
    Matrix ans=power(base,n);
    printf("%d",ans.mat[1][0]);
    return 0;
}