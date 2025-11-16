#include<stdio.h>
#define max 105
int main()
{
    int arr[max][max];
    int sum[max][max];
    int point[max][max]={0};
    int m,n;
    scanf("%d %d",&m,&n);
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i-1>=0&&j-1>=0&&i+1<m&&j+1<n)
            sum[i][j]=arr[i-1][j-1]+arr[i-1][j+1]+arr[i+1][j-1]+arr[i+1][j+1]+arr[i][j];
            else if(i-1<0&&j-1>=0)
            sum[i][j]=arr[i+1][j-1]+arr[i+1][j+1]+arr[i][j];
            else if(i-1>=0&&j-1<0)
            sum[i][j]=arr[i-1][j+1]+arr[i+1][j+1]+arr[i][j];
            else if(i+1>=m&&j+1<n)
            sum[i][j]=arr[i-1][j-1]+arr[i-1][j+1]+arr[i][j];
            else if(i+1<m&&j+1>=n)
            sum[i][j]=arr[i-1][j-1]+arr[i+1][j-1]+arr[i][j];
        }
    }
    sum[0][0]=arr[1][1]+arr[0][0];
    sum[0][n-1]=arr[1][n-2]+arr[0][n-1];
    sum[m-1][0]=arr[m-2][1]+arr[m-1][0];
    sum[m-1][n-1]=arr[m-2][n-2]+arr[m-1][n-1];
    int result=100000;
    int count=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(sum[i][j]<result)
            result=sum[i][j];
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(sum[i][j]==result)
            {
                point[i][j]=1;
                count++;
            }
        }
    }
    printf("%d %d\n",result,count);
    for(i=m-1;i>=0;i--)
    {
        for(j=n-1;j>=0;j--)
        {
            if(point[i][j]==1)
            {
                printf("%d %d\n",i,j);
            }
        }
    }
    return 0;
}