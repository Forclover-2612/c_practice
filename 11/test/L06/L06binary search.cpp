#include<stdio.h>

int main()
{
    int num;
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    scanf("%d",&num);
    int low=0;
    int high=9;
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(num==arr[mid])
        {
            printf("%d",mid);
            return 0;
        }
        if(num<arr[mid])
        {
            high=mid-1;
        }
        else
        low=mid+1;
    }
    printf("Not Found");
    return 0;
}