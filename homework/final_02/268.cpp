#include<stdio.h>
#include<string.h>
#include<limits.h>
int map[50][50];//邻接矩阵
int visited[50];
int memo[50];//都变成一维数组，表示我在哪一个城市（从起点走到这个城市的距离）
int path[200];
// int total_path[50][200];
// int distance;
int count=0;
int start_city,end_city;
int N;
struct Data{
    int Path[200];
    int Count;
    int distance;
};
Data total[100];//没必要完全存下来，只要存第一个
void dfs(int curr_city,int route,int depth)
{
    //还是dfs加可行性剪枝
    //自动切断了环路
    if(route>memo[curr_city])
    {
        return;
    }
    path[depth]=curr_city;
    memo[curr_city]=route;//思考：是不是不用加上了
    if(curr_city==end_city)
    {
        //得到一条可行路径，储存
        total[count].Count=depth+1;
        total[count].distance=route;
        for(int i=0;i<depth+1;i++)
        {
            // total_path[count][i]=path[i];
            total[count].Path[i]=path[i];
        }
        count++;
        return;
    }
    for(int i=0;i<N;i++)
    {
        if(visited[i]==1||map[curr_city][i]==-1)
        continue;
        if(route+map[curr_city][i]<memo[i])
        {
            visited[i]=1;

            dfs(i,route+map[curr_city][i],depth+1);
            visited[i]=0;
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    N=n;
    int s,d;
    scanf("%d %d",&s,&d);
    start_city=s;
    end_city=d;
    memset(memo,10,sizeof(memo));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&map[i][j]);
        }
    }
    visited[s]=1;
    dfs(s,0,0);
    // printf("%d",memo[d]);
    if(count==0)
    {
        printf("-1");
        return 0;
    }
    //排序
    for(int i=0;i<count;i++)
    {
        int min=i;
        for(int j=i+1;j<count;j++)
        {
            if(total[j].distance<total[min].distance)
            min=j;
            else if(total[j].Count==total[min].Count)
            {
                for(int t=0;t<total[j].Count;t++)
                {
                    if(total[j].Path[t]<total[min].Path[t])
                    {
                        min=j;
                        break;
                    }
                }
            }
        }
        if(min!=i)
        {
            Data temp;
            temp=total[min];
            total[min]=total[i];
            total[i]=temp;
        }
    }
    for(int i=0;i<total[0].Count-1;i++)
    {
        printf("%d->",total[0].Path[i]);
    }
    printf("%d",d);
    return 0;
}