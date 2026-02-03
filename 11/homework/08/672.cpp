#include<stdio.h>

int partition(int ary[],int left,int right)
{
    //解决问题：遇到重复元素时死循环
    int x=ary[left];
    while(left<right)
    {
        while((ary[right]>=x)&&right>left)
        {
            right--;
        }
        if(ary[right]<x)
        {
            ary[left]=ary[right];
            left++;
        }
        while((ary[left]<=x)&&left<right)
        {
            left++;
        }
        if(ary[left]>x)
        {
            ary[right]=ary[left];
            right--;
        }
    }
    ary[left]=x;
    return left;
}
void quicksort(int ary[],int left,int right)
{
    if(left>=right)
    return;
    int k=partition(ary,left,right);
    quicksort(ary,left,k-1);
    quicksort(ary,k+1,right);
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[100];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}