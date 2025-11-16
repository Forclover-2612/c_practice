#include <stdio.h>
int com1(int a, int b)
{
    int max = (a > b) ? a : b;
    int min = (a < b) ? a : b;
    int i;
    for (i = max;; i += max)
    {
        if (i % min == 0)
            break;
    }
    return i;
}
int com2(int a, int b)
{
    int max = (a > b) ? a : b;
    int min = (a < b) ? a : b;
    int i;
    for(i=min;i>=1;i--)
    {
        if(max%i==0&&min%i==0)
        break;
    }
    return i;
}
int main()
{
    int a1, a2;
    int b1, b2;
    scanf("%d %d %d %d", &a1, &a2, &b1, &b2);
    int com_n = com1(a2, b2);
    a1 = com_n / a2 * a1;
    b1 = com_n / b2 * b1;
    int num = a1 + b1;
    int com_m=com2(num,com_n);
    printf("%d/%d",num/com_m,com_n/com_m);
    return 0;
}