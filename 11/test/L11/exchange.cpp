#include<stdio.h>

void reverse_a(int *a,int *left,int *right)
{
    if(left>right)
    return;
    int temp;
    temp=*left;
    *left=*right;
    *right=temp;
    reverse_a(a,left+1,right-1);
}
//或者：
void inv(int x[],int n)
{
    int temp,*i,*j;
    for(i=x,j=x+n-1;i<j;i++,j--)
    {
        temp=*i;
        *i=*j;
        *j=temp;
    }
    return;
}
int main()
{
    int a[]={1,2,3,4,5,6};
    int n=sizeof(a)/sizeof(a[0]);
    reverse_a(a,a,a+n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}