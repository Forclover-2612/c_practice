#include <stdio.h>
int used[105];
int group[105][105];
int groupSize[105];
int belong[105];
int idx[105];
int result[105];
int cnt = 0;
// 关于思路：分组：如果在固定工序内，就看idx在哪里从而进行选择
// 如果是独立工序，没有被用过的话可以直接使用
//根据答案的要求：这里面每组工序都必须整体使用
// int canUse(int num)
// {
//     if(used[num]==1)
//     return 0;
//     if(belong[num]==0)
//     return 1;
//     //对属于某组的工序进行分析
//     if(group[belong[num]][idx[belong[num]]]==num)
//     return 1;
//     return 0;
// }
void dfs(int depth, int n)
{
    if (depth == n)
    {
        cnt++;
        printf("%d. ", cnt);
        for (int i = 0; i < n; i++)
        {
            printf("%d ",result[i]);
        }
        printf("\n");
        return;
    }
    for(int i=1;i<=n;i++)
    {
        // if(canUse(i))
        // {
        //     used[i]=1;
        //     result[depth]=i;
        //     if(belong[i])
        //     {
        //         idx[belong[i]]++;
        //     }
        //     dfs(depth+1,n);
        //     //回溯
        //     if(belong[i])
        //     {
        //         idx[belong[i]]--;
        //     }
        //     used[i]=0;
        // }
        if(used[i])
        continue;
        //1.独立工序
        if(belong[i]==0)
        {
            used[i]=1;
            result[depth]=i;
            dfs(depth+1,n);
            used[i]=0;
        }
        //2.某组的第一道工序
        //接下来只能在这组里面和独立工序中选择
        else if(group[belong[i]][0]==i)
        {
            //在这组元素里面回溯？？？
            //不对，直接填入整个数组
            //获取组号
            int num=belong[i];
            int g=groupSize[num];
            for(int j=0;j<g;j++)
            {
                // result[depth++]=group[i][j];
                //不能用depth++,修改了局部变量，返回时是错误的
                result[depth+j]=group[num][j];
                used[group[num][j]]=1;
            }
            dfs(depth+g,n);
            for(int j=0;j<g;j++)
            {
                used[group[num][j]]=0;
            }
        }
    }
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    //编号问题：从哪里开始要统一起来
    for (int i = 1; i <= m; i++)
    {
        //考虑：工序数量是不是也要存下来？？？
        // int num;
        // scanf("%d", &num);
        scanf("%d",&groupSize[i]);
        for (int j = 0; j < groupSize[i]; j++)
        {
            scanf("%d", &group[i][j]);
            belong[group[i][j]]=i;
        }
    }
    dfs(0, n);
    return 0;
}