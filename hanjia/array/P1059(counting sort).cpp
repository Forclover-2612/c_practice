#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long n,ans=0;
//桶排序
int main()
{
    int n;
    cin>>n;
    vector<int> a(1005,0);
    for(int i=0;i<n;i++)
    {
        int b;
        cin>>b;
        a[b]++;//内存访问错误，要先定义大小
        if(a[b]==1)
        ans++;
    }
    //限制是1到1000，可做
    cout<<ans<<endl;
    for(int i=1;i<=1000;i++)
    {
        if(a[i]>0)
        cout<<i<<' ';
    }
    return 0;
}