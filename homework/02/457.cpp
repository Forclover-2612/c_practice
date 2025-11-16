#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<stdlib.h>

int main()
{
    int n, i, j, k, t;
    char input[10];
    char ch = 'A';
    // scanf("%d",&n);

    // for(j=n-i-1;j>0;j--)
    // {
    //     printf(" ");
    // }
    // for(k=0;k<=i;k++)
    // {
    //     printf("%c",ch+k);
    // }
    // //注意：出来的k已经+1
    // for(t=0;t<i;t++)
    // {
    //     printf("%c",ch+k-2-t);
    // }
    // 更加美观的写法
    while (1)
    {
        scanf("%s", input);
        // 检查是否输入q
        if (strcmp(input, "q") == 0)
        {
            break;
        }
        // 检查是否为数字
        int is_number = 1;

        // 逐个检查字符串中的每个字符
        int i = 0;
        while (input[i] != '\0')
        {
            char c = input[i];
            if (c < '0' || c > '9') // 如果字符不在0到9之间，就不是数字
            {
                is_number = 0;
                break;
            }
            i++;
        }
        if (!is_number)
        {
            printf("输入无效\n");
            continue;
        }
        // 将字符串转换为整数
        int n = atoi(input);
        // 检查行数
        if (n < 1 || n > 26)
        {
            printf("行数不规范\n");
            continue;
        }
        for (int i = 0; i < n; i++)
        {
            for (j = 0; j < n - 1 - i; j++)
            {
                printf(" ");
            }
            for (char c = 'A'; c <= 'A' + i; c++)
            {
                printf("%c", c);
            }
            for (char c = 'A' + i - 1; c >= 'A'; c--)
            {
                printf("%C", c);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}