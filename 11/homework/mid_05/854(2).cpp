#include<stdio.h>
int arr[2000001];
int main()
{
    // freopen("error (4).in","r",stdin);
    int n;
    int i,j;
    int num;
    int temp;
    long long sum=0;
    scanf("%d",&n);
    int count=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        for(j=0;j<num;j++)
        {
            scanf("%d",&temp);
            arr[temp+1000000]++;
        }
    }
    for(i=0;i<=2000000;i++)
    {
        if(arr[i]==1)
        sum+=i-1000000;
    }
    printf("%lld",sum);
    return 0;
}