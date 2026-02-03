#include<stdio.h>
#include<string.h>
int main()
{
    char str[35];
    fgets(str,35,stdin);//会读取换行符
    int n;
    scanf("%d",&n);
    int len=strlen(str);
    for(int i=0;i<len-1;i++)
    {
        if(str[i]+n<='z')
        str[i]=str[i]+n;
        else
        {
            str[i]='a'+n-('z'-str[i])-1;
        }
    }
    str[len-1]='\0';
    printf("%s",str);
    return 0;
}