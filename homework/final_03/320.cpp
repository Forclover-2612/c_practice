#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int fama[15][2];
// int weight[205];
struct Data
{
    int weight;
    long long count;
};
Data obj[205];
// 记忆要用二维数组（加上index的原因：之前的方法已经不能再用了）
long long memo[15][20000]; // 从第index种砝码开始，凑出rest有多少种方法
int M, N;
// void search(int index,int sum,int num,long long depth,int i,int n)
// {
//     if(sum==num)
//     {
//         obj[i].count=depth;
//         return;
//     }
//     for(int i=index;i<n;i++)
//     {
//         if(sum+fama)
//     }
// }
void search(int index, int rest, int i) // 砝码的下标
{
    if (rest == 0)
    {
        obj[i].count++;
        return;
    }
    if (index >= N)
        return;
    int max = rest / fama[index][0];
    int num = (max < fama[index][1]) ? max : fama[index][1];
    for (int j = num; j >= 0; j--)
    {
        search(index + 1, rest - j * fama[index][0], i);
    }
}
long long dfs(int index, int rest)
{
    if (rest == 0)
        return 1;
    if (index >= N)
        return 0;
    if(memo[index][rest]!=-1)
    return memo[index][rest];
    int max = rest / fama[index][0];
    int num = (max < fama[index][1]) ? max : fama[index][1];
    int total=0;
    for (int j = num; j >= 0; j--)
    {
        total+=dfs(index + 1, rest - j * fama[index][0]);
    }
    return memo[index][rest]=total;
}
int cmp(const void *a, const void *b)
{
    const Data *x = (const Data *)a;
    const Data *y = (const Data *)b;
    if (x->count != y->count)
        return (x->count < y->count) ? 1 : -1;
    return x->weight - y->weight;
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    N = n, M = m;
    for(int i=0;i<15;i++)
    {
        memset(memo[i],-1,sizeof(memo[0]));
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &fama[i][0]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &fama[i][1]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &obj[i].weight);
    }
    for (int i = 0; i < m; i++)
    {
        // search(0, obj[i].weight, i);
        dfs(0,obj[i].weight);
        obj[i].count=memo[0][obj[i].weight];
    }
    qsort(obj, m, sizeof(Data), cmp);
    for (int i = 0; i < m; i++)
    {
        printf("%d:%lld\n", obj[i].weight, obj[i].count);
    }
    return 0;
}