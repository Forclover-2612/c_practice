#include<stdio.h>
#include<math.h>

int main()
{
    int range;
    scanf("%d",&range);
    int j;
    int arr[101]={0};
    for(int i=3;i<=range;i++)
    {
        for(j=2;j<=sqrt(i);j++)//2 也是素数
        {
            //进一步优化：它的倍数就不用再次判断
            if(i%j==0)
            {
                arr[i]=1;
                break;
            }
        }
    }
    for(int n=2;n<=range;n++)
    {
        if(!arr[n])
        printf("%d ",n);
    }
    return 0;
}