#include<stdio.h>
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
//LCM(a,b)= (a×b)/GCD(a,b)
int lcm(int a,int b)
{
    return (a/gcd(a,b))*b;
}
int main()
{
    int a1,a2;
    int b1,b2;
    scanf("%d %d %d %d",&a1,&a2,&b1,&b2);
    //计算最小公倍数
    int com1=lcm(a2,b2);
    int sum=a1*(com1/a2)+b1*(com1/b2);
    int com2=gcd(sum,com1);
    printf("%d/%d",sum/com2,com1/com2);
    return 0;
}