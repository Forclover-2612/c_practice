#include<stdio.h>
#include<string.h>
char str1[1000006];
char str2[1000006];
int main()
{
    //！注意：fgets会读取换行符
    fgets(str1,sizeof(str1),stdin);
    fgets(str2,sizeof(str2),stdin);

    int len1=strlen(str1);
    if(len1>0&&str1[len1-1]=='\n')
    str1[len1-1]='\0';
    int len2=strlen(str2);
    if(len2>0&&str2[len2-1]=='\n')
    str2[len2-1]='\0';

    char *pos=str1;
    while((pos=strstr(pos,str2))!=NULL)
    {
        printf("%d\n",pos-str1+1);
        pos++;
    }

    
    return 0;
}