#include<stdio.h>
#define MAX 101
#define max 21
struct student{
    int maxn=11,minn=-1,a[max];//先假定一个不可能的数字
    double average,total;
}student[105];
//最小值函数
int min(int arr[][max],int i,int m)
{
    int a=arr[i][0];
    for(int j=1;j<m;j++)
    {
        if(arr[i][j]<a)
        a=arr[i][j];
    }
    return a;
}
//最大值函数
int max_(int arr[][max],int i,int m)
{
    int a=arr[i][0];
    for(int j=1;j<m;j++)
    {
        if(arr[i][j]>a)
        a=arr[i][j];
    }
    return a;
}
double calculate(int arr[][max],int n,int m)
{
    int i,j;
    double point[n];
    int sum=0;
    int count=0;
    for(i=0;i<n;i++)
    {
        sum=0;
        int a=max_(arr,i,m);
        int b=min(arr,i,m);
        for(j=0;j<m;j++)
        {
            sum+=arr[i][j];           
        }
        point[count++]=(sum-a-b)/(double)(m-2); 
    }
    double c=point[0];
    for(i=0;i<count;i++)
    {
        if(point[i]>c)
        c=point[i];
    }
    return c;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int arr[MAX][max];
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    double num=calculate(arr,n,m);
    printf("%.2f",num);
    return 0;
}
//改进，一边输入的时候一边比较
//还可以用结构体实现