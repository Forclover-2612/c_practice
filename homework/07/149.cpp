#include<stdio.h>
#define max 5
int main()
{
    int n,p,m;
    int i,j,t;
    int matrix1[max][max];
    int matrix2[max][max];
    scanf("%d %d %d",&n,&p,&m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<p;j++)
        {
            scanf("%d",&matrix1[i][j]);
        }
    }
    for(i=0;i<p;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&matrix2[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            int sum=0;
            for(t=0;t<p;t++)
            {
                sum+=matrix1[i][t]*matrix2[t][j];
            }
            printf("%d ",sum);
        }
        printf("\n");
    }
    return 0;
}