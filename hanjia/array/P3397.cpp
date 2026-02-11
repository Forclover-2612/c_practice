#include<stdio.h>
//二维前缀和公式是：A[i][j] = D[i][j] + A[i-1][j] + A[i][j-1] - A[i-1][j-1]。

int arr[1005][1005];
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int x1,y1,x2,y2;
    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        for(int j=x1;j<=x2;j++)
        {
            for(int t=y1;t<=y2;t++)
            {
                arr[j][t]+=1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}