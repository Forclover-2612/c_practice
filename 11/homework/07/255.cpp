#include<stdio.h>
#define max 20
int main()
{
    int n,m;
    int i,j;
    scanf("%d %d",&n,&m);
    int matrix[max][max];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",matrix[j][i]);
        }
        printf("\n");
    }
    return 0;
}