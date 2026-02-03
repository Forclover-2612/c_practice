#include <stdio.h>
#include <string.h>
#include<stdlib.h>
long long arr[1000000]; // 记录结果
// int used[15];
int Total;
//逻辑错误：每次都是在原来的和的基础上加上新的数字，即不能把Total和arr[i]一直累加
void plus(int n, char str[], int num, int idx,long long current_sum) // 传入：加号的数量，实际添置的加号数量，（需要上一个加号的位置吗
{
    int j, k;
    int len = strlen(str);
    // 注意：最后一段数字也要累加
    if (num == n)
    {
        // 储存结果
        long long res = 0;
        for (k = idx; k < len; k++)
        {
            res = res * 10 + str[k] - '0';
        }
        arr[Total++] += res+current_sum;
        return;
    }
    // 思路：先确定第一个加号的位置？
    // 可放置加号的间隔有strlen(str)-1个
    long long res=0;
    for (j = idx; j < len - n + num; j++)
    {
        res = res * 10 + str[j] - '0';
        // arr[Total] += res;
        // num++;不要在循环里面这样写
        plus(n, str, num + 1, j + 1,current_sum+res);
    }
}
int compare_longlong(const void*a,const void *b)
{
    long long num1=*(const long long *)a;
    long long num2=*(const long long *)b;
    return num2-num1;
}
int main()
{
    int n;
    char str[16];
    scanf("%d", &n);
    scanf("%s", str);
    plus(n, str, 0, 0,0);
    // for(int i=0;i<Total;i++)
    // {
    //     printf("%lld\n",arr[i]);
    // }
    qsort(arr,Total,sizeof(long long),compare_longlong);
    printf("%lld",arr[0]);
    return 0;
}