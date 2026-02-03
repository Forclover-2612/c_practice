#include <stdio.h>

// 定义结构体，结构体能整行赋值，而二维数组不行
struct Data
{
    int num0;
    int num1;
    int num2;
};

int main()
{
    int n;
    scanf("%d", &n);
    struct Data arr[n];
    int no[n];
    int i, j, t, p, max;
    struct Data temp;
    int temp_no;
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[i].num1, &arr[i].num2);
        no[i] = i + 1;
        arr[i].num0 = i + 1;
    }
    // 选择排序？
    for (i = 0; i < n; i++)
    {
        max = i;                    // 假设第一个元素是最大的
        for (j = i + 1; j < n; j++) // 往后遍历
        {
            if (arr[j].num2 > arr[max].num2)
            {
                max = j;
            }
            // 解决方法：先对学号进行排序
            else if (arr[j].num2 == arr[max].num2)
            {
                if(arr[j].num1<arr[max].num1)
                max=j;
            }
        }
        if (max != i)
        {
            arr[max].num0 = i + 1;
            temp = arr[i];
            arr[i] = arr[max];
            arr[max] = temp; // i+1为此时的排名
        }
        arr[i].num0 = i + 1;
        if (i > 0)
        {
            if (arr[i - 1].num2 == arr[i].num2)
            {
                arr[i].num0 = arr[i - 1].num0;
            }
        }
    }
    // bug1：排序是正常了，但是排名后面还会改变？
    // bug2:还是不能正常排序（只是相邻交换）
    // for (i = 0; i < n; i++)
    // {
    //     // 从i+1个元素往后检查
    //     for (t = i + 1; t < n; t++)
    //     {

    //         if (arr[t].num2 == arr[i].num2)
    //         {
    //             no[t] = no[i];
    //             if (arr[t].num1 < arr[i].num1)
    //             {
    //                 temp = arr[t];
    //                 arr[t] = arr[i];
    //                 arr[i] = temp;
    //             }
    //         }
    //     }
    // }
    for (i = 0; i < n; i++)
    {
        printf("%d %d %d\n", arr[i].num0, arr[i].num1, arr[i].num2);
    }
    return 0;
}