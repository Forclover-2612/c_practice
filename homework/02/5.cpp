#include<iostream>
using namespace std;

char ConverseLetter(char c)
{
    if(c>='a'&&c<='z')
    return (c-32);
    else
    return (c+32);
}
int main()
{
    char c;
    cin>>c;
    cout<<ConverseLetter(c);
    return 0;
}