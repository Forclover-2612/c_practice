#include<stdio.h>
#include<string.h>
int main()
{
    char str[]="0123456789ABCDEF";
    char n[60];
    long long res=0;
    int h;
    scanf("%s %d",n,&h);
    int len=strlen(n);
    for(int i=0;i<len;i++)
    {
        int idx=0;
        char c=n[i];
        // while(str[idx]!=n[i])
        // {
        //     idx++;
        // }
        //直接使用ASCII值的写法
        if(c>='0'&&c<='9')
        {
            idx=c-'0';
        }
        else if(c>='A'&&c<='F')
        {
            idx=c-'A'+10;
        }
        else if(c>='a'&&c<='f')
        {
            idx=c-'a'+10;
        }
        res=res*h+idx;
    }
    printf("%lld\n",res);
    return 0;
}