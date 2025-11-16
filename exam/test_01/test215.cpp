#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n;
    char ch[20]="book";
    cin>>n;
    int arr[n][3];
    int ans=0;
    for(int i=0;i<n;i++)
    {
        string s;
        int a,b;
        cin>>s>>a>>b;
        ans+=a*b;
    }
    printf("%d",ans);
    return 0;
}