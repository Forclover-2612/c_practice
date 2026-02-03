#include <stdio.h>
struct data
{
    int sno;
    int grades[10];
    int sum;
};

int main()
{
    int n, m; // n是学生人数
    scanf("%d %d", &n, &m);
    int gpa[m];
    struct data arr[n];
    int i, j;
    int count = 0;
    int max;
    struct data temp;
    for (i = 0; i < m; i++)
    {
        scanf("%d", &gpa[i]);
    }
    // 存入学生数据
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].sno);
        for (j = 0; j < m; j++)
        {
            scanf("%d", &arr[i].grades[j]);
        }
    }
    // 判断大于60分的科目，计算学分
    for (i = 0; i < n; i++)
    {
        count = 0;
        for (j = 0; j < m; j++)
        {
            if (arr[i].grades[j] >= 60)
            {
                count += gpa[j];
            }
        }
        arr[i].sum = count;
    }
    // 排序
    for (i = 0; i < n - 1; i++)
    {
        max = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[max].sum < arr[j].sum)
                max = j;
            else if (arr[max].sum == arr[j].sum)
            {
                //学号小的先输出
                if (arr[max].sno > arr[j].sno)
                {
                    max = j;
                }
            }
        }
        if (max != i)
        {
            temp = arr[max];
            arr[max] = arr[i];
            arr[i] = temp;
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%d %d\n", arr[i].sno, arr[i].sum);
    }
    return 0;
}