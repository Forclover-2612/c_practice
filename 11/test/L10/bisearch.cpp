#include<stdio.h>

int bisearch(int arr[],int num,int low,int high)
{
    int mid;
    if(low>high)
    return -1;
    mid=(high+low)/2;
    if(num>arr[mid])
    {
        low=mid+1;
        return bisearch(arr,num,low,high);
    }
    else if(num<arr[mid])
    {
        high=mid-1;
        return bisearch(arr,num,low,high);
    }
    else
    return mid;
}
int main()
{
    int num;
    int n,low,high;
    scanf("%d %d",&num,&n);
    scanf("%d %d",&low,&high);
    int arr[100];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("%d",bisearch(arr,num,low,high));
    return 0;
}