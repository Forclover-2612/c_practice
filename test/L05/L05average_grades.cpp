#include<stdio.h>

int main()
{
    int n,m,sum=0;
    scanf("%d %d",&n,&m);
    int arr[n][m];
    printf("input the number\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            sum+=arr[i][j];
        }
        printf("%d\n",sum/m);
        sum=0;
    }
     for(int j=0;j<m;j++)
    {
        for(int i=0;i<n;i++)
        {
            sum+=arr[i][j];
        }
         printf("%d\n",sum/n);
        sum=0;
    }
    return 0;
}