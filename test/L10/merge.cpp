#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int temp1[MAX];
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
            temp1[k++]=arr[i++];
        }
        else
        {
            temp1[k++]=arr[j++];
        }
    }
    //2.处理左子数组
    while(i<=mid)
    {
        temp1[k++]=arr[i++];
    }
    //3。处理右子数组
    while(j<=right)
    {
        temp1[k++]=arr[j++];
    }
    // 4.将临时数组的有序数据复制回原数组
    k=0;
    while(left<=right)
    {
        arr[left++]=temp1[k++];
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

void merge(int arr[],int temp[],int left,int mid,int right)
{
    int i=left;
    int j=mid+1;
    int k=left;
    while(i<=mid&&j<=right)
    {
        if(arr[i]<=arr[j])
        {
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid)
    {
        temp[k++]=arr[i++];
    }
    while(j<=right)
    {
        temp[k++]=arr[j++];
    }
    for(i=left;i<=right;i++)
    {
        arr[i]=temp[i];
    }
}
void mergesort_recursive(int arr[],int temp[],int left,int right)
{
    if(left>=right)
    {
        return;
    }
    int mid=left+(right-left)/2;
    mergesort_recursive(arr,temp,left,mid);
    mergesort_recursive(arr,temp,mid+1,right);
    merge(arr,temp,left,mid,right);
}
void mergesort_entrance(int arr[],int n)
{
    if(n<=0)
    return;
    int *temp=(int*)malloc(n*sizeof(int));
    if(temp==NULL)
    {
        printf("fail to memory\n");
        return;
    }
    mergesort_recursive(arr,temp,0,n-1);
    free(temp);
}
// int main()
// {
//     int n;
//     scanf("%d",&n);
//     int arr[MAX];
//     for(int i=0;i<n;i++)
//     {
//         scanf("%d",&arr[i]);
//     }
//     mergesort(arr,0,n-1);
//     for(int i=0;i<n;i++)
//     {
//         printf("%d ",arr[i]);
//     }
//     return 0;
// }
int main()
{
    int n;
    scanf("%d",&n);
    int* arr=(int*)malloc(n*sizeof(int));
    if(arr==NULL)
    {
        printf("fail to memory");
        return 1;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    mergesort_entrance(arr,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}