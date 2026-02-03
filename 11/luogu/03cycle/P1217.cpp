#include <stdio.h>
#include <math.h>
//判断回文数
int palindromes(int x)
{
    int arr[10];
    int i = 0;
    // 如果是个位数
    if (x < 10)
    {
        return 1;
    }
    // if (x >= 10)//判断可省略
    // {
    while (x > 0)
    {
        arr[i] = x % 10;
        x = x / 10;
        i++;
    }
    int left = 0;
    int right = i - 1;
    while (left <= right)
    {
        if (arr[left] != arr[right])
            return 0;
        else
        {
            left++;
            right--;
        }
    }
    return 1;
    // }
}
// 出现问题：类没有分齐全
// 还有return之后的可以适当省略
//常规判断素数的写法
int prime(int x)
{
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
            return 0;
    }
    return 1;
}
//欧拉筛
void Euler(int a,int b)
{
    // 动态分配标记数组
    bool *is_prime = (bool *)malloc((b + 1) * sizeof(bool));
    // 动态分配质数列表
    int *primes = (int *)malloc(b * sizeof(int));
    // 初始化标记数组
    for (int i = 0; i <= b; i++)
    {
        is_prime[i] = true;
    }
    is_prime[0] = is_prime[1] = false;

    int cnt = 0; // 已找到的素数个数

    for (int i = 0; i <= b; i++)
    {
        if (is_prime[i])
            primes[cnt++] = i; // 是素数，加入列表
        for (int j = 0; j < cnt && primes[j] * i <= b; j++)
        // 第一个条件不会造成越界
        {
            is_prime[primes[j] * i] = 0; // 标记为合数
            // 关键优化：保证只标记一次
            if (i % primes[j] == 0) // prime[j]是i的最小质因数
            {
                break;
            }
        }
    }
    // 输出素数
    for (int i = 0; i < cnt; i++)
    {
       if(primes[i]>=a&&palindromes(primes[i])==1)
       {
        printf("%d\n",primes[i]);
       }
    }
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int i, j;
    // for (i = a; i <= b; i++)
    // {
    //     if (palindromes(i))
    //     {
    //         if (Euler(b,i))
    //         {
    //             printf("%d\n", i);
    //         }
    //     }
    // }
    Euler(a,b);
    return 0;
}