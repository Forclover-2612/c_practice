#include <stdio.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int i,j,temp;
    int arr[n];
    int arr1[n];
    int num, sum = 0, count = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    // 处理学号
    for (i = 0; i < n; i++)
    {
        sum=0;
        num = arr[i];
        while (num > 0)
        {
            sum += num % 10;
            num = num / 10;
        }
        if(sum%k==0)
        {
            arr1[count]=arr[i];
            count++;
        }
    }
    //内部排序：冒泡排序
    for(i=0;i<count-1;i++)
    {
        for(j=0;j<count-i-1;j++)
        {
            if(arr1[j]>arr1[j+1])
            {
                temp=arr1[j];
                arr1[j]=arr1[j+1];
                arr1[j+1]=temp;
            }
        }
    }
    //输出
    //是对arr1排序！！！
    printf("%d\n",count);
    for(i=0;i<count;i++)
    {
        printf("%d\n",arr1[i]);
    }
    return 0;
}