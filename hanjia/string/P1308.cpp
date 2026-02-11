#include <stdio.h>
#include <string.h>
#include <ctype.h>//简化：可以全部转化成小写再比较
char str1[15];
char str2[1000006];
char temp[10000];
char str[5];

int main()
{
    int flag = 0, count = 0, start = 0;
    scanf("%s", str1);
    getchar();
    fgets(str2, sizeof(str2), stdin);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len2 > 0 && str2[len2 - 1] == '\n')
        str2[len2 - 1] = ' ';
    char *pos = str2;
    char *read = str2;
    str[0] = ' ';
    while ((read = strstr(pos, str)) != NULL)//每次都从pos起始
    {
        flag = 1; // 默认不匹配
        int len = read - pos;
        //逻辑可以简化
        // if (len != len1)
        // {
        //     pos=read+1;
        // }
        // else
        // {
        //     for (int i = 0; i < len; i++)
        //     {
        //         if (str2[i + pos-str2] != str1[i])
        //         {
        //             if(str2[i + pos-str2]>='A'&&str2[i + pos-str2]<='Z')
        //             {
        //                 if(str2[i+pos-str2]-32!=str1[i])
        //                 {
        //                     flag=1;
        //                 }
        //             }
        //             if(str2[i + pos-str2]>='a'&&str2[i + pos-str2]<='z')
        //             {
        //                 if(str2[i+pos-str2]+32!=str1[i])
        //                 {
        //                     flag=1;
        //                 }
        //             }
        //         }
        //         if(flag)
        //         break;
        //     }
        // }
        if (len == len1)
        {
            flag = 0; // 假设匹配成功
            for (int i = 0; i < len; i++)
            {
                if (tolower(str2[i + (pos - str2)]) != tolower(str1[i]))
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (!flag)
        {
            count++;
            if (count == 1)
            {
                // printf("%d",pos-str2);
                start = pos - str2;
            }
        }
        // if (count == 1)
        // {
        //     // printf("%d",pos-str2);
        //     start = pos - str2;
        // }
        pos = read + 1;
    }
    if (count == 0)
    {
        printf("-1");
    }
    else
    {
        printf("%d %d", count, start);
        // printf("%d",start);
    }
    return 0;
}