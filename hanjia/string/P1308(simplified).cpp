#include<stdio.h>
#include<string.h>
#include<ctype.h>
char str1[15];
char str2[1000006];

//如何处理空格
int main()
{
     // 1. 读取输入
    // 使用 scanf 读取单词，会自动跳过空白符
    scanf("%s", str1); 
    getchar(); // 吃掉 scanf 留下的换行符
    // 读取整行文章
    fgets(str2, sizeof(str2), stdin);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // 去掉 str2 末尾可能的换行符，避免干扰
    if (len2 > 0 && str2[len2 - 1] == '\n') {
        str2[len2 - 1] = '\0';
        len2--;
    }

    // 3. 核心查找逻辑
    int count = 0;
    int first_pos = -1;
    char *p = str2;

    // 遍历文章中的每一个字符
    while ((p = strstr(p, str1)) != NULL) {
        // p 是找到 str1 在 str2 中的位置指针
        
        // 检查这个匹配是否是独立的单词
        //原来的思路：找空格
        // 独立的条件：（分情况）
        // (1) 匹配位置的前一个字符是空格，或者匹配位置是文章开头
        // (2) 匹配位置+单词长度的后一个字符是空格，或者已经是文章结尾
        
        int idx = p - str2; // 当前匹配的索引
        
        int start_valid = (idx == 0) || (str2[idx - 1] == ' ');
        int end_valid = (str2[idx + len1] == '\0') || (str2[idx + len1] == ' ');

        if (start_valid && end_valid) {
            count++;
            if (first_pos == -1) {
                first_pos = idx;
            }
        }

        // 继续向后查找，一定要向前移动，防止死循环
        // 这里 +1 是为了能够匹配重叠部分（虽然单词统计通常不重叠，但为了严谨和防止原地踏步）
        // 对于单词统计，通常直接跳过这个单词也可以 p += len1;
        p++; //或者p+=len1
    }

    // 4. 输出结果
    if (count > 0) {
        printf("%d %d", count, first_pos);
    } else {
        printf("-1");
    }
    return 0;
}