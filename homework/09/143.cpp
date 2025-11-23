#include <stdio.h>
int arr[15];
int answer[15];
int flag;
int used[15];
int m;
// 权重计算
long long step(int i)
{
    if (i == 0)
        return 1;
    else
        return i * step(i - 1);
}
//注意下标和实际的对应关系
void calculate(int n)
{
    int i, j;
    arr[1] = 1;//对应C（0,n)
    for (i = 2; i <= n+1; i++)
    {
        int res = 1;
        for (j = 0; j < i-1; j++)
        {
            res = res * (n - j);
        }
        arr[i] = res / step(i-1);
    }
}
void generate(int i, int n, int sum) // 第i个数
{
    int j, k;
    int res = 0;
    if (i > n)
    {
        if (sum == m)
        {
            for (j = 1; j <= n; j++)
            {
                printf("%d ", answer[j]);
            }
            flag = 1;
        }
        return;
    }
    if (flag)
        return;
    for (j = 1; j <= n; j++)
    {
        if (used[j] == 0)
        {
            answer[i] = j;
            used[j] = 1;
            res=arr[i]*j;
            generate(i+1,n,sum+res);
            used[j]=0;
        }
    }
}
int main()
{
    int n, sum;
    scanf("%d %d", &n, &sum);
    m=sum;
    // printf("%lld",step(3));
    calculate(n - 1);
    generate(1,n,0);
    // for(int i=1;i<=n;i++)
    // {
    //     printf("%d ",arr[i]);
    // }
    return 0;
}