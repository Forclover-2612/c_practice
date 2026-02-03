#include<stdio.h>

int main()
{
    char ch,m;
    int n=0;
    for(ch='A';ch<='D';ch++)
    {
        n=0;//对n的初始化很重要！
        if(ch!='A')
        n++;
        if(ch=='C')
        n++;
        if(ch=='D')
        n++;
        if(ch!='D')
        n++;
        if(n==3)
        printf("%c",ch);
    }
    return 0;
}