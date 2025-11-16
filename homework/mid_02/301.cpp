#include <stdio.h>
#include <math.h>
int arr[5000];
struct Data
{
    int no;
    int num;
};
void task1(int arr[], int m, int n)
{
    int i, j;
    int unit = 100 / m;
    struct Data count[10];
    struct Data temp;
    for (i = 0; i < m; i++)
    {
        count[i].num = 0;
        count[i].no = i;
    }
    for (i = 0; i < n; i++)
    {
        if (arr[i] == 100)
            count[m - 1].num++;
        else
        {
            for (j = 0; j < m; j++)
            {
                if (arr[i] >= j * unit && arr[i] < (j + 1) * unit)
                {
                    count[j].num++;
                }
            }
        }
    }
    for (i = 0; i < m; i++)
    {
        int max = i;
        for (j = i + 1; j < m; j++)
        {
            if (count[j].num > count[max].num)
                max = j;
            else if (count[j].num == count[max].num)
            {
                if (count[j].no < count[max].no)
                    max = j;
            }
        }
        if (max != i)
        {
            temp = count[i];
            count[i] = count[max];
            count[max] = temp;
        }
    }
    for (j = 0; j < m; j++)
    {

        if (count[j].num != 0)
        {
            if (count[j].no == m - 1)
            {
                printf("[%d,100]: %d\n", count[j].no * unit, count[j].num);
            }
            // else if (count[j].no == 0)
            // {
            //     printf("[ 0, %d): %d\n", (count[j].no + 1) * unit, count[j].num);
            // }
            else
                printf("[%2d, %d): %d\n", count[j].no * unit, (count[j].no + 1) * unit, count[j].num);
        }
    }
}
void task2(int arr[], int m, int n)
{
    int i, j;
    int unit = 100 / m;
    struct Data count[10];
    struct Data temp;
    int flag = 1;
    for (i = 0; i < m; i++)
    {
        count[i].num = 0;
        count[i].no = i;
    }
    for (i = 0; i < n; i++)
    {
        if (arr[i] == 100)
            count[m - 1].num++;
        else
        {
            for (j = 0; j < m; j++)
            {
                if (arr[i] >= j * unit && arr[i] < (j + 1) * unit)
                {
                    count[j].num++;
                }
            }
        }
    }
    int t=0;
    //理解问题：要找到最大人数
    for (i = 0; i < m; i++)
    {
        if (count[i].num > 50)
        {
            flag = 0;
        }
        if(count[i].num>count[t].num)
        t=i;//找到最大值的下标
    }
    //归一化
    if (!flag)
    {
        double a = 50.0 / count[t].num;
        count[t].num = 50;
        for (i = 0; i < m; i++)
        {
            if (i == t)
                continue;
            else
                count[i].num = floor(a * count[i].num);
        }
    }
    for (i = 0; i < m; i++)
    {
        if (i == m - 1)
        {
            printf("[%d,100]:", i * unit);
            for (j = 0; j < count[i].num; j++)
            {
                printf("*");
            }
        }
        else
        {
            printf("[%2d, %d):", i * unit, (i + 1) * unit);
            for (j = 0; j < count[i].num; j++)
            {
                printf("*");
            }
        }
        printf("\n");
    }
}
int main()
{
    // freopen("error.in","r",stdin);
    int n, m, g;
    int i, j;
    scanf("%d %d %d", &n, &m, &g);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    if (g == 0)
    {
        task1(arr, m, n);
        printf("\n");
        task2(arr, m, n);
    }
    else if (g == 1)
    {
        task1(arr, m, n);
    }
    else
    {
        task2(arr, m, n);
    }
    return 0;
}