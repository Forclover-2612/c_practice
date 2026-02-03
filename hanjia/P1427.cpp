#include<stdio.h>

int main()
{
    int i;
    long long n;
    long long arr[102];
    for(i=0;;i++)
    {
        scanf("%lld",&n);
        if(n==0)
        {
            break;
        }
        else
        {
            arr[i]=n;
        }
    }
    for(int j=i;j>0;j--)
    {
        printf("%lld ",arr[j]);
    }
    return 0;
}