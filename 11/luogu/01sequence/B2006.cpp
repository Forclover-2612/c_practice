#include<iostream>
#include<iomanip>
#include<stdio.h>
using namespace std;

int main()
{
    double x,a,y,b;//要求输入正整数是不是不一定用int
    cin>>x>>a>>y>>b;
    cout<<fixed<<setprecision(2)<<(b*y-a*x)/(b-a)<<endl;
    return 0;
}