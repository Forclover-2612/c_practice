#include<stdio.h>
long long w[100005][3];
long long memo[25][25][25];
int total;
//用memo的方法是否合理？
long long function(long long a,long long b,long long c)
{
    if(a<=0||b<=0||c<=0)
    {
        // memo[a][b][c]=1;负数情况不要存入
        return 1;
    }
    if(a>20||b>20||c>20)
    return function(20,20,20);
    if(memo[a][b][c]!=0)
    return memo[a][b][c];
    if(a<b&&b<c)
    {
        //原来的写法：并没有实现真正的记忆化处理
        // if(memo[a][b][c-1]==0)
        // {
        //     memo[a][b][c-1]=function(a,b,c-1);
        // }
        // if(memo[a][b-1][c-1]==0)
        // {
        //     memo[a][b-1][c-1]=function(a,b-1,c-1);
        // }
        // if(memo[a][b-1][c]==0)
        // {
        //     memo[a][b-1][c]=function(a,b-1,c);
        // }
        // return memo[a][b][c-1]+memo[a][b-1][c-1]-memo[a][b-1][c];
        // memo[a][b][c]=memo[a][b][c-1]+memo[a][b-1][c-1]-memo[a][b-1][c];
        memo[a][b][c]=function(a, b, c-1) + function(a, b-1, c-1) - function(a, b-1, c);
    }
    else{
        // if(memo[a-1][b][c]==0)
        // {
        //     memo[a-1][b][c]=function(a-1,b,c);
        // }
        // if(memo[a-1][b-1][c]==0)
        // {
        //     memo[a-1][b-1][c]=function(a-1,b-1,c);
        // }
        // if(memo[a-1][b][c-1]==0)
        // {
        //     memo[a-1][b][c-1]=function(a-1,b,c-1);
        // }
        // if(memo[a-1][b-1][c-1]==0)
        // {
        //     memo[a-1][b-1][c-1]=function(a-1,b-1,c-1);
        // }
        // return memo[a-1][b][c]+memo[a-1][b-1][c]+memo[a-1][b][c-1]-memo[a-1][b-1][c-1];
        // memo[a][b][c]= memo[a-1][b][c]+memo[a-1][b-1][c]+memo[a-1][b][c-1]-memo[a-1][b-1][c-1];
        memo[a][b][c] = function(a-1, b, c) + function(a-1, b-1, c) + function(a-1, b, c-1) - function(a-1, b-1, c-1);
    }
    return memo[a][b][c];
}
int main()
{
    int i,j;
    int flag=0;
    //更好的写法
    long long a,b,c;
    while(scanf("%lld%lld%lld",&a,&b,&c))
    {
        if(a==-1&&b==-1&&c==-1)
        {
            return 0;
        }
        printf("w(%lld, %lld, %lld)= ",a,b,c);
        printf("%lld\n",function(a,b,c));
    }
    // while(1)
    // {
    //     flag=0;//flag要重置
    //     for(i=0;i<3;i++)
    //     {
    //         scanf("%lld",&w[total][i]);
    //     }
    //     for(i=0;i<3;i++)
    //     {
    //         if(w[total][i]!=-1)
    //         {
    //             flag=1;
    //             break;
    //         }
    //     }
    //     if(!flag)
    //     break;
    //     total++;
    // }
    // for(i=0;i<total;i++)
    // {
    //     printf("w(%lld, %lld, %lld) = %lld\n",w[i][0],w[i][1],w[i][2],function(w[i][0],w[i][1],w[i][2]));
    // }
    return 0;
}