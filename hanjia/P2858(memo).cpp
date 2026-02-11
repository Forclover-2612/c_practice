#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
int n;
long long price[2005];
long long memo[2005][2005];

long long solve(int i,int j)
{
    if(i>j)
    return 0;
    if(memo[i][j]!=-1)
    return memo[i][j];
    int age=n-(j-i);
    return memo[i][j]=std::max(price[i]*age+solve(i+1,j),price[j]*age+solve(i,j-1));
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &price[i]);
    }

    memset(memo,-1,sizeof(memo));
    printf("%lld",solve(1,n));
    return 0;
}