#include<stdio.h>
int used[1005];
int count[1005];
int move[4]={-2,-1,1,2};
//全部平移？还是分类讨论
//将1平移到2，在1的旁边新增0,1？
long long route(int m)
{
    if(m<=1)
    return 1;
    // for(int i=0;i<4;i++)
    // {
    //     int k=move[i]+n;
    //     if(used[k]==0)
    //     {
    //         used[k]=1;
            
    //     }
    // }
    return route(m-1)+route(m-2);
}
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    // used[1]=1;
    // used[0]=1;
    printf("%lld",route(n-m));
    return 0;
}