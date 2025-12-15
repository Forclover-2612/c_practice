#include<stdio.h>
#include<stdbool.h>

#define MAX_NODES 10

int queue[MAX_NODES];
int front=0;
int rear=0;
//邻接矩阵：graph[i][j]=1表示i和j相连
int graph[MAX_NODES][MAX_NODES];
bool visited[MAX_NODES];
//队列操作：入队
void enqueue(int node)
{
    if(rear<MAX_NODES)
    {
        queue[rear++]=node;
    }
}
//出队（通过移动front指针实现）
int dequeue()
{
    return queue[front++];
}
//判空（头指针和尾指针相遇）
bool isQueueEmpty()
{
    return front==rear;
}
void bfs(int startNODE,int numNodes)
{
    //1.初始化访问数组
    for(int i=0;i<numNodes;i++)
    {
        visited[i]=false;
    }
    //2.起点入队
    enqueue(startNODE);
    visited[startNODE]=true;
    //3.循环直到队列为空
    while(!isQueueEmpty())
    {
        int currentNode=dequeue();
        printf("正在访问: %d\n", currentNode);
        //4.遍历所有可能的邻居
        for(int i=0;i<numNodes;i++)
        {
            if(graph[currentNode][i]==1&&!visited[i])
            {
                enqueue(i);
                visited[i]=true;
            }
        }
    }
}
//       0
//      / \
//     1   2
//    / \   \
//   3   4   5
int main()
{
    // 0 连接 1, 2
    graph[0][1] = 1; graph[0][2] = 1;
    graph[1][0] = 1; graph[2][0] = 1; // 无向图，反向也要设为1

    // 1 连接 3, 4 (0已经在上面连过了)
    graph[1][3] = 1; graph[1][4] = 1;
    graph[3][1] = 1; graph[4][1] = 1;
    //2连接5
    graph[2][5]=1;
    graph[5][2]=1;
    //总共6个点
    bfs(0,6);
    return 0;
}