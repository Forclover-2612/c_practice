#include<stdio.h>
#define N 9
#define D 20
int queen[N];
// int safe[N][N];
//算法优化
int col[N];//标记列
int d1[D];//标记左对角线
int d2[D];//标记右对角线
int nTotal;//计数
int n=8;
//遇到的问题，无法撤销上一次的选择，可能一列等被多个皇后控制
//解决：使用计数的数组，每次都++
void dfs(int i);
int check_safe(int i,int j);
void set_conflict(int i,int j);
void unset_conflict(int i,int j);
void output();

int main()
{
    dfs(1);
    printf("Total=%d\n",nTotal);
    return 0;
}

void dfs(int i)
{
    int j;
    if(i>n)
    {
        nTotal++;
        output();
        return;
    }
    else
    {
        for(j=1;j<=n;j++)
        {
            // queen[i]=j;//第i行的皇后放在第j列
            if(check_safe(i,j))
            {
                //优化：先检查，再放置
                queen[i]=j;
                set_conflict(i,j);
                dfs(i+1);
                // queen[i]=0;
                unset_conflict(i,j);
            }
            //注意回溯的位置
            //如果在if外面不管是否放置了皇后都会执行
            // queen[i]=0;
            // unset_conflict(i,j);
        }
    }
}
// int check_safe(int i,int j)
// {
//     return (safe[i][j]==0);
// }
// void set_conflict(int i,int j)
// {
//     int k;
//     safe[i][j]++;
//     //标记同一列
//     //标记左对角线（行列差值不变）和右对角线（行列和不变）
//     //注意k的含义？
//     for(k=1;k<=8;k++)
//     {
//         if(k==i) continue;
//         safe[k][j]++;
//         int left=k+j-i;
//         int right=i+j-k;
//         if(left>=1&&left<=8&&k!=i)
//         {
//             safe[k][left]++;
//         }
//         if(right>=1&&right<=8&&k!=i)
//         {
//             safe[k][right]++;
//         }
//     }
// }
// void unset_conflict(int i,int j)
// {
//     int k;
//     safe[i][j]--;
//     //标记同一列
//     //标记左对角线（行列差值不变）和右对角线（行列和不变）
//     //注意k的含义？
//     for(k=1;k<=8;k++)
//     {
//         if(k==i) continue;
//         safe[k][j]--;
//         int left=k+j-i;
//         int right=i+j-k;
//         if(left>=1&&left<=8&&k!=i)
//         {
//             safe[k][left]--;
//         }
//         if(right>=1&&right<=8&&k!=i)
//         {
//             safe[k][right]--;
//         }
//     }
// }
int check_safe(int i,int j)
{
    //检查列、主对角线、副对角线是否被占用
    // i-j 可能为负数，所以加 n 作为偏移量
    return (!col[j]&&!d1[i-j+n]&&!d2[i+j]);
}
void set_conflict(int i,int j)
{
    col[j]=1;
    d1[i-j+n]=1;
    d2[i+j]=1;
}
void unset_conflict(int i,int j)
{
    col[j]=0;
    d1[i-j+n]=0;
    d2[i+j]=0;
}
void output()
{
    for(int i=1;i<=8;i++)
    {
        printf("%d ",queen[i]);
    }
    printf("\n");
}
