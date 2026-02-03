#include<stdio.h>
#include<iostream>
#include<math.h>

int main()
{
    int a,b,n,k,m,num;
    int count=0;
    scanf("%d %d %d %d %d",&a,&b,&n,&k,&m);
    if(k==0||m==0)
    {
        printf("0\n");
    }
    for(num=a;num<=b;num++)
    {
        if(num%10==n&&num>=pow(10,m-1)&&num<(pow(10,m))&&num%k==0)
        {
            count++;
        }
    }
    printf("%d",count);
    return 0;
}