#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void Euler(int n)
{
    //动态分配标记数组
    bool* is_prime=(bool*)malloc((n+1)*sizeof(bool));
    //动态分配质数列表
    int* primes=(int*)malloc(n*sizeof(int));
    //初始化标记数组
    for(int i=0;i<=n;i++)
    {
        is_prime[i]=true;
    }
    is_prime[0]=is_prime[1]=false;

    int cnt=0;//已找到的素数个数

    for(int i=2;i<=n;i++)
    {
        if(is_prime[i])
        primes[cnt++]=i;//是素数，加入列表
        for(int j=0;j<cnt&&primes[j]*i<=n;j++)
        //第一个条件不会造成越界，
        {
            is_prime[primes[j]*i]=0;//标记为合数
            //关键优化：保证只标记一次
            if(i%primes[j]==0)//prime[j]是i的最小质因数
            {
                break;
            }
        }
    }
    //输出素数
    for(int i=0;i<cnt;i++)
    {
        printf("%d ",primes[i]);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    Euler(n);
    return 0;
}