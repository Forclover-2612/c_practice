#include <stdio.h>

int main()
{
    int n;
    int i, j;
    scanf("%d", &n);
    int arr1[101] = {0};
    double arr2[100];
    for (i = 1; i <= n; i++)
    {
        scanf("%d %lf", &arr1[i], &arr2[i]);
    }
    int gain;
    double sum;
    scanf("%d", &gain);
    if (gain > 0)
    {
        for (i = 1; i <= n; i++)
        {
            if ((gain > arr1[i - 1] && gain <= arr1[i])||i==n)
            {
                sum += (gain - arr1[i - 1]) * arr2[i];
                break;
            }
            else if (gain > arr1[i - 1] && gain > arr1[i])
                sum += (arr1[i] - arr1[i - 1]) * arr2[i];
        }
        printf("%.2lf", sum);
    }
    else
        printf("NO");
    return 0;
}