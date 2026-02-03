#include<stdio.h>
#include<stdlib.h>
#include<string.h>
bool is_primes[1000000];
void generate_primes()
{
    memset(is_primes,1,sizeof(is_primes));
    is_primes[0]=is_primes[1]=false;
    for(int i=2;i*i<=1000000;i++)
    {
        if(is_primes[i])
        {
            for(int j=i*i;j<=1000000;j+=i)
            {
                is_primes[j]=false;
            }
        }
    }
}
int main()
{
    generate_primes();
    //分析：最小和最大：从最小的数开始判断
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int num;
        int count=0;
        int n1,n2;
        scanf("%d",&num);
        for(int j=2;j<=num/2;j++)
        {
            //输出找到的第一个组合和最后一个组合
            if(is_primes[j]&&is_primes[num-j])
            {
                n1=j;
                n2=num-j;
                count++;
                break;
            }
            //输出第一个组合
        }
        printf("%d+%d ",n1,n2);
        for(int j=n1+1;j<=num/2;j++)
        {
            //输出找到的第一个组合和最后一个组合
            if(is_primes[j]&&is_primes[num-j])
            {
                n1=j;
                n2=num-j;
                count++;
            }
            //输出第一个组合
        }
        printf("%d+%d ",n1,n2);
        printf("%d\n",count);
    }
    return 0;
}