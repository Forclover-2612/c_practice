#include<stdio.h>
#include<string.h>
int used[100];
char ans[100];
void cope(char *s,int p,int q)
{
    if(p==q)
    {
        for(int i=0;i<q;i++)
        {
            printf("%c",*(s+i));
        }
        printf("\n");
        return;
    }
    for(int i=p;i<q;i++)
    {
        char temp;
        temp=s[i];
        s[i]=s[p];
        s[p]=temp;
        cope(s,p+1,q);
        temp=s[i];
        s[i]=s[p];
        s[p]=temp;
    }
}
//还可以处理重复元素
void tradition(char *s,int p,int q)
{
    if(p>=q)
    {
        for(int i=0;i<q;i++)
        {
            printf("%c",ans[i]);
        }
        printf("\n");
        return;
    }
    for(int i=0;i<q;i++)
    {
        if(!used[i])
        {
            ans[p]=s[i];
            used[i]=1;
            tradition(s,p+1,q);
            used[i]=0;
        }
    }
}
int main()
{
    char s[100];
    scanf("%s",s);
    int len=strlen(s);
    // cope(s,0,len);
    tradition(s,0,len);
    return 0;
}