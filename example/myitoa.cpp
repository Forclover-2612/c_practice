#include<stdio.h>

int myitoa(int n,int arr[])
{
    int cnt=0;
    int i,j;
    int temp;
    while(n>0)
    {
        arr[cnt++]=n%10;
        n/=10;
    }
    int len=cnt;
    for(i=0,j=len-1;i<=j;i++,j--)
    {
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    return len;
}
int main()
{
    int n;
    int arr[20];
    scanf("%d",&n);
    int len=myitoa(n,arr);
    for(int i=0;i<len;i++)
    {
        printf("%d",arr[i]);
    }
    return 0;
}