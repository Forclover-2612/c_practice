#include<stdio.h>
#include<string.h>
char str1[1000006];
char str2[1000006];
int next[1000006];
int main()
{
    //！注意：fgets会读取换行符
    // fgets(str1,sizeof(str1),stdin);
    // fgets(str2,sizeof(str2),stdin);

    // int len1=strlen(str1);
    // if(len1>0&&str1[len1-1]=='\n')
    // str1[len1-1]='\0';
    // int len2=strlen(str2);
    // if(len2>0&&str2[len2-1]=='\n')
    // str2[len2-1]='\0';
    scanf("%s",str1);
    scanf("%s",str2);

    //重新获取长度
    int len1=strlen(str1);
    int len2=strlen(str2);

    //1.构建next数组
    // next[i] 表示模式串 str2[0...i] 的最长相等前后缀长度
    int j=0;//j 代表当前最长相等前后缀的长度
    next[0]=0;
    for(int i=1;i<len2;i++)
    {
        while(j>0&&str2[i]!=str2[j])
        {
            j=next[j-1];//不匹配，退回到前一个可能的位置
        }
        if(str2[i]==str2[j])
        j++;
        next[i]=j;
    }

    //2.使用KMP进行匹配
    //滑动字符串：前缀对齐后缀
    j=0;//现在代表str2中已经匹配的长度
    for(int i=0;i<len1;i++)
    {
        while(j>0&&str1[i]!=str2[j])
        {
            j=next[j-1];
        }
        if(str1[i]==str2[j])
        {
            j++;
        }
        if(j==len2)
        {
            printf("%d\n",i-len2+2);
            j=next[j-1];
        }
    }
    for(int i=0;i<len2;i++)
    {
        printf("%d ",next[i]);
    }
    return 0;
}