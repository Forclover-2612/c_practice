#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
#define PI 3.14159265

//计算阶乘
long double step(int n)
{
    long double sum=1.0L;//要初始化：0！=1
    for(int i=1;i<=n;i++)
    {
        sum=sum*i;
    }
    return sum;
}
//控制x的范围
long double normalize_x(long double x)
{
    if(x>=0)
    {
        while(x>=PI*2.0)
        {
            x-=PI*2.0;
        }
    }
    else if(x<0)
    {
        while(x<-PI*2.0)
        {
            x+=PI*2.0;
        }
    }
    // long double two_pi=2.0L*PI;//直接计算x除以2π的余数
    // x=fmodl(x,two_pi);
    // //若结果为负，转化到[0,2π]区间
    // if(x<0)
    // {
    //     x+=two_pi;
    // }
    //把x归一化到[-π，π]区间
    // long double two_pi=2.0L*PI;
    // x=fmodl(fabsl(x),two_pi);
    // if(x>PI)
    // {
    //     x=x-two_pi;
    // }
    // if(x<0)
    // {
    //     x=-x;
    // }
    return x;
}
//计算sin的近似值
long double my_sin(long double x,long double eps)
{
    // int sign=(x>=0)?1:-1;
    x=normalize_x(x);
    long double sum=0.0L;
    long double term=x;//记录每一项：第一项是x
    //先normalize再使用
    int n=1;//需要阶乘到的数
    int sign=1;//记录符号
    while(fabs(term)>=eps)//每一项和精度进行比较
    {
        sum+=sign*term;
        // term*=x*x/((n+1)*(n+2));
        sign=-sign;
        n+=2;
        term=powl(x,n)/step(n);
    }
    
    return sum;//记得要返回
}
//计算cos的近似值
long double my_cos(long double x,long double eps)
{
    long double sum=0.0L;
    long double term=1.0L;//第一项是1
    int n=0;//初始化为0
    int sign=1;
    x=normalize_x(x);

    while(fabs(term)>=eps)
    {
        sum+=sign*term;
        sign=-sign;
        n+=2;
        term=powl(x,n)/step(n);
    }
    return sum;
}
int main()
{
    long double eps,x;
    cin>>x>>eps;

    cout<<fixed<<setprecision(6)<<my_sin(x,eps)<<endl;
    cout<<fixed<<setprecision(6)<<my_cos(x,eps);
    return 0;
}