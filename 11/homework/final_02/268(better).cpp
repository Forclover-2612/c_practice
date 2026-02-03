#include <stdio.h>
#include <string.h>
#include <limits.h> // 为了使用 INT_MAX

int map[50][50];
int visited[50];
int memo[50];       // 核心：一维数组记录到达该城市的最短距离
int path[200];      // 记录当前递归路径

// 【优化】直接定义全局最优解，代替结构体数组
int best_path[200];
int best_depth = 0;
int min_total_dist = INT_MAX; // 初始化为无穷大

int N, start_city, end_city;

void dfs(int curr_city, int current_dist, int depth)
{
    // 1. 【剪枝】
    // 如果当前距离已经 >= 我们之前找到的到达curr_city的最短距离，
    // 或者已经超过了目前找到的全局最短路径(min_total_dist)，直接回头
    if (current_dist >= memo[curr_city] || current_dist >= min_total_dist) {
        return;
    }

    // 2. 【更新状态】
    path[depth] = curr_city;
    memo[curr_city] = current_dist; // 更新到达当前点的最优记录

    // 3. 【终点判断】
    if (curr_city == end_city) {
        // 因为前面的剪枝保证了能走到这里的肯定是更优或者相等的
        // 但为了保险，还是判断一下是否刷新了全局最短
        if (current_dist < min_total_dist) {
            min_total_dist = current_dist;
            best_depth = depth + 1;
            // 复制当前路径到最优路径数组
            for (int i = 0; i <= depth; i++) {
                best_path[i] = path[i];
            }
        }
        return;
    }

    // 4. 【遍历邻居】
    for (int i = 0; i < N; i++) {
        // 判断是否有路(-1) 且 没有访问过(visited)
        if (map[curr_city][i] != -1 && visited[i] == 0) {
            visited[i] = 1; // 标记
            dfs(i, current_dist + map[curr_city][i], depth + 1);
            visited[i] = 0; // 回溯
        }
    }
}

int main()
{
    scanf("%d", &N);
    scanf("%d %d", &start_city, &end_city);

    // 【修正1】安全的初始化
    for (int i = 0; i < N; i++) {
        memo[i] = INT_MAX; // 初始化为无穷大
        for (int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    //为什么不能用memset(memo,INT_MAX...)
    //这是因为 memset 是 “按字节（Byte）” 进行赋值的，而不是按“整数（Int）”赋值的 
    //但是，memset 函数只取你传入数值的 后8位（即最后一个字节） 来填充每一个字节
    //所以最后是-1
    //可以用0x3f
    // 起点处理
    visited[start_city] = 1; // 起点标记为已访问
    dfs(start_city, 0, 0);

    // 【修正2】无解判断
    if (min_total_dist == INT_MAX) {
        printf("-1");
    } else {
        // 直接输出最优路径
        for (int i = 0; i < best_depth - 1; i++) {
            printf("%d->", best_path[i]);
        }
        printf("%d", best_path[best_depth - 1]);
    }

    return 0;
}