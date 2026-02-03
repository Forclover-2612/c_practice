#include<iostream>
using namespace std;

//当n很大时，可能不能输出
int Fabonacci(int n)
{
    if(n<=2)
    return 1;
    else
    return Fabonacci(n-1)+Fabonacci(n-2);
}

int main()
{
    int n;
    cin>>n;
    printf("%d",Fabonacci(n));
    return 0;
}