#include <stdio.h>

int N, K;
int room[12][12];
int col_used[12]; // 标记列占用
int ans = 0;

// dfs(row, count): 
// 当前正在考虑第 row 行，目前已经放置了 count 个学生
void dfs(int row, int count) {
    // 【边界条件1】学生放够了 -> 找到一种方案
    if (count == K) {
        ans++;
        return;
    }
    // 【边界条件2】行数超标了 -> 没得放了，此路不通
    if (row >= N) {
        return;
    }

    // 【策略 A】：当前第 row 行，我不放任何人（直接跳过）
    // 类似于背包问题里的 "不选这个物品"
    dfs(row + 1, count);

    // 【策略 B】：当前第 row 行，我要放一个人
    // 类似于背包问题里的 "选这个物品"（但这里要枚举选哪一列）
    for (int j = 0; j < N; j++) {
        // 判断：不是陷阱 且 列没冲突
        if (room[row][j] != -1 && !col_used[j]) {
            col_used[j] = 1;      // 标记
            dfs(row + 1, count + 1); // 去下一行，且人数+1
            col_used[j] = 0;      // 回溯
        }
    }
}

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &room[i][j]);

    dfs(0, 0); // 从第0行开始，已放0人
    printf("%d\n", ans);
    return 0;
}