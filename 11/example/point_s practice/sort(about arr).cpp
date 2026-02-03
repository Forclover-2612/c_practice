#include<stdio.h>
#include<stdlib.h>
void selection(int *a,int left,int right);
void bubble(int *a,int left,int right);
void quicksort(int *start,int *end);
void merge(int *start,int *mid,int *end);
void mergesort(int *start,int *end);
int main()
{
    int arr[] = {5, 1, 9, 3, 7, 4, 8, 6, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    // selection(arr,0,n-1);
    bubble(arr,0,n-1);
    // quicksort(arr,arr+n-1);
    // mergesort(arr,arr+n-1);
    for(int *p=arr;p<arr+n;p++)
    {
        printf("%d\n",*p);
    }
    return 0;
}
void selection(int *a,int left,int right)
{
    int *start=a+left;
    int *end=a+right;
    int *minPos;
    int temp;
    for(int *p=start;p<end;p++)
    {
        minPos=p;
        for(int *q=p+1;q<=end;q++)
        {
            if(*q<*minPos)
            {
                minPos=q;//更新指针
            }
        }
        if(minPos!=p)
        {
            //是内容的交换，还是地址的交换
            //必须交换内容！
            temp=*minPos;
            *minPos=*p;
            *p=temp;
        }
    }
}
void bubble(int *a,int left,int right)
{
    int *start=a+left;
    int *end=a+right;
    int temp;
    int swapped;
    for(int *p=end;p>=start;p--)//已经排过的元素的个数-->边界在哪里
    {
        swapped=0;
        for(int *q=start;q<p;q++)
        {
            if(*(q+1)<*q)
            {
                temp=*q;
                *q=*(q+1);
                *(q+1)=temp;
                swapped=1;
            }
        }
        if(!swapped)
        break;
    }
}
void quicksort(int *start,int *end)
{
    if(start>=end)
    return;
    int *left=start;
    int *right=end;
    //基准值
    int pvoit=*start;
    while(left<right)
    {
        if(left<right&&*right>=pvoit)
        right--;
        if(left<right)
        *left=*right;
        if(left<right&&*left<=pvoit)
        left++;
        if(left<right)
        *right=*left;
    }
    *left=pvoit;

    quicksort(start,left-1);
    quicksort(left+1,end);
}
void merge(int *start,int *mid,int *end)
{
    int len=end-start+1;//计算元素个数,为了动态分配数组
    int *temp=(int*)malloc(len*sizeof(int));

    int *p1=start;
    int *p2=mid+1;//初始化不要出错
    int *pTemp=temp;
    while(p1<=mid&&p2<=end)
    {
        if(*p1<*p2)
        *pTemp++=*p1++;
        else
        *pTemp++=*p2++;
    }
    while(p1<=mid)
    *pTemp++=*p1++;
    while(p2<=end)
    *pTemp++=*p2++;

    pTemp=temp;
    for(int *p=start;p<=end;p++)
    {
        *p=*pTemp++;
    }
    free(temp);
}
void mergesort(int *start,int *end)
{
    if(start>=end)
    return;

    int *mid=(end-start)/2+start;
    mergesort(start,mid);
    mergesort(mid+1,end);//这里的mid位置要和上面的对应
    merge(start,mid,end);
}