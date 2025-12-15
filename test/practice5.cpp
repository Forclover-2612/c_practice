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
        while(str[idx]!=n[i])
        {
            idx++;
        }
        res=res*h+idx;
    }
    printf("%lld\n",res);
    return 0;
}