#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    //一维数组
    // int n;
    // cin>>n;
    // int* a=new int[n];
    // a[2]=9;
    // printf("%d",a[2]);
    // delete[] a;
    // a=nullptr;
    //二维动态数组
    int n,m;
    cin>>n>>m;
    //指针数组
    // int **a =new int*[n];
    // for(int i=0;i<n;i++)
    // {
    //     a[i]=new int[m];
    // }
    // for(int i=0;i<n;i++)
    // {
    //     delete[] a[i];
    // }
    // delete[] a;
    //连续内存
    // int *a=new int[n*m];
    // int val=a[1*m+2];
    // delete[] a;
    //动态数组
    //可以读取不知道个数，直到输入结束
    vector<int> a;
    int temp;
    // a.push_back(10);
    //动态扩容
    while(cin>>temp)
    {
        a.push_back(temp);
    }
    vector<int> b(n,5);
    vector<vector<int>> c(n,vector<int>(m));
    c[1][0]=12;
    // cout<<a.size()<<a[0]<<b[0]<<c[1][0]<<endl;
    //快速清空（a.size()=0/a.empty()=true）
    // a.clear();
    //size直接变成0，所有元素被移除，但是内存还在  a.capacity()
    //想保留大小，只是清空内容
    fill(a.begin(),a.end(),0);
    cout<<a[0];
    a.assign(n,8);
    cout<<a[0];
    a.clear();
    a.shrink_to_fit();
    // a.reserve(10000);
    return 0;
}