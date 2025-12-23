#include<stdio.h>

int main()
{
    int n,m;
    int arr1[1005];
    int arr2[1005];
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr1[i]);
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d",&arr2[i]);
    }
    int left=0;
    int right=0;
    int k=0;
    int arr[2010];
    while(left<n&&right<m)
    {
        if(arr1[left]<arr2[right])
        {
            arr[k++]=arr1[left++];
        }
        else
        arr[k++]=arr2[right++];
    }
    while(left<n)
    {
        arr[k++]=arr1[left++];
    }
    while(right<m)
    {
        arr[k++]=arr2[right++];
    }
    for(int i=0;i<n+m;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}