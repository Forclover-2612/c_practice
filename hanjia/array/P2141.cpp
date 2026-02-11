#include<stdio.h>
#include<algorithm>
int arr[105];
int main()
{
    int n,flag=0,count=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    std::sort(arr,arr+n);
    for(int i=2;i<n;i++)
    {
        flag=0;
        for(int j=0;j<=i-2;j++)
        {
            for(int t=j+1;t<=i-1;t++)
            {
                if(arr[j]+arr[t]==arr[i])
                {
                    count++;
                    flag=1;
                    break;
                }
                if(arr[j]+arr[t]>arr[i])
                {
                    // flag=2;
                    break;
                }
            }
            if(flag==1)
            break;
        }
    }
    printf("%d",count);
    return 0;
}