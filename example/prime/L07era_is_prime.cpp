#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>
// bool prime[200]={true};

void is_prime(int n)
{
    if(n<2)
    {
        printf("输入错误");
        return;
    }
    //动态内存分配，下标对应相应的数字（n+1）
    int *isPrime=(int*)malloc((n+1)*sizeof(int));
    //bool数组
    // bool*isPrime=(bool*)malloc((n+1)*sizeof(bool));
    // memset(isPrime,1,(n+1)*sizeof(int));
    if(isPrime==NULL)//ii先检查内存分配
    {
        printf("内存分配失败");
        return;
    }
    //初始化数组
    for(int i=2;i<=n;i++)
    {
        isPrime[i]=1;
    }
    for(int i=2;i*i<=n;i++)//合数有一个<=平方根的质因数
    {
        if(isPrime[i]==1)//i是素数，标记倍数为合数
        {
            //从i*i开始标记（之前的数还有更小的质因数）
            for(int j=i*i;j<=n;j+=i)
            {
                isPrime[j]=0;
            }
        }
    }
    //输出素数
    for(int i=2;i<=n;i++)
    {
        if(isPrime[i]==1)
        {
            printf("%d ",i);
        }
    }
    //手动释放内存
    free(isPrime);
}

int main()
{
    int n;
    scanf("%d",&n);
    is_prime(n);
    return 0;
}