#include<stdio.h>

int reverse(int n)
{
    int m=n;
    int rev=0;
    while(m)
    {
        rev=rev*10+m%10;
        m/=10;
    }
    return rev;
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",reverse(n));
    return 0;
}