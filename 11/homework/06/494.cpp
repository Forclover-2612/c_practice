#include<stdio.h>

typedef struct{
    int i;
    int j;
}num;

num calculate(int x,int n,int arr[])
{
    num nums;
    int i=0;
    for(nums.i=1;nums.i<=n;nums.i++)
    {
        i=nums.i;
        for(nums.j=i+1;nums.j<=n;nums.j++)
        {
            if(arr[nums.i]+arr[nums.j]==x)
            {
                return nums;
            }
        }
    }
}

int main()
{
    int n;//n样奖品
    int i,j;
    int x;
    scanf("%d",&n);
    int arr[n+1];
    for(i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
    scanf("%d",&x);
    num result=calculate(x,n,arr);
    printf("%d %d",result.i,result.j);
    return 0;
}