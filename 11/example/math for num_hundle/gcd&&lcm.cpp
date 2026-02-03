#include <stdio.h>
#include <math.h> // 用于 abs (虽然也可以手写)

// 求最大公约数 (使用 long long 防止溢出)
long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a,int b)
{
    return (a/gcd(a,b))*b;
}
int main() {
    long long a1, a2, b1, b2;
    // 使用 %lld 读取 long long 类型
    if (scanf("%lld %lld %lld %lld", &a1, &a2, &b1, &b2) != 4) return 0;

    // 1. 直接通分公式：(a1*b2 + b1*a2) / (a2*b2)
    // 这样就不需要单独写 lcm 函数了
    long long num = a1 * b2 + b1 * a2; // 分子
    long long den = a2 * b2;           // 分母

    // 2. 约分
    // 注意：为了方便处理符号，通常取绝对值求 GCD，或者直接求完后处理符号
    long long common = gcd(num, den);
    num /= common;
    den /= common;

    // 3. 符号规范化：保证分母永远为正
    // 如果分母是负数 (例如 1/-2)，将分子分母都变号 -> -1/2
    if (den < 0) {
        num = -num;
        den = -den;
    }

    printf("%lld/%lld", num, den);
    return 0;
}