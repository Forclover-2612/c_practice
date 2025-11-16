#include <stdio.h>

int main()
{
    int n, max, tmp, lower, upper;
    scanf("%d %d %d", &n, &lower, &upper);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    // for(int i=0;i<upper-lower;i++)
    // {
    //     for(int j=lower;j<=upper-i-1;j++)
    //     {
    //         if(arr[j+1]<arr[j])
    //         {
    //             tmp = arr[j + 1];
    //             arr[j + 1] = arr[j];
    //             arr[j] = tmp;
    //         }
    //     }
    // }
    for (int i = lower; i < upper; i++)
    {
        int min = i;
        for (int j = i + 1; j <= upper; j++)
        {
            if (arr[j - 1] > arr[j])
                min = j;
        }
        if (min != i)
        {
            tmp = arr[min];
            arr[min] = arr[i];
            arr[i] = tmp;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}