#include <stdio.h>

// 两个数组，也就是两个小本子
// remainders: 记录每一次除法剩下的余数
// quotients: 记录每一次除法得到的商（也就是小数位的数字）
int remainders[10005]; 
int quotients[10005]; 
//本质上是一道模拟题
int main() {
    int n, d;
    scanf("%d %d", &n, &d);

    // 1. 先处理整数部分，直接除就行
    printf("%d.", n / d);
    
    // 拿到第一步的余数
    int r = n % d;
    
    // 如果一开始余数就是0，说明整除，题目要求输出 x.0
    if (r == 0) {
        printf("0");
        return 0;
    }

    int idx = 0; // 记录我们要算出的小数位数
    int loop_start = -1; // 用来记录循环从哪里开始

    // 2. 开始模拟竖式除法 (只要余数不为0，且没有发现循环，就一直算)
    while (r != 0 && loop_start == -1) {
        // 记录当前的余数，万一后面遇到了，就知道是循环了
        remainders[idx] = r;
        
        // 模拟竖式：余数补0 (乘以10)
        r *= 10;
        
        // 算出这一位的商，存起来
        quotients[idx] = r / d;
        
        // 算出新的余数，为下一轮做准备
        r = r % d;
        
        idx++; // 位数+1

        // 3. 关键步骤：检查这个新余数 r 是否在之前出现过？
        // 这一步就是原本代码里递归最让人晕的地方，我们用简单的循环来找
        for (int k = 0; k < idx; k++) {
            if (remainders[k] == r) {
                loop_start = k; // 找到了！循环是从第 k 位开始的
                break;
            }
        }
    }

    // 4. 输出结果
    // 如果 loop_start 还是 -1，说明是除尽了（r变成了0）
    if (loop_start == -1) {
        for (int i = 0; i < idx; i++) {
            printf("%d", quotients[i]);
        }
    } 
    else {
        // 有循环节
        // 先输出括号前的部分
        for (int i = 0; i < loop_start; i++) {
            printf("%d", quotients[i]);
        }
        printf("(");
        // 再输出括号里的部分（循环节）
        for (int i = loop_start; i < idx; i++) {
            printf("%d", quotients[i]);
        }
        printf(")");
    }

    return 0;
}