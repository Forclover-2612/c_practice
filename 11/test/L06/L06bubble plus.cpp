#include <stdio.h>

int main()
{
    int n, max, tmp,lower,upper;
    scanf("%d %d %d", &n,&lower,&upper);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    // 最大元素往后排
    for (int j = 0; j < upper-lower; j++)//j表示不需要排序的个数
    {
        for (int t = lower; t < upper - j; t++)
        {
            if (arr[t] > arr[t + 1])
            {
                tmp = arr[t + 1];
                arr[t + 1] = arr[t];
                arr[t] = tmp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}