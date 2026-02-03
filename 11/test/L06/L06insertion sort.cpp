#include <stdio.h>

int main()
{
    int n, left, right;
    scanf("%d %d %d", &n, &left, &right);
    int arr[n];
    int key;
    int i, j;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    // 核心代码
    for (i = left + 1; i <= right; i++)
    {
        key = arr[i]; // i是待插入元素
        // 比较范围：从left到j
        j = i - 1; // 从当前元素的前一个元素开始比较
        while ((j >= left) && (arr[j] > key))
        {
            arr[j + 1] = arr[j]; // 元素右移一个单位，为arr[i]的插入提供位置
            j--;                 // 继续向左比较
        }
        arr[j + 1] = key; // 将arr[i]的数字插到正确位置，多减了一个1加回
    }
    // 输出
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}