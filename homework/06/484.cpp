#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    int num[65536]={0};//所有数组初始化为0
    int i,j;
    int m;
    int flag=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        m=arr[i];
        num[m+32768]++;        
    }
    //初始化数组：
    //怎么统计重复项
    //统计完就删掉该项的数据吗？还是直接令该项为0
    //直接为0就不参与比较（但是数据中如果也有0呢）
    //已知数据范围，可以直接多一个标记数组
    for(i=0;i<65536;i++)
    {
        if(num[i]>1)
        {
            printf("%d:%d\n",i-32768,num[i]);
            flag=1;
        }
    }
    if(!flag)
    {
        printf("NO");
    }
    return 0;
}