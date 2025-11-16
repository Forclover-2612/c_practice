#include<stdio.h>
#include<math.h>

int main()
{
    int j;
    int arr[101]={0,1};
    for(int i=3;i<=100;i++)
    {
        for(j=2;j<=sqrt(i);j++)//2 也是素数
        {
            if(i%j==0)
            {
                arr[i]=1;
                break;
            }
        }
        j=2;
    }
    for(int n=2;n<=100;n++)
    {
        if(!arr[n])
        printf("%d ",n);
    }
    return 0;
}