#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> a;
    while(n!=1)
    {
        a.push_back(n);
        if(n%2!=0)
        n=n*3+1;
        else
        n=n/2;
    }
    a.push_back(1);
    for(int i=a.size()-1;i>=0;i--)
    {
        cout<<a[i]<<' ';
    }
    return 0;
}