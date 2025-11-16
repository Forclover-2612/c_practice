#include <stdio.h>
#include <string.h>
// 碱基对排序和进制转换
// 注意：前面的数字有可能是0-->不能但对的进行长度比较
//去除前导0
//有一种更好的方法，返回起始索引
int getStartIdx(char s[],char sym0)
{
    int len=strlen(s);
    int start=0;
    //假如全是0；保留一个0
    while(start<len-1&&s[start]==sym0)
    {
        start++;
    }
    return start;
}
int mycompare(char g1[], char g2[], char sym[])
{
    // g1<g2
    char sym0=sym[0];
    int start1=getStartIdx(g1,sym0);
    int start2=getStartIdx(g2,sym0);
    int len1=strlen(g1)-start1;
    int len2=strlen(g2)-start2;
    int len=strlen(sym);
    if (len1 < len2)
        return 1;
    else if (len1 > len2)
        return -1;
    else if (len1 == len2)
    {
        for (int i = 0; i < len1; i++)
        {
            //找到第一个有效字符
             char c1=g1[start1+i];
             char c2=g2[start2+i];
            if (c1 == c2)
                continue;
            else
            {
                for(int j=0;j<len;j++)
                {
                    if(c1==sym[j])
                    return 1;
                    else if(c2==sym[j])
                    return -1;
                }
                // int idx1 = 0, idx2 = 0;
                // while (sym[idx1] != c1)
                //     idx1++; // 定位g1[i]的索引
                // while (sym[idx2] != c2)
                //     idx2++; // 定位g2[i]的索引
                // // 按索引判断优先级：索引小的字符更小
                // if (idx1 < idx2)
                // {
                //     return 1; // g1[i]更小 → g1 < g2
                // }
                // else
                // {
                //     return -1; // g1[i]更大 → g1 > g2
                // }
            }
        }
    }
    return 0;
}

// 进制转化：和十进制转化的过程很像（当前数字*进制+个位数字）
long long calculate(char s[], char sym[])
{
    int base = strlen(sym);
    long long val = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        int idx = 0;
        while (sym[idx] != s[i])
            idx++;
        val = val * base + idx;
    }
    return val;
}
int main()
{
    freopen("error.in","r",stdin);
    int n;
    int i, j;
    char sym[30];
    scanf("%d %s", &n, sym);
    char Data[101][200];
    char temp[200];
    int min;
    for (i = 0; i < n; i++)
    {
        scanf("%s", Data[i]);
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++) // 小的往前放
        {
            if (mycompare(Data[j], Data[j + 1], sym) == -1)
            {
                strcpy(temp, Data[j]);
                strcpy(Data[j], Data[j + 1]);
                strcpy(Data[j + 1], temp);
            }

        }
    }
    // for (i = 0; i < n; i++)
    // {
    //     min = i;
    //     for (j = i + 1; j < n; j++)
    //     {
    //         if (calculate(Data[min], sym) > calculate(Data[j], sym))
    //         min = j;
    //     }
    //     if (min != i)
    //     {
    //         strcpy(temp, Data[i]);
    //         strcpy(Data[i], Data[min]);
    //         strcpy(Data[min], temp);
    //     }
    // }
    for (i = n - 1; i >= 0; i--)
    {
        printf("%s ", Data[i]);
    }
    printf("\n");
    printf("%lld", calculate(Data[0], sym));
    return 0;
}
//可能会溢出？
//预先判断，去掉前导0后