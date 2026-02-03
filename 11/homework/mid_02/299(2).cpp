#include<stdio.h>
#define MAX 10000
int main()
{
    int i,j;
    int n;
    scanf("%d",&n);
    int isprime[MAX+1]={0};//0表示是质数，1表示是合数
    for(i=2;i*i<=MAX;i++)
    {
        if(!isprime[i])
        {
            for(j=i*i;j<=MAX;j+=i)
            {
                isprime[j]=1;
            }
        }
    }
    int t=n;
    for(i=2;i<=t;i++)//不要拿改变的量当循环条件
    {
        int count=0;
        if(!isprime[i])
        {
            while(n%i==0)
            {
                count++;
                n/=i;
            }
        }
        if(count>=1)
        printf("%d:%d\n",i,count);
        if(n==1)
        break;
    }
    return 0;    
}