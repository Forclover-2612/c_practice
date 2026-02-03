#include <iostream>
#include <stdio.h>
#include <stdbool.h>
using namespace std;

// 利用杨辉三角算最终和
int c[] = {1, 4, 6, 4, 1};
bool found = false;
int n;

int calculateSum(int arr[])
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += arr[i] * c[i];
    }
    return sum;
}

// 回溯生成1到5的排列
// 假如要储存？
void backtrack(int arr[], int index, bool used[])
{
    if (found)
        return;     // 已经找到解，直接返回
    if (index == 5) // 已经生成了一个完整的排列，判断加和
    {
        int sum = calculateSum(arr);
        if (sum == n)
        {
            for (int i = 0; i < index; i++)
            {
                printf("%d ", arr[i]);
            }
            found = true; // 剪枝：一旦找到答案，一直返回上一层
        }
        return; // 无论是否符合，都要返回上一层
    }
    for (int i = 1; i <= 5; i++) // 从1到5尝试，保证第一个生成的就是字典序最小的
    {
        if (!used[i]) // 数字i没用过
        {
            arr[index] = i;
            used[i] = true;//标记数字i为用过
            backtrack(arr, index + 1, used); // 递归填充下一个位置
            used[i] = false;                 // 已经生成一种（或一类）排列后，撤销选择
        }
    }
}

int main()
{
    int arr[5];
    bool used[6] = {false}; // 标记1到5是否被使用过
    // 要写6，否则发生越界（为了索引和数字对应，多出来一个used[0])
    scanf("%d", &n);
    backtrack(arr, 0, used);
    return 0;
}