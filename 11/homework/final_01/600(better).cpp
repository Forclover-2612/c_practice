#include<stdio.h>

int main()
{
    int a, b, c, d;
    if (scanf("%d %d %d %d", &a, &b, &c, &d) != 4) return 1;

    // 防止除以零错误
    if (a <= 0) return 0; 
    // 防止无限循环 (如果1个瓶子或1个盖子就能换1瓶酒，且起始有酒，则无限喝)
    if (b <= 1 || c <= 1) {
        // 这里视题目要求而定，通常题目会保证 b, c > 1
        // 如果 b=1 或 c=1，理论上是无穷大，这里简单处理为打印错误或特殊值
        return 0; 
    }

    int count = d / a; // 初始购买的数量
    int bottles = count; // 当前空瓶数
    int caps = count;    // 当前瓶盖数

    while (bottles >= b || caps >= c) {
        int new_drinks = 0;
        
        // 用空瓶换
        if (bottles >= b) {
            int exchange = bottles / b;
            new_drinks += exchange;
            bottles %= b; // 剩下的空瓶
        }

        // 用瓶盖换
        if (caps >= c) {
            int exchange = caps / c;
            new_drinks += exchange;
            caps %= c; // 剩下的瓶盖
        }

        // 统计总数
        count += new_drinks;
        
        // 新换来的饮料喝完后产生新的空瓶和瓶盖
        bottles += new_drinks;
        caps += new_drinks;
    }

    printf("%d", count);
    return 0;
}