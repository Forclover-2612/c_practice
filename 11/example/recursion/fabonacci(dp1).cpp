#include<stdio.h>
long long memo[100000];
//备忘录法：递归+数组缓存
long long fibMemo(int n)
{
    if(n==0)
    return 0;
    else if(n==1)
    return 1;
    else if(memo[n]!=0)
    return memo[n];
    memo[n]=fibMemo(n-1)+fibMemo(n-2);
    return memo[n];
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%lld",fibMemo(n));
    return 0;
}