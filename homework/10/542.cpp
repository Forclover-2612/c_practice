#include <stdio.h>
#include <stdlib.h>

void mySort(int *a,int left,int right)
{
    // int min,temp;
    // //选择排序的本质：记住下标
    // for(int i=left;i<right;i++)
    // {
    //     min=i;
    //     for(int j=i+1;j<=right;j++)
    //     {
    //         if(*(a+j)<*(a+min))
    //         min=j;
    //     }
    //     if(min!=i)
    //     {
    //         temp=*(a+i);
    //         *(a+i)=*(a+min);
    //         *(a+min)=temp;//错误！这里面并没有改变数组本身的值，即没有记住下标！！！
    //     }
    // }
    //纯指针写法
    int *end=a+right;
    int *start=a+left;
    int *p,*q,*minPos;
    int temp;
    for(p=start;p<end;p++)
    {
        minPos=p;
        for(q=p+1;q<=end;q++)
        {
            if(*q<*minPos)
            {
                minPos=q;
            }
        }
        if(minPos!=p)
        {
            temp=*p;
            *p=*minPos;
            *minPos=temp;
        }
    }
    return;
}

int main()  
{  
    int array[100], i, n;
    
    scanf("%d",&n);

    for ( i = 0; i < n; i ++ ){
        scanf("%d", &array[i]);
    }

    mySort(array, 0, n - 1);

    for ( i = 0; i < n; i ++ ){
        printf("%d ", array[i]);
    }
    printf("\n");  
    return 0;  
}  