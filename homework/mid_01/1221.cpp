#include <stdio.h>
#include <math.h>
#define MAX 1000
int sort_value(int values[], int n)
{
    int i, j;
    int temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (values[j] > values[j + 1])
            {
                temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
        }
    }
    if (values[4] == 14 && values[0] == 2 && values[1] == 3 && values[2] == 4 && values[3] == 5)
    {
        return 1;
    }
    else
        for (i = 1; i < n; i++)
        {
            if (values[i] - values[i - 1] != 1)
            {
                return 0;
            }
        }
    return 1;
}
int judge(char arr[MAX][7][3], int num[MAX][7], int i)
{
    int j, p, t;
    int flag = 0;
    int count = 0;
    int same_color[5];
    // 注意：前两张是底牌，必须使用
    if (arr[i][0][0] == arr[i][1][0])
    {
        flag = 1;
        for (j = 2; j <= 6; j++)
        {
            if (arr[i][j][0] == arr[i][0][0])
            // 如果相同花色的，储存在另外一个数组中(但是只要储存他们的数字就好了)
            {
                same_color[count++] = num[i][j];
            }
        }
        if (count < 3)
        {
            flag = 0;
        }
        else // 进入数值判断
        {
            if (count == 3)
            {
                same_color[3] = num[i][0];
                same_color[4] = num[i][1];
                int is_straight = sort_value(same_color, 5);
                if (is_straight == 1)
                    return 0;
                else
                    return 1;
            }
            // 生成组合
            else if (count >= 4)
            {
                int has_straight = 0;
                for (j = 0; j < count; j++)
                {
                    for (t = j + 1; t < count; t++)
                    {
                        for (p = t + 1; p < count; p++)
                        {
                            int five_cards[5] = {num[i][0], num[i][1], same_color[j], same_color[t], same_color[p]};
                            int result = sort_value(five_cards, 5);
                            if (result == 1)
                            {
                                has_straight = 1;
                                break;
                            }
                            else
                                continue;
                        }
                        if (has_straight)//写法：不能直接一次判断return（在外部进行判断）
                            break;
                    }
                    if (has_straight)
                        break;
                }
                if (has_straight)
                    return 0;
                else
                    return 1;
            }
        }
    }
    if (flag == 0)//不能写else if!!!(是另外一个判断分支)
    {
        int has_straight = 0;
        for (j = 2; j < 7; j++)
        {
            for (t = j + 1; t < 7; t++)
            {
                for (p = t + 1; p < 7; p++)
                {
                    int five_cards[5] = {num[i][0], num[i][1], num[i][j], num[i][t], num[i][p]};
                    int result = sort_value(five_cards, 5);
                    if (result == 1)
                    {
                        has_straight = 1;
                        break;
                    }
                }
                if (has_straight)
                    break;
            }
            if (has_straight)
                break;
        }
        if(has_straight)
        return 2;
        else return 3;
    }
    return 3;
}
int main()
{
    int n;
    int i, j;
    scanf("%d", &n);
    char arr[MAX][7][3];
    int num[MAX][7];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 7; j++)
        {
            scanf("%s", arr[i][j]);
            if (arr[i][j][1] == '2')
                num[i][j] = 2;
            else if (arr[i][j][1] == '3')
                num[i][j] = 3;
            else if (arr[i][j][1] == '4')
                num[i][j] = 4;
            else if (arr[i][j][1] == '5')
                num[i][j] = 5;
            else if (arr[i][j][1] == '6')
                num[i][j] = 6;
            else if (arr[i][j][1] == '7')
                num[i][j] = 7;
            else if (arr[i][j][1] == '8')
                num[i][j] = 8;
            else if (arr[i][j][1] == '9')
                num[i][j] = 9;
            else if (arr[i][j][1] == '1')
                num[i][j] = 10;
            else if (arr[i][j][1] == 'J')
                num[i][j] = 11;
            else if (arr[i][j][1] == 'Q')
                num[i][j] = 12;
            else if (arr[i][j][1] == 'K')
                num[i][j] = 13;
            else
                num[i][j] = 14;
        }
        int result = judge(arr, num, i);
        if (result == 0)
        {
            printf("THS\n");
        }
        else if (result == 1)
        {
            printf("TH\n");
        }
        else if (result == 2)
        {
            printf("SZ\n");
        }
        else
            printf("GP\n");
    }
    return 0;
}