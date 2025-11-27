#include<stdio.h>
//思路：第i步，以Ai为第一个数，对余下的A1,A2…Ai-1, Ai+1…An进行全排列（固定前缀）
void perm(int A[],int p,int q)//p表示当前处理到第几个位置，q表示需要排列的数字个数
{
    if(p==q)
    {
        for(int i=0;i<q;i++)
        {
            printf("%d ",A[i]);
        }
        printf("\n");
        return;
    }
    //先交换Ai和A1
    int temp;
    //注意起点：要从哪里开始(因为现在没有标记数组了)
    //从当前位置p开始，依次与后面的元素交换,等于说是通过交换实现排列
    for(int i=p;i<q;i++)
    {
        temp=A[i];
        A[i]=A[p];
        A[p]=temp;
        perm(A,p+1,q);
        //回溯：回复交换前的状态，以便下一次尝试
        temp=A[i];
        A[i]=A[p];
        A[p]=temp;
    }
}
int main()
{
    int A[]={1,2,3,4,5};
    int n=sizeof(A)/sizeof(A[0]);
    perm(A,0,n-1);//不是n-1，指到元素之后
    return 0;
}