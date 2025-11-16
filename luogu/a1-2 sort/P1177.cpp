#include <stdio.h>
#define MAX 100000
int arr[MAX];

int main()
{
    int n;
    scanf("%d", &n);
    int temp;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int i, j;
    // 冒泡排序
    //  for(int i=0;i<n-1;i++)
    //  {
    //      for(int j=0;j<n-i-1;j++)
    //      {
    //          if(arr[j+1]<arr[j])
    //          {
    //              temp=arr[j];
    //              arr[j]=arr[j+1];
    //              arr[j+1]=temp;
    //          }
    //      }
    //  }
    // 选择排序
    // for (int i = 0; i < n - 1; i++)
    // {
    //     int min = i;
    //     for (j = i + 1; j < n; j++)
    //     {
    //         if (arr[j] < arr[min])
    //         {
    //             min = j;
    //         }
    //     }
    //     if (min != i)
    //     {
    //         temp = arr[min];
    //         arr[min] = arr[i];
    //         arr[i] = temp;
    //     }
    // }
    //插入排序
    // for(i=1;i<n;i++)
    // {
    //     int key=arr[i];
    //     j=i-1;
    //     while(j>=0&&arr[j]>key)
    //     {
    //         arr[j+1]=arr[j];
    //         j--;
    //     }
    //     arr[j+1]=key;
    // }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}