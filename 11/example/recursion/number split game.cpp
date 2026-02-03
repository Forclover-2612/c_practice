#include <stdio.h>
int D[11];
int temp_ans[200];
int path[200];
void find(int s, int sum, int m, int index, int depth)
{
    if (sum == s)
    {
        for (int i = 0; i < depth; i++)
        {
            printf("%d ", temp_ans[i]);
        }
        printf("\n");
        return;
    }
    if (sum > s)
        return;
    // 我可以重复选当前这个数字
    // 下一层传的还是相同的数字
    for (int i = index; i < m; i++)
    {
        temp_ans[depth] = D[i];
        find(s, sum + D[i], m, i, depth + 1);
    }
}
//better:背包视角：选或者不选
void dfs(int current_sum, int index,int depth,int s,int m)
{
    if(current_sum==s)
    {
        return;
    }
    if(current_sum>s||index==m)
    {
        return;
    }
    //策略1：选当前数字
    path[depth]=D[index];
    dfs(current_sum+D[index],index,depth+1,s,m);
    //策略2：不选或者选够了当前数字
    dfs(current_sum,index+1,depth,s,m);
}
// 不要一层层地“选哪个数”，而是对于集合里的每个数字，一次性决定“选几个”。
// 没有想到的点：怎么取回溯，控制输出的长度
// 维护一个全局变量top
int top = 0;
void my_dfs(int index, int rest,int m)
{
    //成功的边界
    if (rest == 0)
    {
        for (int i = 0; i < top; i++)
        {
            printf("%d ", path[i]);
        }
        printf("\n");
        return;
    }
    //失败的边界
    if(index>=m)
    {
        return;
    }
    int curr_num = D[index];
    int max_k = rest / curr_num;
    for (int k = max_k; k >= 0; k--)
    {
        // 填入k个数字
        for (int i = 0; i < k; i++)
        {
            path[top++] = curr_num;
        }
        my_dfs(index + 1, rest - k*curr_num,m);
        //记得回溯
        top-=k;
    }
}
int main()
{
    int s, m;
    scanf("%d %d", &s, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &D[i]);
    }
    // 一个数字可以取多次而且不可以出现重复方案
    // 主动的避免重复（每次传入上一次的index，从当前开始）
    // find(s, 0, m, 0, 0);
    my_dfs(0,s,m);
    return 0;
}
//两种思路：我的思路是“批处理”（纵向枚举），简化的代码是“流式处理”（二叉树分支）