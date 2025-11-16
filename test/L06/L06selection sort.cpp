#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int arr[100];
    int tmp;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    //i、n是数组元素的个数
    //寻找最小值，排在前面
    //或者用min存最小值的下标
    for(int j=0;j<n-1;j++)//放在第j个元素，写n-1少一次循环
    {
        for(int t=j;t<n-1;t++)//t是需要比较的元素个数
        {
            if(arr[j]>arr[t+1])
            {
                tmp=arr[j];//注意：不能写倒
                arr[j]=arr[t+1];
                arr[t+1]=tmp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }
    return 0;
}