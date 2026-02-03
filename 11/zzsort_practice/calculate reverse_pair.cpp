#include <stdio.h>
// 使用归并排序解决逆序对问题
int arr[100005];
int temp[100005];
long long count;
void mergesort(int left, int right, int mid, int n)
{
    int i = left;
    int j = mid + 1;
    // while(arr[i]<arr[j]&&j<right)
    // {
    //     j++;
    // }
    // if(j==right)
    // return;
    // else
    // {
    //     count+=right-j;
    // }
    int k = 0;
    //处理的是闭区间
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            // 归并排序能加速统计逆序对的原理在于：
            // 如果左边当前的数 arr[i] 比右边的 arr[j] 大
            // 那么左边剩下的所有数都比 arr[j] 大！
            //  count++;
            count += (long long)(mid - i + 1);
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= right)
    {
        temp[k++] = arr[j++];
    }
    k = 0;
    while (left <= right)
    {
        arr[left++] = temp[k++];
    }
}
void merge(int left, int right, int n)
{
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    merge(left, mid, n);
    merge(mid + 1, right, n);
    mergesort(left, right, mid, n);
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    merge(0, n - 1, n);
    printf("%lld", count);
    return 0;
}