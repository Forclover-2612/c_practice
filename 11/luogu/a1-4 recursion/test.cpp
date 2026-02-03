#include<stdio.h>
// long long res;
long long count(int n, int x, int y) {
    if (x == 0 && y == n)
        return 1;
    if (x < 0 || y > n)
        return 0;
    long long res = 0;
    if (x > 0)
        res += count(n, x - 1, y + 1);
    if (y > 0)
        res += count(n, x, y - 1);
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%lld", count(n, n, 0));
    return 0;
}