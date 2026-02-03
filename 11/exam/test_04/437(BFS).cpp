#include <stdio.h>
#include <string.h>
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};
int N;
int map[12][12];
typedef struct
{
    int x, y, dist;
} Node;

int bfs(int start_x, int start_y, int target_x, int target_y)
{
    // 1.起点入队
    int front = 0;
    int rear = 0;
    Node queue[150];
    int visited[12][12];
    // 一定要进行初始化
    memset(visited, 0, sizeof(visited));
    queue[front].x = start_x;
    queue[front].y = start_y;
    //修改：初始化起点的距离为0
    queue[front].dist=0;
    rear++; // 尾指针要记得++
    // 标记已经走过
    visited[start_x][start_y] = 1;
    // 2.开始循环
    while (front < rear)
    {
        // 3.判断是否到达终点
        // 取出队头元素
        Node cur = queue[front++]; // 先使用，后++
        if (cur.x == target_x && cur.y == target_y)
        {
            return cur.dist;
        }
        // 4.向四周扩散
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            // 5.合法性检查并将新的格子入队
            if (nx >= 0 && ny >= 0 && nx < N && ny < N && visited[nx][ny] != 1&&map[nx][ny]!=1)
            {
                visited[nx][ny] = 1;
                // 新格子入队
                queue[rear].x = nx;
                queue[rear].y = ny;
                //步数+1
                queue[rear].dist=cur.dist+1;
                rear++;
            }
        }
    }
    return -1;
}
int main()
{
    scanf("%d", &N);               // 输入地图大小
    int pos1[2], pos2[2], pos3[2]; // 用来存 2, 3, 4 的坐标

    // 读取地图
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &map[i][j]);
            // 记录关键点的位置
            if (map[i][j] == 2)
            {
                pos1[0] = i;
                pos1[1] = j;
            } // 起点
            else if (map[i][j] == 3)
            {
                pos2[0] = i;
                pos2[1] = j;
            } // 中转点
            else if (map[i][j] == 4)
            {
                pos3[0] = i;
                pos3[1] = j;
            } // 终点
        }
    }
    int len1=bfs(pos1[0],pos1[1],pos2[0],pos2[1]);
    int len2=bfs(pos2[0],pos2[1],pos3[0],pos3[1]);
    printf("%d\n",len1+len2);
    return 0;
}