#include <stdio.h>
#include <string.h>

// 统计子串
int calculate_str(char arr1[], char arr2[], int n)
{
    int flag;
    int count = 0;
    char ch;
    int len = 0;
    int j, t;
    // // 输入字符串
    // while ((ch = getchar()) != '\n')
    // {
    //     arr2[i] = ch;
    //     i++;
    // } // 此时字符串长度为i
    len = strlen(arr2);
    // 判断首元素
    for (j = 0; j < n; j++)
    {
        flag = 1;
        // flag=1;//bug:若首字符不匹配，flag还是1
        // if (arr1[j] == arr2[0])
        // {
        //     // 记得处理子串长度为1的情况
        //     if (i == 1)
        //         flag = 1;
            for (t = 1; t < len; t++)
            {
                if (arr1[j + t] != arr2[t])
                {
                    flag = 0;
                    break;
                }

            }
        // }
        if (flag)
        {
            count++;
            j += len - 1; // bug：j后面还要++；应该要-1,要么就用while
        }
    }
    return count;
}

// 删除子串
void delete_str(char *arr1, char arr2[], int n)
{
    int flag = 0;
    char ch;
    int len = 0;
    int j, t, k;
    // 输入字符串
    // while ((ch = getchar()) != '\n')
    // {
    //     arr2[i] = ch;
    //     i++;
    // } // 此时子串长度为i
    len = strlen(arr2);
    for (j = 0; j < n; j++)
    {
        flag = 1;
        // flag=1;//bug:若首字符不匹配，flag还是1
        
            for (t = 1; t < len; t++)
            {
                if (arr1[j + t] != arr2[t])
                {
                    flag = 0;
                    break;
                }

            }

        if (flag)
        {
            // 把子串后面的字符前移
            for (k = j; k < n - len; k++)
            {
                arr1[k] = arr1[k + len];
            }
            arr1[n - len] = '\0';//在不移动结尾\0的情况下，这步是必要的
            break;
        }
    }
}

// 插入子串
void insert_str(char *arr1, char arr2[], char arr3[], int n, int sum)
{
    int flag = 0;
    char ch;
    int len1 = 0;
    int len2 = 0;
    int j, t, k;
    int count = 0;
    // // 输入字符串
    // while ((ch = getchar()) != '\\ ')
    // {
    //     arr2[i] = ch;
    //     i++;
    // } // 此时子串长度为i
    // while ((ch = getchar()) != '\n')
    // {
    //     arr3[m] = ch;
    //     m++;
    // } // 此时子串长度为m
    len1 = strlen(arr2);
    len2= strlen(arr3);
    for (j = 0; j < n; j++)
    {
        flag = 1;
        // flag=1;//bug:若首字符不匹配，flag还是1
            for (t = 0; t < len1; t++)
            {
                if (arr1[j + t] != arr2[t])
                {
                    flag = 0;
                    break;
                }
            }
        if (flag)
        {
            count++;
            if (count == sum)
            {
                // 此时j就是最后一个字符串首元素的位置
                // 原字符串元素后移
                // bug：从后往前移动，避免覆盖
                for (k = n; k >= j; k--)
                {
                    arr1[k + len2] = arr1[k];
                }
                // 插入字符串2
                for (k = 0; k < len2; k++)
                {
                    arr1[j + k] = arr3[k]; // arr1原位置的元素丢失了吗
                }
            }
            j += len1 - 1;//所以是为什么
        }
    }
}

// 替换子串
void replace_str(char *arr1, char arr2[], char arr3[], int n)
{
    int flag = 0;
    int len1, len2;
    int j = 0, k, t; // j是遍历的原字符串的下标
    len1 = strlen(arr2);
    len2 = strlen(arr3);
    int current_len = n;
    char temp[1000]; // 储存需要移动的字符

    while (j <= current_len - len1) // 防止越界访问导致的匹配错误，可能读取到垃圾值
    {
        flag = 1;
        for (t = 0; t < len1; t++)
        {
            if (arr1[j + t] != arr2[t])
            {
                flag = 0;
                break;
            }
        }

        if (flag)
        {
            // printf("%d %s\n", j, arr1);
            // 先删除后添加？
            // 计算替换后的新长度
            int new_len = current_len - len1 + len2;
            // // 从后往前移动字符
            // for (k = current_len-1; k >= j + len1; k--)
            // {
            //     arr1[k + len2 - len1] = arr1[k];
            // }
            // 第一：如果误移动了结束标志，会出现提前结束的情况
            // 第二：如果len2<len1,会出现覆盖的情况
            // 最好的做法：创建一个临时数组
            for (k = j + len1; k < current_len; k++)
            {
                temp[k - (j + len1)] = arr1[k]; // 一种很好的写法：不用再开一个循环
            }
            // 替换子串
            for (k = 0; k < len2; k++)
            {
                arr1[j + k] = arr3[k];
            }
            // 将临时数组中的字符复制回原字符串
            for (k = 0; k < current_len - (j + len1); k++)
            {
                arr1[j + len2 + k] = temp[k];
            }
            // 更新长度
            current_len = new_len;
            // n=n-len1+len2;这样修改循环中仍用原来的n
            // 跳到当前子串结束位置+1
            j += len2;
            // printf("%s\n", arr1);
        }
        else
            j++;
    }
    arr1[current_len] = '\0';//长度发生变化
    // 若替换后字符串变短（如 current_len < n）：原 '\0' 仍在索引 n-1 处，但新字符串的有效字符只到 current_len-1。此时 printf 会继续打印到原 '\0' 位置，导致输出原字符串中未被覆盖的残留字符（例如旧字符串的尾部垃圾）。
    // 若替换后字符串变长（如 current_len > n）：原 '\0' 被新字符覆盖，且未添加新的 '\0'。此时 printf 会超出数组范围打印，导致输出乱码（访问了未初始化的内存）。
}

int main()
{
    char str[1000] = "abc";
    char str1[101];
    char str2[101];
    char c, ch, ch1, ch2;
    int n = 0, i = 0, j, t;
    int flag = 1;
    // 输入原字符串
    fgets(str, sizeof(str), stdin); // fgets读取的字符串包含换行符
    n = strlen(str);
    // getchar();
    // 字符串的长度为n
    scanf("%c", &c);
    getchar();
    if (c == 'C')
    {
        scanf("%s", str1);
        printf("%d", calculate_str(str, str1, n));
    }
    else if (c == 'D')
    {
        scanf("%s", str1);
        delete_str(str, str1, n);
        printf("%s", str); //%s会直接读取到'/0'的位置
    }
    else if (c == 'I')
    {
        scanf("%s %s", str1, str2);
        int sum = calculate_str(str, str1, n);
        insert_str(str, str1, str2, n, sum);
        printf("%s", str);
    }
    else if (c == 'R')
    {
        scanf("%s %s", str1, str2);
        replace_str(str, str1, str2, n);
        printf("%s", str);
    }
    return 0;
}