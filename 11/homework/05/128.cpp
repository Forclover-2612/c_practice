#include<stdio.h>
#include<math.h>
struct data{
    int k;
    int s;
};

int main()
{
    int n,m;//n是参加笔试的选手人数，m是录取人数
    scanf("%d %d",&n,&m);
    struct data arr[n];
    int i,j;
    int max,min;
    struct data temp;
    int plus;
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&arr[i].k,&arr[i].s);
    }
    //排序
    for(i=0;i<n-1;i++)
    {
        max=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[max].s<arr[j].s)
            max=j;
            else if(arr[max].s==arr[j].s)
            {
                if(arr[max].k>arr[j].k)
                {
                    max=j;
                }
            }
        }
        if(max!=i)
        {
            temp=arr[max];
            arr[max]=arr[i];
            arr[i]=temp;
        }
    }
    //计算最少人数
    min=floor(m*1.5);
    //考察排名在min之后的数据
    i=min;
    plus=0;
    while(arr[i].s==arr[min-1].s&&i<n)
    {
        plus++;
        i++;
    }
    printf("%d %d\n",arr[min-1].s,min+plus);
    for(i=0;i<min+plus;i++)
    {
        printf("%d %d\n",arr[i].k,arr[i].s);
    }
    return 0;
}