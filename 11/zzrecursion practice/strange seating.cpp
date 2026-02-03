#include<stdio.h>
//N皇后变形
int room[12][12];
int col[12];
int count;
int is_safe(int j)
{
    return(!col[j]);
}
void search(int n,int k,int num,int row)
{
    if(num==k)
    {
        count++;
        return;
    }
    for(int i=row;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(room[i][j]!=-1&&is_safe(j))
            {
                col[j]=1;
                search(n,k,num+1,i+1);//注意是写i，而不是写row
                col[j]=0;
            }
        }
    }
}
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&room[i][j]);
        }
    }
    search(n,k,0,0);
    printf("%d",count);
    return 0;
}