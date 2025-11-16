#include <stdio.h>

int main()
{
    int i, j;
    int n;
    int count;
    int row, col, step;
    scanf("%d %d", &row, &col);
    scanf("%d", &step);
    int arr1[22][22];
    int arr2[22][22];
    for (i = 0; i < 22; i++)
    {
        for (j = 0; j < 22; j++)
        {
            arr1[i][j] = -1;
            arr2[i][j] = -1;
        }
    }
    for (i = 1; i <= row; i++)
    {
        for (j = 1; j <= col; j++)
        {
            scanf("%d", &arr1[i][j]);
        }
    }
    for (i = 1; i <= row; i++)
    {
        for (j = 1; j <= col; j++)
        {
            arr2[i][j]=arr1[i][j];
        }
    }
    for (n = 0; n < step; n++)
    {
        for (i = 1; i <= row; i++)
        {
            for (j = 1; j <= col; j++)
            {
                count = 0;
                if (arr1[i][j - 1] == 1)
                    count++;
                if (arr1[i][j + 1] == 1)
                    count++;
                if (arr1[i - 1][j] == 1)
                    count++;
                if (arr1[i + 1][j] == 1)
                    count++;
                if (arr1[i][j] == 1)
                {
                    if (count < 2 || count == 4)
                        arr2[i][j] = 0;
                }
                else if (arr1[i][j] == 0)
                {
                    if (count == 3)
                        arr2[i][j] = 1;
                }
            }
        }
        for (i = 1; i <= row; i++)
        {
            for (j = 1; j <= col; j++)
            {
                arr1[i][j] = arr2[i][j];
            }
        }
    }
    for (i = 1; i <= row; i++)
    {
        for (j = 1; j <= col; j++)
        {
           printf("%d ",arr1[i][j]);
        }
        printf("\n");
    }
    return 0;
}