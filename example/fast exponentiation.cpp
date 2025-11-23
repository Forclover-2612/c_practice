#include<stdio.h>
//相当于是把指数看成二进制数（拆分指数）
long long qpow(long long a,int n,int mod)//a是底数，配合取模运算，b是指数
{
    //模运算的结合律:所有数都取模后取模=所有数相乘后再取模
    //如果结果不取模的话，对所有的数也不应该取模
    long long ans=1;
    a%=mod;
    while(n>0)
    {
        if(n&1)//如果最后一位是1
        {
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        n>>=1;//右移一位，相当于除以2
    }
    return ans;
}
int main()
{
    long long k=qpow(15,2,100);
    printf("%lld",k);
    return 0;
}