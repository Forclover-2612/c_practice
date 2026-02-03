#include <stdio.h>
#include <string.h>
struct Data
{
    char name[30];
    int count;
};
int main()
{
    int n, k, m;
    scanf("%d %d %d",&n,&k,&m);
    struct Data stu[200] = {0};
    int num=0;

    char line[1000];
    // 整行读入的写法
    while (1)
    {
        fgets(line, sizeof(line), stdin); // 读取一行输入
        // fgets会读入\n
        line[strcspn(line, "\n")] = 0;
        // 去除换行符
        if (strcmp(line, "END") == 0)
            break;

        char *token = strtok(line, " \t"); // 第一次调用
        char names[100][30] = {0};        // 每次进行初始化
        int cou = 0;
        while (token != NULL)
        {
            strcpy(names[cou], token);
            cou++;
            token = strtok(NULL, " \t");//空格和制表符
        }
        // 检查选票有效性
        int valid = 1;
        if (cou > k)
            valid = 0;
        if (valid)
        {
            for (int i = 0; i < cou; i++)
            {
                for (int j = i + 1; j < cou; j++)
                {
                    if (strcmp(names[i], names[j]) == 0)
                    {
                        valid = 0;
                        break;
                    }
                }
                if (!valid)
                    break;
            }
        }
        // 选票有效，进行处理
        if (valid)
        {
            for (int i = 0; i < cou; i++)
            {
                int found = 0;
                for (int j = 0; j < num;j++)
                {
                    if (strcmp(stu[j].name, names[i]) == 0)
                    {
                        stu[j].count++;
                        found = 1;
                        break;
                    }
                }
                if (!found)
                {
                    strcpy(stu[num].name, names[i]);
                    stu[num].count = 1;
                    num++;
                }
            }
        }
    }

    return 0;
}