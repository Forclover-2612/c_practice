#include <stdio.h>
#include <string.h>
struct use
{
    char str[3];
    int count;
};
void judge(char arr[][8][3], int n)
{
    int i, j, t, k;
    int flag_same, flag_duizi;
    int num = 0;
    struct use used[8];
    for (i = 0; i < 8; i++)
    {
        flag_same = 0;
        for (j = 0; j < num; j++)
        {
            if (strcmp(arr[n][i], used[j].str) == 0)
            {
                flag_same = 1;
                used[j].count++;
                break;
            }
        }
        if (!flag_same)
        {
            strcpy(used[num].str, arr[n][i]);
            used[num].count = 1;
            num++;
        }
    }
    // 先判断是否有对子
    for (i = 0; i < num; i++)
    {
        flag_duizi = 0;
        int mianzi = 0;
        // 注意在原数组上的改动要保存下来
        if (used[i].count >= 2)
        {
            flag_duizi = 1;
            used[i].count -= 2;
            int orig_i_count = used[i].count;
            int kezi_j[2] = {-1, -1}; // 存储刻子的牌的索引
            int kezi_orig[2];         // 存储原始数量
            // // 第一种情况：三张重复的牌
            for (j = 0; j < num; j++)
            {
                if (used[j].count >= 3)
                {
                    kezi_j[mianzi] = j;
                    kezi_orig[mianzi] = used[j].count;
                    mianzi++;
                    used[j].count -= 3;
                }
            }
            if (mianzi == 2)
            {
                printf("YES\n");
                return;
            }
            // 怎么把用过的牌删去
            // 第二种情况：三张连续的同花色牌
            // 遍历数组，将剩下的牌组成一个新的数组？
            int last_count = 0;
            int last[8];
            for (j = 0; j < num; j++)
            {
                if (used[j].count > 0)
                {
                    for (t = 0; t < used[j].count; t++)
                    {
                        if (used[j].str[0] == 'w')
                        {
                            last[last_count++] = 30 + (used[j].str[1] - '0');
                        }
                        else if (used[j].str[0] == 't')
                        {
                            last[last_count++] = 20 + (used[j].str[1] - '0');
                        }
                        else if (used[j].str[0] == 'b')
                        {
                            last[last_count++] = 10 + (used[j].str[1] - '0');
                        }
                    }
                }
            }
            for (j = 0; j < last_count - 1; j++)
            {
                for (k = 0; k < last_count - 1 - j; k++)
                {
                    if (last[k] > last[k + 1])
                    {
                        int tmp = last[k];
                        last[k] = last[k + 1];
                        last[k + 1] = tmp;
                    }
                }
            }
            // 找顺子
            k = 0;
            int shunzi=0;
            while (k <= last_count - 3)
            {
                if ((last[k] / 10 == last[k + 1] / 10) && (last[k + 1] / 10 == last[k + 2] / 10) && (last[k + 1] == last[k] + 1) && (last[k + 2] == last[k] + 2))
                {
                    mianzi++;
                    k += 3;
                }
                else
                {
                    k++;
                }
            }
            if (mianzi == 2)
            {
                printf("YES\n");
            }
            for (t = 0; t < mianzi; t++)
                {
                    if (kezi_j[t] != -1)
                    {
                        used[kezi_j[t]].count=kezi_orig[t];
                    }
                }
            used[i].count=orig_i_count;
        }
    }
    printf("NO\n");
    return;
}
int main()
{
    int i, j;
    int n;
    scanf("%d", &n);
    char arr[10000][8][3];
    int num[8];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 8; j++)
        {
            scanf("%s", arr[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        judge(arr, i);
    }
    return 0;
}