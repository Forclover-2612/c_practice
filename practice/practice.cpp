#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int primes[10000]={0};//0表示都是素数
    for(int i=2;i*i<=n;i++)
    {
        if(primes[i]==1)
        continue;
        else
        for(int j=i*i;j<=n;j+=i)
        {
            primes[j]=1;
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(primes[i]==0)
        printf("%d ",i);
    }
    return 0;
}