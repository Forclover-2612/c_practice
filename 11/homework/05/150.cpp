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
            else if (arr[j].num1 == arr[max].num1)
            {
                max = j;
            }
        }
        if (max != i)
        {
            arr[max].num0 = i + 1;
            temp = arr[i];
            arr[i] = arr[max];
            arr[max] = temp; // i+1为此时的排名
            // 交换排名（但是这里是不是更应该是变换排名？）
            // arr[i].num0 = i + 1;
        }
        // 无论是否相等，都要把i对应行的排名改变
        arr[i].num0 = i + 1;
        // 现在排完了第一个人，我是不是要从第二个人就和第一个人比较但是又不太合理
        // 进行相邻比较吗
        if (i > 0)
        {
            if (arr[i - 1].num2 == arr[i].num2)
            {
                arr[i].num0 = arr[i - 1].num0;
                if (arr[i].num1 < arr[i - 1].num1)
                {
                    // 此时排名相同，但需要交换行
                    temp = arr[i - 1];
                    arr[i - 1] = arr[i];
                    arr[i] = temp;
                }
            }
        }
    }

    return 0;
}