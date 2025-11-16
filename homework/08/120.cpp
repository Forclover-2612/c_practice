#include <stdio.h>
long long step;
typedef struct{
    int m;
    int min;
    int arr[101];
}Step;
Step steps[1000000];
//储存信息
void selection_sort(int n, int m, int arr[])
{
    int i;
    int min;
    int temp;
    if (m == n)
        return;
    else
    {
        min = m;
        for (i = m + 1; i <= n; i++)
        {
            if (arr[i] < arr[min])
            {
                min = i;
            }
        }
        if (min != m)
        {
            temp = arr[min];
            arr[min] = arr[m];
            arr[m] = temp;
            // printf("%d<-->%d:", m, min);
            // for (i = 1; i <= n; i++)
            // {
            //     printf("%d ", arr[i]);
            // }
            // printf("\n");
            steps[step].m=m;
            steps[step].min=min;
            for(i=1;i<=n;i++)
            {
                steps[step].arr[i]=arr[i];
            }
            step++;
        }
        return selection_sort(n, m + 1, arr);
    }
}
int main()
{
    int n;
    int i,j;
    int arr[101];
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    selection_sort(n, 1, arr);
    for(i=step-1;i>=0;i--)
    {
        printf("%d<->%d:",steps[i].m,steps[i].min);
        for(j=1;j<=n;j++)
        {
            printf("%d ",steps[i].arr[j]);
        }
        printf("\n");
    }
    printf("Total steps:%lld\n",step);
    printf("Right order:");
    for(i=1;i<=n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}