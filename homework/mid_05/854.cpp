#include<stdio.h>
int arr[2000000];
int used[20000000];
int main()
{
    freopen("error (4).in","r",stdin);
    int n;
    int i,j,t;
    int num,k;
    int flag;
    long long count=0;
    long long sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        for(j=0;j<num;j++)
        {
            flag=0;
            scanf("%d",&k);
            for(t=0;t<count;t++)
            {
                if(k==arr[t])
                {
                    flag=1;
                    used[t]++;
                    break;
                }
            }
            if(!flag)//不是重复
            {
                arr[count++]=k;
                sum+=k;
            }
            else if(flag==1&&used[t]==1)
            {
                sum-=k;
            }
        }
    }
//bug：我无法知道后面有没有重复
    printf("%lld",sum);
    return 0;
}
//拼成一个大数组，跟重复元素类似
//用数组下标映射