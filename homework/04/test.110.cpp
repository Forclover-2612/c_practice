#include<iostream>
#include<string>
#include<stdio.h>
#include<string.h>
using namespace std;

int main()
{
    string str;
    cin>>str;
    if(str.length()%2==0)//没有末尾的\0
    cout<<"yes";
    return 0;
}