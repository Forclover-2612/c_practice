#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//运用动态数组排序和去重
int main()
{
    int n;
    cin>>n;
    vector<int> a;
    // int temp;
    // while(cin>>temp)
    // {
        
    // }
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    //begin和end也是迭代器，左闭右开原则
    //v.begin()：指向容器的第一个元素
    //v.end()：指向容器最后一个元素之后的那个位置
    //it！=v.end()就没有走完，空容器：begin=end，end()-begin()就是元素的总个数
    sort(a.begin(),a.end());
    //去重
    //unique返回的是去重后出现重复元素（废弃数据）的位置，a.size还是没有变
    //返回的是it(迭代器)高级指针：专门为容器(vector,list,map)设计的
    //unique要针对有序集合（无序用unordered_set）
    a.erase(unique(a.begin(),a.end()),a.end());
    cout<<a.size()<<endl;
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<' ';
    }
    return 0;
}