#include<stdio.h>
int used[100];
char ans[100];
//辅助函数：判断在A[p...i-1]之间，是否有和A[i]一样的数
//如果有，说明之前已经有一样的数被交换到p位置试过了，这次就不用试了
int is_duplicate(int A[],int p,int i)
{
    for(int k=p;k<i;k++)
    {
        if(A[k]==A[i])
        return 1;
    }
    return 0;
}
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
        if(is_duplicate(A,p,i))
        {
            continue;
        }
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
void tradition(char *s,int p,int q)
{
    if(p>=q)
    {
        for(int i=0;i<q;i++)
        {
            printf("%c",ans[i]);
        }
        printf("\n");
        return;
    }
    for(int i=0;i<q;i++)
    {
        //考虑重复元素
        if(i>0&&s[i]==s[i-1]&&!used[i-1])
        continue;
        if(!used[i])
        {
            ans[p]=s[i];
            used[i]=1;
            tradition(s,p+1,q);
            used[i]=0;
        }
    }
}
int main()
{
    int A[]={1,2,3};
    int n=sizeof(A)/sizeof(A[0]);
    perm(A,0,n);//不是n-1，指到元素之后
    return 0;
}