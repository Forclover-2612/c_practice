#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int i,j;
    int t;
    int sum;
    for(i=n;i<=m;i++)
    {
        sum=0;
        int a=i;
        for(j=0;j<3;j++)
        {
            t=a%10;
            sum+=t*t*t;
            a=a/10;
        }
        if(sum==i)
        {
            printf("%d ",sum);
        }
    }
    return 0;
}