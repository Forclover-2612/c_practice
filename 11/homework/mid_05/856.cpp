#include<stdio.h>
#define MAX 100000
int devide_num(int n)
{
    int sum=0;
    while(n!=0)
    {
        sum+=n%10;
        n/=10;
    }
    return sum;
}
int main()
{
    int arr[MAX];
    int i=0,j;
    int flag=0;
    scanf("%d",&arr[0]);
    while(arr[i]!=0)
    {
        scanf("%d",&arr[++i]);
    }
    int n=i;
    for(i=0;i<n;i++)
    {
        flag=0;
        for(j=0;j<arr[i];j++)
        {
            if(j+devide_num(j)==arr[i])
            {
                printf("%d\n",j);
                flag=1;
                break;
            }
        }
        if(flag==0)
        printf("0\n");
    }
    return 0;
}