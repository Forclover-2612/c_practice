#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
    int arr1[20];
    int arr2[20];
    int x;
    int i=0,j=0;
    // while(1)
    // {
    //     cin>>x;
    //     if(x==-1)
    //     break;
    //     arr1[i]=x;
    //     i++;
    // }
    // while(1)
    // {
    //     cin>>x;
    // }
    while(1)
    {
        cin>>arr1[i];
        if(arr1[i]==-1)
        break;
        i++;
    }
    while (1)
    {
        cin >> arr2[j];
        if (arr2[j] == -1)
            break;
        j++;
    }
    // for(int j=0;j<i;j++)
    // {
    //     printf("%d\n",arr1[j]);
    // }
    printf("%d\n",i);
    printf("%d\n",j);
    for(int m=0;m<i&&m<j;m++)
    {
        if(arr1[m]!=arr2[m])
        {
            int a=arr1[m]-arr2[m];
            printf("%d",a);
            return 0;
        }
    }
    if(i==j)
    {
        printf("0");
    }
    else
    {
        printf("Not Comparable");
    }
    return 0;
}