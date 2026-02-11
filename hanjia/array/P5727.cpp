#include<stdio.h>
int arr[10000];

int judge(int n)
{
    if(n%2==0)
    {
        return n/2;
    }
    else 
    {
        return n*3+1;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    arr[0]=n;
    int i=1;
    while(n!=1)
    {
        n=judge(n);
        arr[i]=n;
        i++;
    }
    for(int j=i-1;j>=0;j--)
    {
        printf("%d ",arr[j]);
    }
    return 0;
}