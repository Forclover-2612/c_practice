#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
// long long arr[100000];
typedef struct{
    long long ori;
    int date;
}IDCard;
IDCard arr[100000];
// char str[100000][20];
// 注意：数据截断问题
int mycmp1(long long num1, long long num2)
{
    int i;
    char str1[20];
    char str2[20];
    //比较耗时
    sprintf(str1, "%lld", num1);
    sprintf(str2, "%lld", num2);
    for (i = 6; i < 14; i++)
    {
        if (str1[i] == str2[i])
            continue;
        else
        {
            if (str1[i] < str2[i])
                return -1;
            else
                return 1;
        }
    }
    // for (i = 0; i < 18; i++)
    // {
    //     if (str1[i] < str2[i])
    //         return -1;
    //     else
    //         return 1;
    // }
    int res = strcmp(str1, str2);
    if (res < 0)
        return -1;
    else
        return 1;
    return 0;
}
int mycmp(IDCard a,IDCard b)
{
    if(a.date!=b.date)
    return a.date<b.date;
    return a.ori<b.ori;
}
int partition(int left, int right)
{
    int idx = left + rand() % (right - left + 1);
    IDCard temp;
    temp = arr[left];
    arr[left] = arr[idx];
    arr[idx] = temp;
    IDCard x = arr[left];
    while (left < right)
    {
        // int sign1 = mycmp(x, arr[right]);
        // int sign2 = mycmp(x, arr[left]);
        while (!mycmp(x, arr[right]) && right > left)
        {
            right--;
            // sign1 = mycmp(x, arr[right]);
        }
        arr[left] = arr[right];
        while (mycmp(x, arr[left]) && left < right)
        {
            left++;
            // sign2=mycmp(x,arr[left]);
        }
        arr[right] = arr[left];
    }
    arr[left] = x;
    return left;
}
void quicksort(int left, int right)
{
    if (left >= right)
        return;
    int k = partition(left, right);
    quicksort(left, k - 1);
    quicksort(k + 1, right);
}
int main()
{
    // freopen("error (2).in","r",stdin);
    srand(time(NULL));
    int i, j;
    int n;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i].ori);
        //如何提取日期：去掉后4位，再取后8位
        arr[i].date=(int)((arr[i].ori/10000)%100000000);
    }
    // for(i=0;i<n;i++)
    // {
    //     sprintf(str[i],"%lld",arr[i]);
    // }
    quicksort(0, n - 1);
    for (i = 0; i < n; i++)
    {
        printf("%lld\n", arr[i].ori);
        
    }
    return 0;
}