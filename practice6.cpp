#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int **arr=(int**)malloc(n*sizeof(int *));
    for(int i=0;i<n;i++)
    {
        arr[i]=(int*)malloc(m*sizeof(int));
    }
    if(arr==NULL)
    {
        printf("fail to memory\n");
        exit(0);
    }
    arr[n-1][m-1]=1;
    int t=*(*(arr+n-1)+m-1);
    printf("%d",t);
    for(int i=0;i<n;i++)
    {
        free(arr[i]);
    }
    free(arr);
    return 0;
}