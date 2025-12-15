#include <stdio.h>
#include <math.h>
int main()
{
    int m;
    int i, j;
    scanf("%d", &m);
    int arr1[102];
    int arr2[102];
    int flag = 0;
    int count = 1;
    for (i = 1; i <= m; i++)
    {
        scanf("%d", &arr1[i]);
    }
    arr1[0] = 0;
    arr1[m + 1] = 0;
    arr2[0] = 0;
    arr2[m + 1] = 0;
    for (i = 2; i <= m; i++)
    {
        if (arr1[i] != arr1[i - 1])
        {
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        while (1)
        {
            if (count % 2 != 0)
            {
                flag = 0;
                for (i = 1; i <= m; i++)
                {
                    if (i - 1 != 0 && i != m)
                        arr2[i] = floor((arr1[i - 1] + arr1[i] + arr1[i + 1]) / 3);
                    else
                    {
                        arr2[i] = floor((arr1[i - 1] + arr1[i] + arr1[i + 1]) / 2);
                    }
                }
                for (i = 2; i <= m; i++)
                {
                    if (arr2[i] != arr2[i - 1])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (!flag)
                {
                    count++;
                    break;
                }
                else
                    count++;
            }
            if (count % 2 == 0)
            {
                flag = 0;
                for (i = 1; i <= m; i++)
                {
                    if (i - 1 != 0 && i != m)
                        arr1[i] = floor((arr2[i - 1] + arr2[i] + arr2[i + 1]) / 3);
                    else
                    {
                        arr1[i] = floor((arr2[i - 1] + arr2[i] + arr2[i + 1]) / 2);
                    }
                }
                for (i = 2; i <= m; i++)
                {
                    if (arr1[i] != arr1[i - 1])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (!flag)
                {
                    count++;
                    break;
                }
                else
                    count++;
            }
        }
    }
    printf("%d", count);
    return 0;
}