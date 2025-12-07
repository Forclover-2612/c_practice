#include <stdio.h>
int n, m;
int arr[55][55];
void reverse(int p)
{
    if (p == 4)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
    }
    if (p == 1)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                printf("%d ", arr[j][i]);
            }
            printf("\n");
        }
    }
    if (p == 2)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
    }
    if (p == 3)
    {
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d ", arr[j][i]);
            }
            printf("\n");
        }
    }
}
int main()
{
    int rev;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    scanf("%d", &rev);
    if(rev<0)
    {
        while(rev<0)
        {
            rev+=360;
        }
    }
    int num = rev / 90;
    if (num % 4 == 1)
    {
        reverse(1);
    }
    else if (num % 4 == 2)
    {
        reverse(2);
    }
    else if (num % 4 == 3)
    {
        reverse(3);
    }
    else if (num % 4 == 0)
    {
        reverse(4);
    }

    return 0;
}