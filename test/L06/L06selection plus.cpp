#include<iostream>
using namespace std;

int main()
{
    int n,min,tmp,upper,lower;
    cin>>n>>lower>>upper;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int j=lower;j<=upper-1;j++)//-1最后一个元素不用比较
    {
        min=j;//先存下标，不用比较第一个元素（先直接假设第一个元素是最小的）
        // printf("%d\n",min);
        for(int t=j+1;t<=upper;t++)//假定下标的情况下要考虑边界
        {
            if(arr[min]>arr[t])
            min=t;//先存下标，后面发现不相等时再做一次交换
            if(min!=j)
            {
                tmp=arr[j];
                arr[j]=arr[min];
                arr[min]=tmp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}