#include <stdio.h>
#include <string.h>
char res[500][3];
// 建议：先存到一个临时变量中，不然每次回溯回去前面都是0
int path[3];
int count = 0;
void search(char *str, int n, int len, int index)
{
    if (n == 3)
    {
        // 最后一个数字的判断
        int val = 0;
        // int t;
        if (len - index == 0 || len - index > 3)
            return;
        if (len - index > 1 && str[index] == '0')
            return;
        for (int j = index; j < len; j++)
        {
            val = 10 * val + str[j] - '0';
        }
        if (val >= 0 && val <= 255)
        {
            for (int k = 0; k < 3; k++)
            {
                res[count][k] = path[k];
            }
            count++;
        }
        return;
    }
    for (int i = index; i < index + 3 && i < len - 1; i++)
    {
        int val = 0;
        for (int j = index; j <= i; j++)
        {
            val = 10 * val + str[j] - '0';
        }
        if (val < 0 || val > 255)
        {
            continue;
        }
        // if(str[index]=='0'&&val>0)
        // {
        //     continue;
        // }
        if (i > index && str[index] == '0')
            continue;
        // res[count][n] = i;
        path[n] = i;
        search(str, n + 1, len, i + 1);
    }
}
int main()
{
    char str[15];
    scanf("%s", str);
    int len = strlen(str);
    search(str, 0, len, 0);
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j <= res[i][0]; j++)
        {
            printf("%c", str[j]);
        }
        printf(".");

        for (int j = res[i][0] + 1; j <= res[i][1]; j++)
        {
            printf("%c", str[j]);
        }
        printf(".");

        for (int j = res[i][1] + 1; j <= res[i][2]; j++)
        {
            printf("%c", str[j]);
        }
        printf(".");
        for (int j = res[i][2] + 1; j < len; j++)
        {
            printf("%c", str[j]);
        }
        printf("\n");
    }

    return 0;
}