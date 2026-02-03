#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    const double eps=0.0001;
    double x,sinx,item;
    int n=2;
    int sign=-1;
    cin>>x;
    sinx=x;
    item=x*x*x/6;//第三项
    while(fabs(item)>eps)
    {
        sinx=sinx+item*sign;
        item=item*x*x/((2*n)*(2*n+1));
        sign=-sign;
        n++;
    }
    cout<<sinx<<endl;
    return 0;
}