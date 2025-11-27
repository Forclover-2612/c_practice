#include <stdio.h>

#define N 5
int arr[N] = {1, 2, 3, 4, 5};
int ans[N];
int used[N];
void perm(int n,int len)
{
    if(n==len)
    {
        for(int i=0;i<len;i++)
        {
            printf("%d ",ans[i]);
        }
        printf("\n");
        return;
    }
    for(int i=0;i<len;i++)
    {
        if(used[i]==0)
        {
            used[i]=1;
            ans[n]=arr[i];
            perm(n+1,len);
            used[i]=0;
        }
    }
}
int main()
{
    perm(0,N-2);
    return 0;
}