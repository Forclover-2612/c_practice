#include <stdio.h>
#define max 100
int main()
{
    int n, m;
    int i, j;
    scanf("%d %d", &m, &n);
    int arr[max][max];
    int sum[max][max];
    int count;
    int point[max][2];
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i - 1 >= 0 && j - 1 >= 0 && i + 1 < m && j + 1 < n)
                sum[i][j] = arr[i - 1][j] + arr[i][j + 1] + arr[i][j - 1] + arr[i + 1][j] + arr[i][j];
            else if (i - 1 < 0 && j - 1 >= 0)//上边
                sum[i][j] = arr[i][j - 1] + arr[i][j + 1] + arr[i+1][j]+arr[i][j];
            else if (i - 1 >= 0 && j - 1 < 0)//左边
                sum[i][j] = arr[i - 1][j] + arr[i + 1][j] + arr[i][j]+arr[i][j+1];
            else if (i + 1 >= m && j + 1 < n)//下边
                sum[i][j] = arr[i - 1][j] + arr[i][j + 1] + arr[i][j]+arr[i][j-1];
            else if (i + 1 < m && j + 1 >= n)//右边
                sum[i][j] = arr[i][j - 1] + arr[i + 1][j] + arr[i][j]+arr[i-1][j];
        }
    }
    sum[0][0] = arr[1][0] + arr[0][1] + arr[0][0];
    sum[0][n - 1] = arr[0][n - 2] + arr[0][n - 1] + arr[1][n - 1];
    sum[m - 1][0] = arr[m - 2][0] + arr[m - 1][0] + arr[m - 1][1];
    sum[m - 1][n - 1] = arr[m - 2][n - 1] + arr[m - 1][n - 1] + arr[m - 1][n - 2];
    int result=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(sum[i][j]>result)
            {
                count=0;
                result=sum[i][j];
                point[0][0]=i;
                point[0][1]=j;
                count++;
            }
            else if(sum[i][j]==result)//两种情况；要么前面break，要么else if
            {
                point[count][0]=i;
                point[count][1]=j;
                count++;            
            }
        }
    }
    printf("%d %d\n",result,count);
    for(i=0;i<count;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("%d ",point[i][j]);
        }
        printf("\n");
    }
    return 0;
}