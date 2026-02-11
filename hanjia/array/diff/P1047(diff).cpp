#include<iostream>
using namespace std;
//差分数组 diff[i] 记录的是“当前位置 
//diff[i] = a[i] - a[i-1]
//上下车的理解：diff[2]++（在 2 号站上车 1 人）diff[5]--（在 5 号站下车 1 人）
//差分数组只需要修改开头和结尾的下一个两个位置，就能通过“前缀和”影响中间所有的元素。

int diff[10005];

int main()
{
    int l,m;
    cin>>l>>m;
    int left,right;
    for(int i=0;i<m;i++)
    {
        cin>>left>>right;
        diff[left]++;
        diff[right+1]--;
    }
    int curr_sum=0;
    int remain_count=0;
    for(int i=0;i<=l;i++)
    {
        curr_sum+=diff[i];
        if(curr_sum==0)
        remain_count++;
    }
    cout<<remain_count<<endl;
    return 0;
}