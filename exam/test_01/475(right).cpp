#include<stdio.h>

int main()
{
    int arr1[20],arr2[20],x;
    int len1=0,len2=0;
    int i,a;

    while(scanf("%d",&x))
    {
        if(x==-1)
        break;
        arr1[len1]=x;
        len1++;
    }
    while(scanf("%d",&x))
    {
        if(x==-1)
        break;
        arr2[len2]=x;
        len2++;
    }
    printf("%d\n%d\n",len1,len2);

    for(i=0;i<len1&&i<len2;i++)
    {
        if(arr1[i]!=arr2[i])
        {
            a=arr1[i]-arr2[i];
            printf("%d",a);
            return 0;
        }
    }
    //无法判断：有两种情况（长度相等=0；长度不等not Comparable)
    if(len1==len2)
    {
        printf("0");
    }
    else
    {
        printf("Not Comparable");
    }
    return 0;
}