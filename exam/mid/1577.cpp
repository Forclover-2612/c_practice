#include <stdio.h>
#include <string.h>
int rot(int n)
{
    int i, j;
    int num = 0;
    char str[7];
    sprintf(str, "%d", n);
    int len = strlen(str);
    for (i = 0; i < len; i++)
    {
        if (str[i] == '6')
            str[i] = '9';
        else if (str[i] == '9')
            str[i] = '6';
    }
    for (i = len - 1; i >= 0; i--)
    {
        num = num * 10 + (str[i] - '0');
    }
    return num;
}
int validnum(int n, char s[])
{
    int flag = 0;
    int i, j;
    char str[7];
    sprintf(str, "%d", n);
    int len = strlen(str);
    for (i = 0; i < len; i++)
    {
        flag = 0;
        for (j = 0; j < 5; j++)
        {
            if (str[i] == s[j])
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
            return -1;
    }
    return 1;
}
int main()
{
    int n;
    int count = 0;
    int i, j, t, p, r;
    scanf("%d", &n);
    char valid_n[6];
    int valid_arr[5000];
    // 先分析n的位数
    //  char str_n[10];
    //  char A[10];
    //  char B[10];
    //  char C[10];
    //  sprintf(str_n,"%d",n);
    //  int length=strlen(str_n);
    char s[6] = {'0', '1', '6', '8', '9'};
    // for(i=1;i<length;i++)//生成位数
    // {

    // }
    // 最简单的思路：枚举加判断
    // 超时3个点
    // 第二个思路，先生成合法数字并储存
    int num = 0;
    for (i = 1; i < 5; i++)
    {
        valid_arr[num++] = s[i] - 48;
    }
    for (i = 1; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            valid_arr[num++] = 10 * (s[i] - 48) + s[j] - 48;
        }
    }
    for (i = 1; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            for (t = 0; t < 5; t++)
            {
                valid_arr[num++] = 100 * (s[i] - 48) + 10 * (s[j] - 48) + s[t] - 48;
            }
        }
    }
    for (i = 1; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            for (t = 0; t < 5; t++)
            {
                for (p = 0; p < 5; p++)
                {
                    valid_arr[num++] = 1000 * (s[i] - 48) + 100 * (s[j] - 48) + 10*(s[t] - 48)+s[p]-48;
                }
            }
        }
    }
    for (i = 1; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            for (t = 0; t < 5; t++)
            {
                for (p = 0; p < 5; p++)
                {
                    for(r=0;r<5;r++)
                    {
                        valid_arr[num++] = 10000 * (s[i] - 48) + 1000 * (s[j] - 48) + 100*(s[t] - 48)+10*(s[p]-48)+s[p]-48;
                    }
                }
            }
        }
    }
    for(i=0;i<num;i++)
    {
        for(j=i;j<num;j++)
        {
            t=valid_arr[i]+valid_arr[j];
            if(t>=n||validnum(t,s)==-1)
            continue;
            else
            {
                if (rot(valid_arr[i]) + rot(valid_arr[j]) == rot(t))
                    count++;
            }
        }
    }
    // for (i = 1; i < n / 2; i++)
    // {
    //     for (j = i; j < n - i; j++)
    //     {
    //         t = i + j;
    //         if (t >= n || validnum(t, s) == -1 || validnum(i, s) == -1 || validnum(j, s) == -1)
    //             continue;
    //         else
    //         {
    //             if (rot(i) + rot(j) == rot(t))
    //                 count++;
    //         }
    //     }
    // }
    // printf("%d",rot(188));
    printf("%d", count);
    return 0;
}