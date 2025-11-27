#include<stdio.h>
typedef long long ll;
ll reverse(ll num)
{
    ll rev=0,cur=num;
    while(cur)
    {
        rev=rev*10+cur%10;
        cur/=10;
    }
    return rev;
}
int main()
{
    long long num=123456789;
    printf("%lld",reverse(num));
    return 0;
}