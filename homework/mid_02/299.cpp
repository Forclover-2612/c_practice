#include<stdio.h>
#include<math.h>

int main()
{
    freopen("error (29).in","r",stdin);
    int n;
    int i,j;
    scanf("%d",&n);
    int count=0;
    int flag=0;
    int prime[1500];
    int num[1500]={0};
    for(i=2;i<=10000;i++)
    {
        flag=0;
        for(j=2;j<=sqrt(i);j++)
        {
            if(i%j==0)
            {
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            prime[count++]=i;
        }
    }
    int temp=n;//最好不要在原数据上改动，容易出错
    for(i=0;i<count;i++)
    {
        while(temp%prime[i]==0)
        {
            num[i]++;
            temp/=prime[i];
        }
        if(temp==1)
        break;
    }
    for(i=0;i<1500;i++)//不要越界
    {
        if(num[i]!=0)
        {
            printf("%d:%d\n",prime[i],num[i]);
        }
        if(prime[i]>n)
        break;
    }
    return 0;
}
