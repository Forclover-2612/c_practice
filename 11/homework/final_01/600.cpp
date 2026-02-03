#include<stdio.h>
int count;
//x:空瓶数 y：瓶盖数 
void calculate(int x,int y,int b,int c)
{
    if(x<b&&y<c)
    return;
    int n1=0,n2=0;
    if(x>=b)
    n1=x/b;
    if(y>=c)
    n2=y/c;
    int plus=n1+n2;
    count+=plus;
    calculate(x-n1*b+plus,y-n2*c+plus,b,c);
}
int main()
{
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    int n=d/a;
    count=n;
    calculate(n,n,b,c);
    printf("%d",count);
    return 0;
}