#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int arr[50];
    int arr2[50];
    int count = 0;
    int flag = 0;
    int num;
    //getchar()返回的是ASCII值，而非实际输入的数字值，因此找不到-1
    //如果-48处理只局限于0~9的数字，但是-1的符号缺失（因为不是digit)
    // while ((num = getchar()) != '\n')
    // {
    //     if (isdigit(num))
    //     {
    //         arr[count] = num;
    //         count++;
    //     }
    // }
    // //自动跳过空格和回车，直到读取到非数字字符或Ctrl+Z结束
    // //但是不符合题目要求
    // while(scanf("%d",&arr[count])==1)
    // {
    //     count++;
    // }
    // 找到第一个-1的位置
    int first_end;
    for (int i = 0; i < count; i++)
    {
        if (arr[i] == -1)
        {
            first_end = i;
        }
    }
    // 找到第二个-1的位置
    int second_end;
    for (int i = first_end + 1; i < count; i++)
    {
        if (arr[i] == -1)
        {
            second_end = i;
        }
    }
    int len1 = first_end;
    int len2 = second_end - first_end - 1;
    printf("%d\n", len1);
    printf("%d\n", len2);
    int min = (len1 < len2) ? len1 : len2;
    for (int i = 0; i < min; i++)
    {
        if (arr[i] != arr[first_end + 1 + i])
        {
            printf("%d", arr[i] - arr[first_end + 1 + i]);
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        printf("Not Comparable");
    }
    return 0;
}