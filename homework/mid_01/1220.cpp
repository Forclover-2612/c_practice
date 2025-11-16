#include <stdio.h>
#include<math.h>
#define max 1000
//储存学生数据
struct Data
{
    long long no;
    int grade[10];
    double num;
    int rank;
};
//排序时的数据
struct Sort
{
    int no;
    double num;
    int rank;
};
double calculate(int x)
{
    if (x >= 90)
        return 4.0;
    else if (x <= 89 && x >= 86)
        return 3.7;
    else if (x >= 83 && x <= 85)
        return 3.3;
    else if (x >= 80 && x <= 82)
        return 3.0;
    else if (x >= 76 && x <= 79)
        return 2.7;
    else if (x >= 73 && x <= 75)
        return 2.3;
    else if (x >= 70 && x <= 72)
        return 2.0;
    else if (x >= 66 && x <= 69)
        return 1.7;
    else if (x >= 63 && x <= 65)
        return 1.3;
    else if (x >= 60 && x <= 62)
        return 1.0;
    else
        return 0;
}
//保留以为小数的函数
double round_1(double x)
{
    // x = x * 100;
    // int n = (int)x % 10;
    // if (n >= 5)
    //     return ((int)x / 10) / 10.0 + 0.1;
    // else
    //     return ((int)x / 10) / 10.0;
    return (int)(x*10+0.5)/10.0;
}
int main()
{
    int n, m;
    int i, j;
    int point[10];
    // double num[max];
    double sum;
    double tmp;
    int min;
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++)
    {
        scanf("%d", &point[i]);
    }
    struct Data arr[max];
    for (i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i].no);
        sum = 0;
        for (j = 0; j < m; j++)
        {
            scanf("%d", &arr[i].grade[j]);
            tmp = calculate(arr[i].grade[j]);
            sum += tmp * point[j];
        }
        //放里面和放外面有什么区别
        arr[i].num = round_1(sum);

    }
    // 排序
    // 但是我如何确定输出顺序（因为我不能改变原顺序，而排序需要改变）
    // 初识想法：增加一个数组（结构体）
    // 一个保存输出顺序，一个存储真正排名，一个储存成绩
    struct Sort sort[max];
    struct Sort temp;
    for (i = 0; i < n; i++)
    {
        sort[i].no = i;
        sort[i].num = arr[i].num;
    }
    for (i = 0; i < n; i++)
    {
        int best = i;
        for (j = i + 1; j < n; j++)
        {
            if (sort[j].num > sort[best].num)
            {
                best = j;
            }
        }
        if (best != i)
        {
            temp = sort[best];
            sort[best] = sort[i];
            sort[i] = temp;
        }
        sort[i].rank = i + 1;
        // if (sort[i].num == sort[i - 1].num&&i>=1)//不能比较？？？
        if(fabs(sort[i].num-sort[i-1].num)<1e-6&&i>=1)
        {
            sort[i].rank = sort[i-1].rank;
        }
    }
    for (i = 0; i < n; i++)
    {
        for(j=0;j<n;j++)
        {
            if(sort[j].no==i)
            {
                break;
            }
        }
        printf("%lld %.1lf %d\n", arr[i].no, arr[i].num, sort[j].rank);
    }
    // printf("%.1lf",round_1(3.699));
    return 0;
}