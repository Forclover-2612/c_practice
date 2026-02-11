#include<stdio.h>
//给你一个字符串 s 1，它是由某个字符串s2不断自我连接形成的（保证至少重复 2 次）。
//但是字符串s2是不确定的，现在只想知道它的最短长度是多少。

//结论：最小循环节长度=L-next[L-1](这是整个字符串的border)
//错位重叠：构成周期性 s[i]=s[i+平移距离]

char s[1000006];
int next[1000006];
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    int j=0;
    next[0]=0;
    for(int i=1;i<n;i++)
    {
        while(j>0&&s[i]!=s[j])
        {
            j=next[j-1];
        }
        if(s[i]==s[j])
        {
            j++;
        }
        next[i]=j;
    }

    printf("%d",n-next[n-1]);
    return 0;
}