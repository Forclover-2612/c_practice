#include <stdio.h>
#include <string.h>

struct use
{
    char str[3];
    int count;
};

// 预先把牌转成0~26的索引(b:0~8 t:9~17 w:18~26)共27张
int get_index(char s[])
{
    int type = 0;
    if (s[0] == 't')
        type = 1;
    else if (s[0] == 'w')
        type = 2;
    return type * 9 + (s[1] - '1'); // 注意是ASCII值！
}
// 回溯判断是否存在面子(三张重复或三张同花色顺子)
int can_form_mianzi(int counts[], int need)
{
    int i;
    if (need == 0)
        return 1;
    // 先判断重复
    // 不对，每次先找到最小的牌（贪心）
    // 最小的牌只有两种可能：要么自身组成刻子（三张重复），要么成为顺子的一部分
    for (i = 0; i < 27; i++)
    {
        if (counts[i] > 0)
            break;
    }
    if (i == 27)
        return 0;

    int result = 0;
    // 尝试刻子
    if (counts[i] >= 3)
    {
        counts[i] -= 3;
        // 注意：一定不能先return！一定要还回牌
        if (can_form_mianzi(counts, need - 1))
            result = 1;

        counts[i] += 3;
        if (result)
            return 1;
    }
    // 尝试刻子:不能跨花色
    result = 0;
    if (i % 9 <= 6 && counts[i + 1] > 0 && counts[i + 2] > 0)
    {
        counts[i]--;
        counts[i + 1]--;
        counts[i + 2]--;
        if (can_form_mianzi(counts, need - 1))
            result = 1;
        counts[i]++;
        counts[i + 1]++;
        counts[i + 2]++;

        if (result)
            return 1;
    }
    return 0;
}
void judge(char arr[][8][3], int n)
{
    int counts[30] = {0};
    int i;
    // 统计牌数
    for (i = 0; i < 8; i++)
    {
        counts[get_index(arr[n][i])]++;
    }
    // 枚举对子
    for (i = 0; i < 27; i++)
    {
        //注意以下内容要全部包含！！！
        if (counts[i] >= 2)
        {
            counts[i] -= 2;

            if (can_form_mianzi(counts, 2))
            {
                printf("YES\n");
                return;
            }
            // 回溯
            counts[i] += 2;
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