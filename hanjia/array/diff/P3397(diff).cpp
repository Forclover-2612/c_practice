#include<stdio.h>
//二维前缀和公式是：A[i][j] = D[i][j] + A[i-1][j] + A[i][j-1] - A[i-1][j-1]。
//最终地毯数：arr[i][j] = Sum(diff[1][1] ... diff[i][j])

// diff 用于记录差分操作，arr 用于存储最终结果
int diff[5005][5005]; 
int arr[5005][5005];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int x1, y1, x2, y2;
    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        diff[x1][y1]+=1;
        diff[x1][y2+1]-=1;
        diff[x2+1][y1]-=1;
        diff[x2+1][y2+1]+=1;
    }

    long long ans=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            arr[i][j]=arr[i][j-1]+arr[i-1][j]-arr[i-1][j-1]+diff[i][j];
            // printf("%d ",arr[i][j]);
            ans+=((i+j)^arr[i][j]);
        }
        // printf("\n");
    }
    printf("%lld",ans);
    return 0;
}