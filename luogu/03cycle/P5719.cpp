#include<stdio.h>

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int sum1=0,count1=0;
    int sum2=0,count2=0;
    for(int i=1;i<=n;i++)
    {
        if(i%k==0)
        {
            sum1+=i;
            count1++;
        }
        else
        {
            sum2+=i;
            count2++;
        }
    }
    printf("%.1f %.1f",(float)sum1/count1,(float)sum2/count2);
    return 0;
}