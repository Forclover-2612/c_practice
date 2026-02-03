#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void replaceStr(char*s,char *s1,char *s2)
{
    int len=strlen(s);
    int len1=strlen(s1);
    int len2=strlen(s2);
    char *pos=s;
    //统计数量
    int count=0;
    while((pos=strstr(pos,s1))!=NULL)
    {
        count++;
        pos+=len1;
    }
    if(count==0)
    return;
    int newLen=len+count*(len2-len1)+1;
    char *temp=(char*)malloc(sizeof(char)*newLen);
    if(temp==NULL)
    return;
    //!必须初始化为空字符串
    temp[0]='\0';
    //读指针
    char *pos_read=s;
    while((pos=strstr(pos_read,s1))!=NULL)
    {
        int preLen=pos-pos_read;
        strncat(temp,s,preLen);//会自动封口
        // temp[preLen]='\0';
        strncat(temp,s2,len2);
        pos_read+=len1;
    }
    //拼接剩下的
    strcat(temp,pos_read);//后面有\0自动停止
    strcpy(s,temp);
    free(temp);
}
void insertStr(char*s,char *s1,char *s2)
{
    int len=strlen(s);
    int len1=strlen(s1);
    int len2=strlen(s2);
    char *pos=s;
    char *lastPos=NULL;
    while((pos=strstr(pos,s1))!=NULL)
    {
        lastPos=pos;
        pos+=len1;
    }
    int newLen=len+len2+1;
    char *temp=(char*)malloc(sizeof(char)*newLen);
    if(temp==NULL)
    return;
    strncpy(temp,s,lastPos-s);
    //两个拼接
    temp[lastPos-s]='\0';
    strcat(temp,s2);
    strcat(temp,lastPos);
    strcpy(s,temp);
    free(temp);
}
int main()
{
    char str[200];
    char str1[10];
    char str2[10];
    // gets(str);
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")]=0;
    scanf("%s",str1);
    scanf("%s",str2);
    // replaceStr(str,str1,str2);
    insertStr(str,str1,str2);
    printf("%s",str);
    return 0;
}