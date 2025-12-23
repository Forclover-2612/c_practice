#include <stdio.h>
#include <string.h>

char *checkSubstr_Optimized(char *s1, char *s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if (len1 > len2) return NULL;

    // map数组用来记录字符频率，ASCII码共有128个常用字符，256足以覆盖
    // target用于记录s1的频率，window用于记录s2当前窗口的频率
    int target[256] = {0};
    int window[256] = {0};

    // 1. 统计 s1 的字符频率
    for (int i = 0; i < len1; i++) {
        target[(unsigned char)s1[i]]++;
    }

    // 2. 初始化窗口（先把s2的前len1个字符放进去）
    // 注意：只初始化 len1-1 个，方便在循环里统一处理“进一个、出一个”的逻辑
    // 或者直接初始化完整窗口然后check，这里采用逐个滑动的写法：
    
    // 先填满第一个窗口的数据
    for(int i = 0; i < len1; i++) {
        window[(unsigned char)s2[i]]++;
    }

    // 3. 检查第一个窗口是否匹配
    // memcmp 可以快速比较两块内存，如果两个数组完全一样，返回0
    if (memcmp(target, window, sizeof(target)) == 0) {
        return s2; 
    }

    // 4. 开始滑动窗口
    // i 代表窗口刚刚新加入的那个字符的索引
    // 窗口范围是 [i - len1 + 1, i]
    for (int i = len1; i < len2; i++) {
        // 新加入的字符
        char new_char = s2[i];
        // 被移出的字符 (位于窗口最左侧)
        char old_char = s2[i - len1];

        // 更新窗口统计：进一个，出一个
        window[(unsigned char)new_char]++;
        window[(unsigned char)old_char]--;

        // 再次检查两个频率数组是否一致
        if (memcmp(target, window, sizeof(target)) == 0) {
            // 返回窗口起始位置
            return &s2[i - len1 + 1];
        }
    }

    return NULL;
}

int main()
{
    char s1[220], s2[220];
    char *pRes = NULL;

    // 建议加上防止缓冲区溢出的限制
    if (scanf("%219s%219s", s1, s2) != 2) return 0;
    
    pRes = checkSubstr_Optimized(s1, s2);

    if (pRes == NULL)
        printf("false\n");
    else
    {
        // 这一步虽然能打印出结果，但会修改原字符串s2的内容（把后面截断了）
        // 如果题目允许修改s2，这样写没问题。
        pRes[strlen(s1)] = '\0';
        printf("%s\n", pRes);
    }
    return 0;
}