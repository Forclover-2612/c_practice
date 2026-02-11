#include<stdio.h>
//用映射的思想
int arr[10005];
int main()
{
    int l,m;
    scanf("%d %d",&l,&m);
    int left,right;
    int count=0;
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&left,&right);

        for(int j=left;j<=right;j++)
        {
            if(arr[j]==0)
            {
                arr[j]=1;
                count++;
            }
            // else
            // {
            //     continue;
            // }
        }
    }
    printf("%d",l+1-count);
    return 0;
}