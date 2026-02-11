#include<stdio.h>
char old[15][15];
char last[15][15];
char result[15][15];
char temp[15][15];
int judge(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(result[i][j]!=last[i][j])
            return 0;
        }
    }
    return 1;
}
void change1(int n)
{
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<n;i++)
        {
            result[j][n-1-i]=temp[i][j];
        }
    }
}
void change2(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            result[i][j]=temp[n-i-1][n-j-1];
        }
    }
}
void change3(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            result[n-j-1][i]=temp[i][j];
        }
    }
}
void change4(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            result[i][n-1-j]=temp[i][j];
        }
    }
}
int change5(int n)
{
    change4(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            temp[i][j]=result[i][j];
        }
    }
    change1(n);
    if(judge(n))
    {
        return 1;
    }
    change2(n);
    if(judge(n))
    {
        return 1;
    }
    change3(n);
    if(judge(n))
    {
        return 1;
    }
    return 0;
}

int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%c",&old[i][j]);
            temp[i][j]=old[i][j];
        }
        getchar();
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%c",&last[i][j]);
        }
        getchar();
    }
    change1(n);
    if(judge(n))
    {
        printf("1");
        return 0;
    }
    change2(n);
    if(judge(n))
    {
        printf("2");
        return 0;
    }
    change3(n);
    if(judge(n))
    {
        printf("3");
        return 0;
    }
    change4(n);
    if(judge(n))
    {
        printf("4");
        return 0;
    }
    if(change5(n))
    {
        printf("5");
        return 0;
    }
    // 修复 Case 6 的判断逻辑
    // 因为之前的 change5 操作修改了 result 和 temp，
    // 这里需要将 result 重置为 old（即原始图形），才能判断"不改变"的情况
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            result[i][j]=old[i][j];
        }
    }
    if(judge(n))
    {
        printf("6");
        return 0;
    }
    printf("7");
    return 0;
}