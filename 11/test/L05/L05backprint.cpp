#include<iostream>
using namespace std;

int main()
{
    //逆序输出
    int i=0;
    int arr[5]={0};
    int minnumber=0;//有个bug：整数最小值仍大于0
    //改进：另写一个循环，令第一个元素为min
    for(i=0;i<5;i++)
    {
        cin>>arr[i];
    }
    minnumber=arr[0];
    for(i=0;i<5;i++)
    {
        if(minnumber>arr[i])
        {
            minnumber=arr[i];
        }
    }
    cout<<minnumber<<endl;
    for(i=0;i<5;i++)
    {
        cout<<arr[4-i]<<" ";
    }
    return 0;
}