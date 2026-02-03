#include <stdio.h>
#include <vector>
using namespace std;

int arr[2005][2005];
int memo[2005][2005]; // 存结果
int vis[2005][2005];  // 存当前的访问状态：0未访问，1正在本次路径中，2已完全处理

int m, n;
// 方向数组：0空, 1左, 2右, 3上, 4下
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};

int solve() {
    int max_len = 0;
    
    // 遍历每个点
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (memo[i][j] != 0) continue; // 算过的跳过

            vector<pair<int, int>> path;
            int curr_x = j;
            int curr_y = i;

            // 1. 模拟走路，直到撞墙、撞旧结果、或撞自己（环）
            while (curr_x >= 0 && curr_x < m && curr_y >= 0 && curr_y < n) {
                // 如果遇到计算过的，直接利用
                if (memo[curr_y][curr_x] != 0) {
                    break; 
                }
                // 如果遇到本次路径已走过的 -> 发现环！
                // 我们需要一种快速判断是否在 path 中的方法
                // 这里为了简单，用 visited 标记辅助
                if (vis[curr_y][curr_x] == 1) {
                    // 这是一个环，但我们需要知道环的起点在 path 的哪里
                    break;
                }

                vis[curr_y][curr_x] = 1; // 标记正在路径中
                path.push_back({curr_x, curr_y});

                int dir = arr[curr_y][curr_x];
                curr_x += dx[dir];
                curr_y += dy[dir];
            }

            // 2. 回溯处理 path 中的点
            int val = 0;
            
            // 情况A: 撞墙越界了 (curr_x, curr_y 不合法) -> val = 0
            // 情况B: 撞到旧结果 (memo != 0) -> val = memo[curr_y][curr_x]
            if (curr_x >= 0 && curr_x < m && curr_y >= 0 && curr_y < n) {
                if (memo[curr_y][curr_x] != 0) {
                    val = memo[curr_y][curr_x];
                    // 此时 path 里的点倒着推，依次 +1
                    for (int k = path.size() - 1; k >= 0; k--) {
                        val++;
                        int px = path[k].first;
                        int py = path[k].second;
                        memo[py][px] = val;
                        vis[py][px] = 2; // 标记处理完毕
                    }
                    path.clear(); // 清空，表示处理完了
                }
            }
            
            // 情况C: 发现环 (vis == 1 且 memo == 0)
            if (!path.empty()) {
                // 此时 curr_x, curr_y 就是环的入口（也是环的一部分）
                // 找到它在 path 中的位置
                int loop_start = -1;
                for(int k=0; k<path.size(); k++) {
                    if(path[k].first == curr_x && path[k].second == curr_y) {
                        loop_start = k;
                        break;
                    }
                }
                
                // 算出环长
                int loop_len = path.size() - loop_start;
                
                // 1. 处理环上的点：值都等于环长
                for(int k=loop_start; k<path.size(); k++) {
                     int px = path[k].first;
                     int py = path[k].second;
                     memo[py][px] = loop_len;
                     vis[py][px] = 2;
                }
                
                // 2. 处理环前面的尾巴：值 = 环长 + 距离
                int tail_val = loop_len;
                for(int k=loop_start-1; k>=0; k--) {
                    tail_val++;
                    int px = path[k].first;
                    int py = path[k].second;
                    memo[py][px] = tail_val;
                    vis[py][px] = 2;
                }
            }
        }
    }
    
    // 找最大值逻辑（略）...
    return 0;
}