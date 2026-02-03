#include <stdio.h>

int main()
{
    int n, max, tmp;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    // 最大元素往后排
    for (int j = 0; j < n - 1; j++)
    {
        for (int t = 0; t < n - j - 1; t++)//-1防越界
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