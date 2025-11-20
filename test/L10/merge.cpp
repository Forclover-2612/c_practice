#include<stdio.h>

#define MAX 100
int temp[MAX];
//合并函数
void merge(int arr[],int left,int mid,int right)
{
    int i=left;//左子数组的起始指针
    int j=mid+1;//右子数组的起始指针
    int k=0;
    //1.双指针遍历，把较小的元素放入临时数组
    //直到一个子数组的全部元素放入临时数组（只需要处理另外一个数组的剩余元素）
    while(i<=mid&&j<=right)
    {
        if(arr[i]<=arr[j])
        {
            temp[k++]=arr[i++];
        }
        else
        {
            temp[k++]=arr[j++];
        }
    }
    //2.处理左子数组
    while(i<=mid)
    {
        temp[k++]=arr[i++];
    }
    //3。处理右子数组
    while(j<=right)
    {
        temp[k++]=arr[j++];
    }
    //4.将临时数组的有序数据复制回原数组
    k=0;
    while(left<=right)
    {
        arr[left++]=temp[k++];
    }
}
//排序主函数：递归拆分数组
void mergesort(int arr[],int left,int right)
{
    if(left==right)
    return;
    // int mid=(left+right)/2;
    //防止溢出的写法
    int mid=left+(right-left)/2;

    //递归拆分左半部分
    mergesort(arr,left,mid);
    //递归拆分右半部分
    mergesort(arr,mid+1,right);
    //合并两个有序子数组
    merge(arr,left,mid,right);
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[MAX];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}