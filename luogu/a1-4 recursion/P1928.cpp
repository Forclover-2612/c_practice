#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
// char str[20000];
// char same_str[20000];
// void decompress(int n)
// {
//     while()
// }
string decompress()
{
    int k;
    char ch;
    //注意！！！是否要初始化（或者说是一定要放在函数内部
    string s;//默认是空字符串
    string str;
    //cin>>ch会自动跳过换行符
    while(cin>>ch)
    {
        if(ch=='[')
        {
            cin>>k;
            str=decompress();
            for(int i=0;i<k;i++)
            s+=str;
        }
        else if(ch==']')
        {
            return s;
        }
        else{
            s+=ch;
        }
    }
    //结尾一定要return
    return s;
}
int main()
{
    cout<<decompress();
    return 0;
}
//OJ系统会发送EOF