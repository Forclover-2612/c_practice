#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int i,j;
    int sum=1;
    int temp=1;
    for(i=0;i<n;i++)//打印数量
    {
        for(j=sum;j<=sum+n-i-1;j++)//打印数字
        //注意！不能用动态变化的变量作为条件
        {
            printf("%02d",j);
            temp++;
        }
        printf("\n");
        sum=temp;
    }
    return 0;
}