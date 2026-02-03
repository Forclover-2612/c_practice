#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    char str[1001];
    int ch;
    int index = 0;
    int flag = 0;
    char arr[1001] = {};

    // 读取字符串
    while ((ch = getchar()) != '\n') // 明确优先级
    {
        arr[index++] = (char)ch;
    }

    for(int i=0;i<index;i++)
    {
        printf("%c",arr[i]);
    }

    int n = index / 2;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != arr[index - 1 - i])
        {
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        printf("No");
    }
    else
    {
        printf("Yes");
    }
    return 0;
}