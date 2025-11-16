#include<stdio.h>

void year(int x,int y)
{
    int count=0;
    int arr[1500];
    for(int i=x;i<=y;i++)
    {
        if((i%100!=0&&i%4==0)||i%400==0)
        {
            arr[count++]=i;
            i+=3;
        }
    }
    printf("%d\n",count);
    for(int i=0;i<count;i++)
    {
        printf("%d ",arr[i]);//注意输出格式
    }
}
int main()
{
    int x,y;
    scanf("%d %d",&x,&y);
    year(x,y);
    return 0;
}