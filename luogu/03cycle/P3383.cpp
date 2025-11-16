#include<stdio.h>
#include<string.h>
int arr[1000001];
bool isPrime[100000000];
int prime[100000000];

void Getprime(int n)//筛到n
{
    memset(isPrime,1,sizeof(isPrime));
    isPrime[0]=0;
    isPrime[1]=0;

    int cnt=0;
    for(int i=2;i<=n;i++)
    {
        if(isPrime[i])
        {
            prime[++cnt]=i;
        }
        for(int j=1;j<=cnt&&prime[j]*i<=n;j++)
        {
            isPrime[prime[j]*i]=0;
            if(i%prime[j]==0)
            break;
        }
    }
}
//出现异常：内存分配失败(内部开的数组太大了)
int main()
{
    int n,q;
    scanf("%d %d",&n,&q);
    // int arr[MAX];
    Getprime(n);
    // for(int i=0;i<q;i++)
    // {
    //     scanf("%d",&arr[i]);
    // }
    while(q--)
    {
        int k;
        scanf("%d",&k);
        printf("%d\n",prime[k]);
    }
    // Getprime(n);
    // for(int i=0;i<q;i++)
    // {
    //     printf("%d\n",prime[arr[i]]);
    // }
    return 0;
}