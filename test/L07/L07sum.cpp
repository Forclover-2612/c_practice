#include<stdio.h>

int power(int ,int);

int SOP(int ,int);//累加

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    
    int result=SOP(n,k);
    printf("%d",result);
    return 0;
}

int power(int x,int y)
{
    int z=1;
    for(int i=1;i <=y;i++)
    {
        z=z*x;
    }
    return z;
}

int SOP(int m,int l)
{
    int sum=0;
    for(int i=1;i<=m;i++)
    {
        sum+=power(i,l);
    }
    return sum;
}