#include <stdio.h>

int main()
{
    int n,count = 0;
    long long m;
    scanf("%d", &n);
    scanf("%lld", &m);
    long long arr[n];
    int i, j, flag = 0;
    long long key, temp;
    int mid, left, right;
    for (i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    // 先排序
    //插入排序
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while ((j >= 0) && (arr[j] > key))//一定要写key
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    // 冒泡排序
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    // 二分查找
    left = 0;
    right = n - 1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (arr[mid] == m)
        {
            count++;
            flag = 1;
            break;
        }
        if (m > arr[mid])
        {
            left = mid + 1;
            count++;
        }
        else
        {
            right=mid-1;
            count++;
        }
    }
    if(flag)
    {
        printf("%d\n",mid);
        printf("%d",count);
    }
    else
    {
        printf("-1\n%d",count);
    }
    return 0;
}