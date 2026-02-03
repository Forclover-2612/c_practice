#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 方向：0无, 1左, 2右, 3上, 4下
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};

int m, n;
int grid[2005][2005];
int memo[2005][2005]; // 存最终结果
int vis[2005][2005];  // 0:未访问, 1:正在递归栈中, 2:计算完成

// 辅助结构：用于在发现环时，快速回溯找到环上的所有点
struct Point { int x, y; };
vector<Point> path_stack; // 模拟系统的调用栈

int dfs(int x, int y) {
    // 1. 如果越界（撞墙）
    if (x < 0 || x >= m || y < 0 || y >= n) {
        return 0;
    }

    // 2. 如果已经计算完成（遇到老祖宗留下的路标）
    if (vis[y][x] == 2) {
        return memo[y][x];
    }

    // 3. 如果遇到“正在访问中”的点 -> 【发现环了！】
    if (vis[y][x] == 1) {
        // 这时候，path_stack 里存着当前路径：A -> B -> C -> ...
        // 而 (x, y) 就是环的入口。
        // 我们需要算出环长，但这在单纯的 return 里很难更新所有点。
        // 所以我们在这里返回一个特殊标记（比如 -1），让上层函数去处理环。
        return -1; 
    }

    // 4. 正常递归流程
    vis[y][x] = 1; // 标记为“正在访问”
    path_stack.push_back({x, y}); // 入栈

    int next_x = x + dx[grid[y][x]];
    int next_y = y + dy[grid[y][x]];

    int res = dfs(next_x, next_y);

    // 5. 递归回来后的处理（最关键的部分）
    
    // 情况 A: 下面返回了 -1，说明下面发现了环
    if (res == -1) {
        // 判断我自己是不是也在环里？
        // 环的特征是：如果我是环的一部分，那么我的 memo 还没被填。
        // 这个逻辑比较复杂，我们换一种简单粗暴的策略：
        // 在发现环的那一刻（上面第3步），我们其实很难把环长传回来。
        
        // 既然一定要用递归，这里有一个 trick：
        // 我们利用全局的 path_stack 来处理环。
        // 如果发现是环模式，我们暂时不填 memo，等待这一层递归结束，
        // 在外层循环里统一填，或者...
        
        // 实际上，递归写这种带环图非常痛苦。
        // 为了让你看懂，我们将逻辑简化：
        // 如果遇到了环，我们不通过 return 传递长度，而是直接操作 memo。
        return -1; 
    }
    
    // 情况 B: 下面返回了正常数值（说明没环，或者是撞墙了，或者是接上了旧路）
    // 这里的 res 就是 next 的长度
    memo[y][x] = res + 1;
    vis[y][x] = 2; // 标记为计算完成
    path_stack.pop_back(); // 出栈
    return memo[y][x];
}

// 上面的 DFS 很难完美处理环，因为当 B 发现环 A 时，B 还没 return，
// 栈里的 C, D, E 都在等 B。B 很难通知 CDE "你们都在环里"。

// ==========================================
// 【修正版】真正可行的递归写法 (结合 Tarjan 缩点思想的简化版)
// ==========================================

int solve_recursive(int x, int y) {
    // 1. 越界
    if (x < 0 || x >= m || y < 0 || y >= n) return 0;
    
    // 2. 记忆化直接返回
    if (memo[y][x] != 0) return memo[y][x];

    // 3. 记录当前点进栈
    path_stack.push_back({x, y});
    vis[y][x] = 1; // 在栈中

    int nx = x + dx[grid[y][x]];
    int ny = y + dy[grid[y][x]];

    if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
        if (vis[ny][nx] == 1) { 
            // 【发现环！】 (ny, nx) 是环入口
            // 此时 path_stack 里从 (ny, nx) 到栈顶的所有元素都在环里
            
            // 倒序遍历栈，找到入口
            int loop_len = 0;
            int start_index = -1;
            
            // 这一步是为了算环长
            for (int i = path_stack.size() - 1; i >= 0; i--) {
                loop_len++;
                if (path_stack[i].x == nx && path_stack[i].y == ny) {
                    start_index = i;
                    break;
                }
            }
            
            // 直接在这里把环上所有点的 memo 都填好！
            // 这样回溯回去的时候，大家都有值了
            for (int i = start_index; i < path_stack.size(); i++) {
                memo[path_stack[i].y][path_stack[i].x] = loop_len;
                vis[path_stack[i].y][path_stack[i].x] = 2; // 标记处理完
            }
            
            // 返回环长，给指向环的那些“尾巴”用
            path_stack.pop_back();
            return loop_len;
        }
    }

    // 递归下去
    int sub_res = solve_recursive(nx, ny);

    // 回溯阶段
    // 如果 memo[y][x] 已经被上面的“发现环”逻辑填过了，就不要覆盖它
    if (memo[y][x] == 0) {
        memo[y][x] = sub_res + 1;
        vis[y][x] = 2;
    }
    
    path_stack.pop_back();
    return memo[y][x];
}

int main() {
    // ... 输入代码略 ...
    // 调用 solve_recursive
}