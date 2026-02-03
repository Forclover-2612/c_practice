#include <stdio.h>
int dicimal_digit[100];
int remain_map[100]; // 一个映射表，储存新的余数，便于判断是否出现循环节
// 为什么不是在小数列表中寻找：不好判断
int idx;
int flag;
void to_decimal(int remain, int n, int m) // n/m
{
    int i,j;
    //有限小数
    if(remain==0)
    {
        printf("%d.",n/m);
        for(i=0;i<idx;i++)
        {
            printf("%d",dicimal_digit[i]);
        }
        return;
    }
    for (i = 0; i < idx; i++)
    {
        if (remain == remain_map[i])
        {
            flag=1;
            printf("%d.", n / m);
            for(j=0;j<i;j++)
            {
                printf("%d",dicimal_digit[j]);
            }
            printf("(");
            for(j=i;j<idx;j++)
            {
                printf("%d",dicimal_digit[j]);
            }
            printf(")");
            return;
        }
    }
    if(!flag)
    {
        dicimal_digit[idx]=remain*10/m;
        remain_map[idx]=remain;//存入当前的映射表
        remain=remain*10%m;
        idx++;
        return to_decimal(remain,n,m);
    }
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    // double p=(double)n/m;
    if(n%m==0)
    {
        printf("%d.0",n/m);
    }
    else{
        to_decimal(n%m,n,m);
    }
    return 0;
}