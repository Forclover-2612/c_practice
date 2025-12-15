#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void convert(long long n,int h)
{
    if(n==0)
    return;
    convert(n/h,h);
    char str[]="0123456789ABCDEF";
    printf("%c",str[n%h]);
}
int main()
{
    //同时考虑0和负数的情况
    char str[]="0123456789ABCDEF";
    char res[70];
    long long n,h;
    int isNagetive=0;
    int count=0;
    scanf("%lld %lld",&n,&h);
    if(n==0)
    {
        printf("0\n");
        return 0;
    }
    if(n<0)
    {
        printf("-");
        n=-n;
    }
    convert(n,h);
    // if(n<0)
    // {
    //     isNagetive=1;
    //     n=-n;
    // }
    // long long num=n;
    // while(num!=0)
    // {
    //     int t=num%h;
    //     res[count++]=str[t];
    //     num=num/h;
    // }
    // //如果是负数，加上符号
    // if(isNagetive)
    // {
    //     res[count++]='-';
    // }
    // res[count]='\0';
    // //直接倒序输出就好
    // for(int i=count-1;i>=0;i--)
    // {
    //     printf("%c",res[i]);
    // }
    printf("\n");
    return 0;
}