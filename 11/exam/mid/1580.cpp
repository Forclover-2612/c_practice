#include <stdio.h>
#include <string.h>
struct Data
{
    char name[30];
    int count;
};
int main()
{
    // freopen("error (2).in","r",stdin);
    int n, k, m; // n次投票，可以投k次，m个候选人
    scanf("%d %d %d", &n, &k, &m);
    struct Data stu[101];
    char s[30];
    char str[1000][30];
    int i, j, t;
    int max;
    int flag = 0;
    int flag_end=0;
    int flag_samename=0;
    int num = 0;
    char ch;
    int cou; // 临时计数的变量
    // while (1)
    // {
    //     scanf("%s", s);
    //     getchar();
    //     flag = 0;
    //     if (strcmp(s, "END") == 0)
    //         break;
    //     for (i = 0; i < num; i++)
    //     {
    //         if (strcmp(stu[i].name, s) == 0)
    //         {
    //             flag = 1;
    //             break;
    //         }
    //     }
    //     if (!flag)
    //     {
    //         strcpy(stu[num].name, s);
    //         stu[num].count = 0;
    //         stu[num].count++;
    //         num++;
    //     }
    //     else
    //     {
    //         stu[i].count++;
    //     }
    // }
    while(1)//理解有误！！！
    {
        flag_samename=0;//标志选票中重复的
        flag = 0;//标志后面统计中重复的
        cou = 0;
        do
        {
            scanf("%s", s);
            if(strcmp(s,"END")==0)
            {
                flag_end=1;
                break;
            }
            strcpy(str[cou], s);
            cou++;
        } while ((ch = getchar()) != '\n');
        //如果是END，退出
        if(flag_end==1)
        break;
        // 先判断选票是否符合题意
        if (cou > k)
            continue;
        // 怎么判断相同元素？（往前遍历吗）
        else
        {
            for (j = 0; j < cou; j++)
            {
                for (t = 0; t <j; t++)
                {
                    if (strcmp(str[j], str[t]) == 0)
                    {
                        flag_samename = 1;
                        break;
                    }
                }
                if (flag_samename == 1)
                    break;
            }
        }
        if (flag_samename == 1)
            continue;
        // 剩下的储存下来
        for (j = 0; j < cou; j++)
        {
            flag=0;
            for (t = 0; t < num; t++)
            {
                if (strcmp(stu[t].name, str[j]) == 0)
                {
                    flag = 1;
                    break;
                }
            }
            if (!flag)
            {
                strcpy(stu[num].name, str[j]);
                stu[num].count = 0;
                stu[num].count++;
                num++;
            }
            else
            {
                stu[t].count++;
            }
        }
    }
    flag = 0;
    struct Data temp;
    cou = 0;
    //统计是否有人大于半数票数
    for (i = 0; i < num; i++)
    {
        if (stu[i].count*2 >= n)//注意大于半数票数的写法
        {
            flag = 1;
            cou++;
        }
    }
    //先对整体排序
    for (i = 0; i < num; i++)
    {
        max = i;
        for (j = i + 1; j < num; j++)
        {
            if (stu[j].count > stu[max].count)
            {
                max = j;
            }
            // else if (stu[j].count == stu[max].count && stu[j].name[0] < stu[max].name[0])
            // {
            //     max = j;
            // }
            //按照字典序进行名字排序
            else if(stu[j].count==stu[max].count)
            {
                if(strcmp(stu[j].name,stu[max].name)<0)//比较方便的写法
                {
                    max=j;
                }
            }
        }
        if (max != i)
        {
            temp = stu[max];
            stu[max] = stu[i];
            stu[i] = temp;
        }
    }
    if (flag == 1)
    {
        for (i = 0; i < cou; i++)
        {
            printf("%s %d\n", stu[i].name, stu[i].count);
        }
    }
    else
    {
        if (num <= m)
        {
            for (i = 0; i < num; i++)
            {
                printf("%s %d\n", stu[i].name, stu[i].count);
            }
        }
        else
        {
            for (i = 0; i < m; i++)
            {
                printf("%s %d\n", stu[i].name, stu[i].count);
            }
            while (i < num && stu[i].count == stu[i - 1].count)
            {
                printf("%s %d\n", stu[i].name, stu[i].count);
                i++;
            }
        }
    }
    return 0;
}