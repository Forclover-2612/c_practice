#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
    string str;
    char c;
    int arr[100] = {};
    int index = 0;
    int sum = 0;
    int n = 0;
    cin >> str; // 读取号码
    // 处理每个字符
    for (char c : str) // 遍历字符写法
    {
        if ((c >= '0' && c <= '9') || c == 'X') // 判断是否为数字或X
        {
            arr[index++] = c; // 不可颠倒写
        }
    }
    for (index = 0; index < 9; index++)
    {
        // 转换为相应的数字
        sum += (arr[index] - 48) * (index + 1); // 计算加和
    }
    n = sum % 11;
    if (arr[9] != 'X')
    {
        if (n == arr[9]-48)
        {
            printf("Right");
        }
        else if(n==10)
        {
            printf("%d-%d%d%d-%d%d%d%d%d-%c", arr[0]-48, arr[1]-48, arr[2]-48, arr[3]-48, arr[4]-48, arr[5]-48, arr[6]-48, arr[7]-48, arr[8]-48, 'X');
        }
        else 
        {
            printf("%d-%d%d%d-%d%d%d%d%d-%d", arr[0]-48, arr[1]-48, arr[2]-48, arr[3]-48, arr[4]-48, arr[5]-48, arr[6]-48, arr[7]-48, arr[8]-48, n);
        }
    }
    else if (arr[9] = 'X')
    {
        if (n == 10)
        {
            printf("Right");
        }
        else
        {
            printf("%d-%d%d%d-%d%d%d%d%d-%d", arr[0]-48, arr[1]-48, arr[2]-48, arr[3]-48, arr[4]-48, arr[5]-48, arr[6]-48, arr[7]-48, arr[8]-48, n);
        }
    }
    return 0;
}