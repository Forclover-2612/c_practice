#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 20000

// 全局变量，保存输入的所有字符
char input[MAX_LEN];
int pos = 0; // 当前读取位置

// 递归解压函数
// 返回一个动态分配的字符串，由调用者负责 free
char* decompress()
{
    char* result = (char*)malloc(MAX_LEN);
    int result_len = 0;
    
    while (pos < strlen(input))
    {
        char ch = input[pos++];
        
        if (ch == '[')
        {
            // 读取数字 k
            int k = 0;
            while (pos < strlen(input) && isdigit(input[pos]))
            {
                k = k * 10 + (input[pos] - '0');
                pos++;
            }
            
            // 递归处理括号内容
            char* str = decompress();
            
            // 重复 k 次拼接
            int str_len = strlen(str);
            for (int i = 0; i < k; i++)
            {
                strcpy(result + result_len, str);
                result_len += str_len;
            }
            
            free(str); // 释放递归返回的字符串
        }
        else if (ch == ']')
        {
            // 这一层结束，返回结果
            result[result_len] = '\0';
            return result;
        }
        else
        {
            // 普通字符，添加到结果
            result[result_len++] = ch;
        }
    }
    
    result[result_len] = '\0';
    return result;
}

int main()
{
    // 读取所有输入到 input 数组
    int i = 0;
    int ch;
    while ((ch = getchar()) != EOF)
    {
        if (i < MAX_LEN - 1)
        {
            input[i++] = ch;
        }
    }
    input[i] = '\0';
    
    pos = 0;
    char* result = decompress();
    printf("%s", result);
    
    free(result);
    return 0;
}