#include<stdio.h>
//double buffering(ping-pong)
//当前状态需要依赖上一轮的状态
int is_uniform(int *arr,int m)
{
    for(int i=2;i<=m;i++)
    {
        if(arr[i]!=arr[1])
        return 0;
    }
    return 1;
}
int main()
{
    int buffer_a[102]={0};
    int buffer_b[102]={0};
    int *curr=buffer_a;
    int *next=buffer_b;
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&buffer_a[i]);
    }
    int count=1;
    while(!is_uniform(curr,m))
    {
        for(int i=1;i<=m;i++)
        {
            int divisor=(i==1||i==m)?2:3;
            next[i]=(curr[i-1]+curr[i]+curr[i+1])/divisor;//本身就是向下取整
        }
        //核心：交换指针
        int *temp;
        temp=curr;
        curr=next;
        next=temp;
        count++;
    }
    printf("%d\n",count);
    return 0;
}