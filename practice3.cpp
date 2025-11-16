#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    scanf("%d",&n);
    char str[5];
    sprintf(str,"%d",n);
    int len=strlen(str);
    for(int i=len-1;i>=0;i--)
    {
        printf("%d,",(int)str[i]-48);
    }
    printf("%d",len);
    return 0;
}