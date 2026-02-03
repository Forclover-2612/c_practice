#include <stdio.h>
#include <string.h>

// 也就是你原来的逻辑，但是写得更清晰一点
char *checkSubstr_Simple(char *s1, char *s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int used[220]; // 放在函数内，避免全局污染

    // 如果s1比s2长，肯定找不到
    if (len1 > len2) return NULL;

    // 遍历s2的每一个可能的起始位置
    for (int i = 0; i <= len2 - len1; i++)
    {
        // 每次开始前，重置used数组
        // 这里用memset更方便，需要包含string.h
        memset(used, 0, sizeof(used)); 
        
        int match_count = 0;
        
        // 尝试从 s2[i] 开始匹配 len1 个字符
        for (int j = 0; j < len1; j++)
        {
            char current_char = s2[i + j];
            int found_char = 0;
            
            // 在 s1 中寻找这个字符
            for (int k = 0; k < len1; k++)
            {
                if (s1[k] == current_char && !used[k])
                {
                    used[k] = 1;
                    found_char = 1;
                    match_count++;
                    break; // 找到了就跳出最内层循环
                }
            }
            
            // 如果这个字符在s1里没找到（或者次数用光了），那这个起点i肯定不行
            if (!found_char) break;
        }

        // 如果匹配的长度等于len1，说明找到了
        if (match_count == len1)
        {
            return &s2[i];
        }
    }

    return NULL;
}