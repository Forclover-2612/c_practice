#include<stdio.h>

int main()
{
    long long a,b;
    char c;
    scanf("%lld %lld %c",&a,&b,&c);
    if(c=='+')
    printf("%lld",a+b);
    else if(c=='-')
    printf("%lld",a-b);
    else if(c=='*')
    printf("%lld",a*b);
    else if(c=='/')
    {
        if(b==0)
        printf("NO");
        else
        printf("%lld",a/b);
    }
    else if(c=='%')
    {
        if(b==0)
        printf("NO");
        else
        printf("%lld",a%b);
    }
    else
    printf("NO");
    return 0;
}