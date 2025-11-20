#include<stdio.h>
//x：未入栈的个数 y:栈中的个数
//计算c(n,0)
// long long num;
//不能使用全局变量
long long count(int n,int x,int y)
{
    if(x==0)//所有数字都在栈中，生成一个合法序列
    return 1;
    if(x<0||y>n)//非法序列
    return 0;
    long long res=0;
    if(x>0)
    res+=count(n,x-1,y+1);
    if(y>0)
    res+=count(n,x,y-1);
    return res;
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%lld",count(n,n,0));
    return 0;
}