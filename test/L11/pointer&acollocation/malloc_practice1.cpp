#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    printf("想要创建的数组大小n:");
    scanf("%d",&n);
    printf("\n");
    int *arr=(int*)malloc(n*sizeof(int));
    if(arr==NULL)
    {
        printf("内存分配失败\n");
        return 1;
    }
    printf("数组内容为：");
    for(int i=0;i<n;i++)
    {
        *(arr+i)=i*10;
        printf("%d ",arr[i]);
    }
    printf("\n");
    free(arr);
    arr=NULL;
    return 0;
}