#include <stdio.h>
#include <stdlib.h>

int findMax(int *p, int nSize)
{
    int *pos;
    int max=*p;
    int idx=0;//idx一定要初始化！
    for(pos=p;pos<p+nSize;pos++)
    {
        if(*pos>max)
        {
            idx=pos-p;
            max=*pos;
        }
    }
    int temp;
    temp=*p;
    *p=*(p+idx);
    *(p+idx)=temp;
    return max;
}

int my_findMax(int *p,int nsize)
{
    //直接假设第一个元素就是最大的
    int *maxpos=p;
    int *current;
    for(current=p+1;current<p+nsize;current++)
    {
        if(*current>*maxpos)
        {
            //更新最大值的位置指针
            maxpos=current;
        }
    }
    //只有当最大值不再第一个位置时才需要交换
    // int maxval=*maxpos;可以选择先保存值
    if(maxpos!=p)
    {
        int temp=*p;
        *p=*maxpos;
        *maxpos=temp;
    }
    return *p;
}
int main()
{
    int ary[2100] = {3, 2, 1, 5, 6, 7, 9, 10}, n = 8, nMax, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &ary[i]);

    nMax = my_findMax(ary, n);

    for (i = 0; i < n; i++)
        printf("%d ", ary[i]);
    printf("\n");

    printf("%d\n", nMax);
    return 0;
}