#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// 分治的位置
int partition(int arr[], int left, int right)
{
    // 优化1：随机选择基准值，避免有序数组导致的最坏情况
    // 随机选一个位置，和left交换
    int rand_idx = left + rand() % (right - left + 1); // 生成从left到right的随机数
    int temp = arr[left];
    arr[left] = arr[rand_idx];
    arr[rand_idx] = temp;
    // 拿出元素
    int x = arr[left];
    // 也可以直接写=
    while (left < right)
    {
        // 查找从右到左小于x的元素（移动right)
        // 把元素放在前面的空位(是否能放)
        // 找到第一个大于x的数（移动left)
        // 把元素放在后面的空位
        //注意：是大于等于（防止遇到重复元素时死循环）
        while (arr[right] >= x && right > left)
        {
            right--;
        }
        //可以去掉多余的if
        // if (left < right)
        // {
            arr[left] = arr[right];
            // left++;
        // }
        while (arr[left] <= x && left < right)
        {
            left++;
        }
        // if (left < right)
        // {
            arr[right] = arr[left];
            // right--;
        // }
    }
    arr[left] = x;
    return left;
}
void quicksort(int arr[], int left, int right)
{
    if (left >= right)
        return;
    else
    {
        int k = partition(arr, left, right);
        quicksort(arr, left, k - 1);
        quicksort(arr, k + 1, right);
        return;
    }
}
int main()
{
    srand(time(NULL));
    int n;
    scanf("%d", &n);
    int arr[100];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}