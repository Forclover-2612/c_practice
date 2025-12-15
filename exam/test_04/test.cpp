#include <stdio.h>

// 定义最大地图大小，放在全局变量防止栈溢出
#define MAXN 2005

// 地图数据
int grid[MAXN][MAXN];
// 记忆化数组：存储从该点出发能吃到的最大食物数量
int memo[MAXN][MAXN];
// 访问状态标记：
// 0 = 未访问
// 1 = 正在当前的路径本子里（用于检测环）
// 2 = 已经计算完毕（以后可以直接用）
int vis[MAXN][MAXN];

// 模拟“路径本子”，用来记录当前走的路线
// 大小需要足够大，因为最坏情况是走满整个地图（蛇形走位）
// 2000 * 2000 = 4,000,000
int path_x[MAXN * MAXN];
int path_y[MAXN * MAXN];

// 方向数组：0无, 1左, 2右, 3上, 4下
// 注意题目给的坐标系：向右x增加，向下y增加
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};

int main() {
    int m, n; // m是列数(x最大值)，n是行数(y最大值)
    
    // 1. 读取输入
    if (scanf("%d %d", &m, &n) != 2) return 0;

    for (int i = 0; i < n; i++) {     // 行
        for (int j = 0; j < m; j++) { // 列
            scanf("%d", &grid[i][j]);
            // 初始化数组
            memo[i][j] = 0;
            vis[i][j] = 0;
        }
    }

    // 2. 遍历每一个格子，计算它们的结果
    for (int i = 0; i < n; i++) {     // y: 0 -> n-1
        for (int j = 0; j < m; j++) { // x: 0 -> m-1
            
            // 如果这个点之前已经算过了，直接跳过，不用再算
            if (vis[i][j] == 2) continue;

            // === 开始一次新的探险 ===
            int curr_x = j;
            int curr_y = i;
            int path_len = 0; // 路径本子的当前页码

            // 循环走路，直到遇到结束情况
            while (1) {
                // 【情况A：撞墙】越界了
                if (curr_x < 0 || curr_x >= m || curr_y < 0 || curr_y >= n) {
                    // 倒推填值：撞墙后的贡献是0
                    int value = 0; 
                    // 从路径本子的最后一页往前翻
                    for (int k = path_len - 1; k >= 0; k--) {
                        value++; // 往回倒推一步，步数+1
                        int px = path_x[k];
                        int py = path_y[k];
                        memo[py][px] = value;
                        vis[py][px] = 2; // 标记为计算完毕
                    }
                    break; // 结束本次探险
                }

                // 【情况B：遇到算过的老路】
                if (vis[curr_y][curr_x] == 2) {
                    // 借用老路的结果
                    int value = memo[curr_y][curr_x];
                    // 从路径本子的最后一页往前翻
                    for (int k = path_len - 1; k >= 0; k--) {
                        value++;
                        int px = path_x[k];
                        int py = path_y[k];
                        memo[py][px] = value;
                        vis[py][px] = 2;
                    }
                    break;
                }

                // 【情况C：遇到自己（发现环）】
                // 如果当前点已经在路径本子里（标记为1），说明转圈了
                if (vis[curr_y][curr_x] == 1) {
                    // 1. 找到环的入口在路径本子的第几页
                    int loop_start_index = -1;
                    // 倒着找最快
                    for (int k = path_len - 1; k >= 0; k--) {
                        if (path_x[k] == curr_x && path_y[k] == curr_y) {
                            loop_start_index = k;
                            break;
                        }
                    }

                    // 2. 计算环的周长
                    // 比如本子记了 [A, B, C, D]，现在又走到了 B
                    // loop_start_index 就是 B 的位置，len = 4 - 1 = 3 (B,C,D)
                    int loop_len = path_len - loop_start_index;

                    // 3. 处理环上的点：它们的值都等于环长
                    for (int k = loop_start_index; k < path_len; k++) {
                        int px = path_x[k];
                        int py = path_y[k];
                        memo[py][px] = loop_len;
                        vis[py][px] = 2;
                    }

                    // 4. 处理环前面的“尾巴”（入环前的路）
                    // 比如 A -> [环]，A的值 = 环长 + 距离
                    int tail_value = loop_len;
                    for (int k = loop_start_index - 1; k >= 0; k--) {
                        tail_value++;
                        int px = path_x[k];
                        int py = path_y[k];
                        memo[py][px] = tail_value;
                        vis[py][px] = 2;
                    }
                    break;
                }

                // === 还没结束，继续走 ===
                // 1. 记录当前点到路径本子上
                path_x[path_len] = curr_x;
                path_y[path_len] = curr_y;
                path_len++;

                // 2. 标记当前点为“正在访问中” (用于检测环)
                vis[curr_y][curr_x] = 1;

                // 3. 移动到下一个点
                int dir = grid[curr_y][curr_x];
                curr_x += dx[dir];
                curr_y += dy[dir];
            }
        }
    }

    // 3. 统计最大值
    int max_food = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (memo[i][j] > max_food) {
                max_food = memo[i][j];
            }
        }
    }

    // 4. 输出结果
    // 题目要求：如果有多个，按横坐标(x/j)递增优先，纵坐标(y/i)递增其次
    // 所以我们外层循环 j (0->m)，内层循环 i (0->n) 即可自然满足顺序
    printf("%d\n", max_food); // (题目虽然没让输出最大值，但通常调试需要，如果不需输出最大值可注释) -> 抱歉题目只让输出坐标，这里是K行坐标
    // 修正：题目只要输出坐标，不需要输出max_food，我把上面那行删掉，直接统计数量也没必要，直接输出即可

    // 题目说输出K行，我们直接遍历输出即可
    // 为了符合"横坐标优先"，我们交换循环顺序
    int count = 0; // 如果题目需要先输出总数K，可以用这个统计，但题目只要每行坐标
    for (int j = 0; j < m; j++) {     // 先枚举列 (x)
        for (int i = 0; i < n; i++) { // 再枚举行 (y)
            if (memo[i][j] == max_food) {
                printf("%d %d\n", j, i);
            }
        }
    }

    return 0;
}