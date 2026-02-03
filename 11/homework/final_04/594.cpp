#include <stdio.h>
int matrix[1000][1000];
int num[10000];
void find(int n, int i)
{
    int r = num[i];
    for (int j = 0; j < n; j++)
    {
        // 先确定数字范围（根据行列号进行寻找）
        if (r >= matrix[j][0] && r <= matrix[j][n - 1])
        {
            // 往里寻找，可以考虑二分
            int left = 0;
            int right = n - 1;
            
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (matrix[j][mid] == r)
                {
                    printf("%d %d\n", j, mid);
                    return;
                }
                if(r>matrix[j][mid])
                {
                    left=mid+1;
                }
                if(r<matrix[j][mid])
                {
                    right=mid-1;
                }
            }
        }
        if(r<matrix[j][0])
        break;
    }
    printf("-1\n");
    return;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &num[i]);
    }
    for (int i = 0; i < k; i++)
    {
        find(n,i);
    }
    return 0;
}