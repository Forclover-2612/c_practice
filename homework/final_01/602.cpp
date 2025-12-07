#include <stdio.h>
#include<stdbool.h>
//TLE优化三处
int primes[200];
bool is_prime[1005];//使用标记数组
int prime_count;
int count;
int isPrime(int n)
{
    for (int j = 2; j * j <= n; j++)
    {
        if (n % j == 0)
            return 1;
    }
    return 0;
}
//优化：用埃拉筛
void get_prime()
{
    // int i, j;
    // for (i = 2; i <= 1000; i++)
    // {
    //     if (!isPrime(i))
    //         primes[prime_count++] = i;
    // }
    for(int i=0;i<=1000;i++)
    {
        is_prime[i]=true;
    }
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i*i<=1000;i++)
    {
        if(is_prime[i])
        {
            // primes[prime_count++]=i;
            //注意：一定是标记完再添加！！！
            for(int j=i*i;j<=1000;j+=i)
            {
                is_prime[j]=false;
            }
        }
    }
    for(int i=2;i<=1000;i++)
    {
        if(is_prime[i])
        {
            primes[prime_count++]=i;
        }
    }
}
//注意：是3个不同元素
//改完之后，还是不能保证第3个数大于第2个数
void calculate(int n, int num, int remain, int latter)
// n代表已经列举的数字个数,remain是拆解剩余的和，latter是上一个数字的下标+1(作为起始)
{
    int i, j;
    if (n == 2)
    {
        // if (!isPrime(remain) && remain <= 1000)
        // //&&remain>primes[latter-1]
        // {
        //     count++;
        // }
        //直接查表判断
        if(remain>primes[latter-1]&&remain<=1000&&is_prime[remain])
        {
            count++;
        }
        return;
    }
    for (i = latter; i < prime_count; i++)
    {
        // if (primes[i] > remain / 2)
        // if(primes[i]*2>=remain)//保证严格递增
        // {
        //     return;
        // }
        //对n==0的情况也进行剪枝
        if(primes[i]*(3-n)>=remain)
        {
            return;
        }
        calculate(n + 1, num, remain - primes[i], i+1);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int ni;
    get_prime();
    for (int i = 0; i < n; i++)
    {
        count = 0;
        scanf("%d", &ni);
        calculate(0, ni, ni, 0);
        printf("%d ", count);
    }
    return 0;
}