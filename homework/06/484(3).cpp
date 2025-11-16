#include<stdio.h>
//只用一个数组存储，先排序，再往后找相同元素
int main()
{
    int n;
    int i,j;
    scanf("%d",&n);
    int arr[1000];
    int temp;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    //注意：冒泡排序，从前往后比较的话，是先确定最后面的元素
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    int flag=0;
    for(i=0;i<n;i++)
    {
        int k=1;
        //向后寻找
        while(arr[i+1]==arr[i]&&i+1<n)
        {
            k++;
            i++;
        }
        if(k>1)
        {
            printf("%d:%d\n",arr[i],k);
            flag=1;
        }
    }
    if(!flag)
    {
        printf("NO");
    }
    return 0;
}