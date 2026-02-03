#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
char *checkSubstr(char *s1, char *s2)
{
    int used[205];

    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int _len2 = len2;

    char *pos = s2;
    int flag_curr = 0;
    int flag_find = 1;
    while (_len2--)
    {
        int _len1 = len1;
        flag_find = 1;
        //可以使用count计数简化标记
        // for (int i = 0; i < len1; i++)
        // {
        //     used[i] = 0;
        // }
        memset(used,0,sizeof(used));
        // 对每一个起点都往后找，找不到直接break
        char *curr_pos = pos;
        // 不能随便改动len1
        while (_len1--)
        {
            flag_curr = 0;
            if (*curr_pos == '\0')
            {
                // 已经找到了最后，但是找不到
                return NULL;
            }
            for (int i = 0; i < len1; i++)
            {
                if (*curr_pos == s1[i] && used[i] == 0)
                {
                    used[i] = 1;
                    flag_curr = 1; // 当前已经找到了字符
                    break;
                }
            }
            // 如果没有找到字符，break
            if (!flag_curr)
            {
                flag_find = 0;
                break;
            }
            curr_pos++;
        }
        // 如果已经找到了字符串
        if (flag_find)
        {
            return pos;
        }
        pos++;
    }
    return NULL;
}

int main()
{
    char s1[220], s2[220];
    char *pRes = NULL;

    scanf("%s%s", s1, s2);
    pRes = checkSubstr(s1, s2);

    if (pRes == NULL)
        printf("false\n");
    else
    {
        pRes[strlen(s1)] = '\0';
        printf("%s", pRes);
    }
    return 0;
}