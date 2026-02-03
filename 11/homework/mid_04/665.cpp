#include <stdio.h>
#include <math.h>
int calculate(int x)
{
    int i, j, t, p;
    int arr[4]={0};
    for (i = 0;i*i<=x; i++)
    {
        for (j = 0;i*i+j*j<=x; j++)
        {
            for (t = 0;i*i+j*j+t*t<=x; t++)
            {
                for (p = 0;i*i+j*j+t*t+p*p<=x; p++)
                {
                    if (p * p == x)
                    // arr[0]=1;
                    return 1;
                    if (t * t + p * p == x)
                    // arr[1]=1;
                    return 2;
                    if (p * p + j * j + t * t == x)
                    // arr[2]=1;
                    return 3;
                    if (i * i + j * j + t * t + p * p==x)
                    // arr[3]=1;
                    return 4;
                } 
            }
        }
    }
    // for(i=0;i<4;i++)
    // {
    //     if(arr[i]==1)
    //     return i+1;
    // }
    return 0;
}
int main()
{
    // 打印1到10000之内的素数表？
    int i, j;
    int prime[10000] = {0};
    int primes[2000];
    int count = 0;
    for (i = 2; i * i <= 10000; i++)
    {
        if (prime[i] == 0)
        {
            for (j = i * i; j <= 10000; j += i)
            {
                prime[j] = 1;
            }
        }
    }
    for (i = 2; i <= 10000; i++)
    {
        if (prime[i] == 0)
            primes[count++] = i;
    }
    int n;
    scanf("%d", &n);
    int min = 100000;
    int mini, minj;
    for (i = 0; i < count; i++)
    {
        for (j = i; j < count; j++)
        {
            if (primes[i] * primes[j] > n)
            {
                if (primes[i] * primes[j] < min)
                {
                    min = primes[i] * primes[j];
                    mini = primes[i];
                    minj = primes[j];
                }
                break;
            }
        }
    }
    printf("%d %d\n", mini, minj);
    // int x = primes[i] * primes[j];
    printf("%d", calculate(min));
    return 0;
}