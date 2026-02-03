#include <stdio.h>
#define max 101
int main()
{
    int n;
    int i, j;
    int m;
    int matrix[max][max];
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        if(i%2==0)
        {
            m=(i-1)*(i-1)+1;
            for(j=1;j<=i;j++)
            {
                matrix[j][i]=m;
                m++;
            }
            for(j=i-1;j>=1;j--)
            {
                matrix[i][j]=m;
                m++;
            }
        }
        else{
             m=(i-1)*(i-1)+1;
            for(j=1;j<=i;j++)
            {
                matrix[i][j]=m;
                m++;
            }
            for(j=i-1;j>=1;j--)
            {
                matrix[j][i]=m;
                m++;
            }
        }
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}