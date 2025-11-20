#include <iostream>
#include <cstdio>
using namespace std;
int n;
struct data1
{
    int len;
    int s[2000];
}a[5000 + 5];
data1 jia(data1 a, data1 b)
{
    data1 c;
    for (int i = 0; i < 2000; i++)
        c.s[i] = 0;
    c.len = max(a.len, b.len);
    for (int i = 1; i <= max(a.len, b.len); i++)
        c.s[i + 1] = (c.s[i] + a.s[i] + b.s[i]) / 10, c.s[i] = (c.s[i] + a.s[i] + b.s[i]) % 10;
    if (c.s[c.len + 1] > 0)
        c.len++;
    return c;
}
int main()
{
    a[1].len = a[2].len = 1;
    a[1].s[1] = 1;
    a[2].s[1] = 2;
    scanf("%d", &n);
    if (n == 0)
    {
        printf("0");
        return 0;
    }
    for (int i = 3; i <= n; i++)
        a[i] = jia(a[i - 1], a[i - 2]);
    for (int i = a[n].len; i > 0; i--)
        cout << a[n].s[i];
    return 0;
}
