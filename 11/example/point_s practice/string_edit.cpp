#include <stdio.h>
#include <string.h>
// #include<stdlib.h>
// char temp[1000];
// 得到正确的字符串
char parseCmd(char *s, char *str1, char *str2)
{
    // 先剥离出第一个字母
    char *start = s;
    //    s+=2;//注意是加1还是加2
    s += 1;
    if (*s == ' ')
        s++;
    while (*s != ' ' && *s != '\0')
    {
        *str1++ = *s++; // 注意是先使用后++
    }
    *str1 = '\0';
    s += 1;
    if(*s== ' ')s+=1;
    while (*s != ' ' && *s != '\0')
    {
        *str2++ = *s++;
    }
    *str2 = '\0';
    return *start;
}

int countStr(char *s, char *str1)
{
    if(str1==NULL||*str1=='\0')
    return 0;
    // 当遇到第一个字符一样的？就开始循环
    // 第二个版本，使用strstr
    int count = 0;
    char *pos = s;
    while ((pos = strstr(pos, str1)) != NULL)
    {
        count++;
        pos += strlen(str1);
    }
    return count;
}
// 删除第一个子串,用动态数组
void deleteStr(char *s, char *str1)
{
    char temp[1000];
    // if(!countStr(s,str1))
    // return;
    char *pos;
    pos=strstr(s,str1);
    if(pos==NULL)
    return;
    int lenStr1=strlen(str1);
    int lenS=strlen(s);

    //1.计算新长度
    int newLen=lenS-lenStr1+1;//+1的作用？填入'\0'吗
    //2.申请内存
    // char *temp=(char *)malloc(newLen*sizeof(char));
    // if(temp==NULL)return;
    //3.拷贝前半部分
    int preLen=pos-s;
    strncpy(temp,s,preLen);
    temp[preLen]='\0';//一定要封口，不用再+1了
    //4.拼接后半部分
    strcat(temp,pos+lenStr1);//会封口
    //5.将原结果拷回原字符串
    strcpy(s,temp);
    //释放临时内存
    // free(temp);
}
//插入到最后一个子串的前面
void insertStr(char *s, char *str1, char *str2)
{
    //记录最后一次出现的位置
    //注意！pos最后一定变成空指针
    //一定要初始化
    char temp[1000];
    char *pos=s;
    char *lastPos=NULL;
    int lenStr1=strlen(str1);
    while((pos=strstr(pos,str1))!=NULL)
    {
        lastPos=pos;
        pos+=lenStr1;
    }
    if(lastPos==NULL)return;
    int lenS=strlen(s);
    int lenStr2=strlen(str2);
    //计算新长度
    int newLen=lenS+lenStr2+1;
    //申请内存
    // char *temp=(char *)malloc(newLen*sizeof(char));
    // if(temp==NULL)return;
    //拷贝加两个拼接
    int preLen=lastPos-s;
    strncpy(temp,s,preLen);
    temp[preLen]='\0';

    strcat(temp,str2);

    strcat(temp,lastPos);

    strcpy(s,temp);
    // free(temp);
}
//将全部子串进行替换
char *replaceStr(char *s, char *str1, char *str2)
{
    char temp[1000];
    int count=countStr(s,str1);
    int lenS=strlen(s);
    int lenStr1=strlen(str1);
    int lenStr2=strlen(str2);
    //计算新长度
    int newLen=lenS+count*(lenStr2-lenStr1)+1;

    // char*temp=(char*)malloc(newLen*sizeof(char));
    // if(temp==NULL)return s;
    //初始化temp为空字符串！否则strcat会出错
    temp[0]='\0';
    char *pos = s;
    //需要一个指向当前阅读位置的指针
    char *p_read=s;
    while ((pos = strstr(p_read, str1)) != NULL)//一定要从p_read开始寻找
    {
        int preLen=pos-p_read;
        int current_pos=p_read-s; 
        //拷贝是从temp其实位置开始复制的，是错误的
        // strncpy(temp,p_read,preLen);
        // temp[preLen+current_pos]='\0';//一定要更新下标
        //不需要手动封口
        // strncat 会自动追加到 temp 末尾，并自动添加 \0
        strncat(temp,p_read,preLen);
        //拼接
        strcat(temp,str2);
        //更新读取位置
        p_read=pos+lenStr1;
    }
    //找不到的时候，直接把剩下的拷贝
    strcat(temp,p_read);
    strcpy(s,temp);
    // free(temp);
    return s;
}
int main()
{
    char s[500], cmdStr[500], str1[500], str2[500], cmd;
    char *pStr1, *pStr2;

    gets(s);
    gets(cmdStr);
    pStr1 = str1;
    pStr2 = str2;

    cmd = parseCmd(cmdStr, pStr1, pStr2);

    switch (cmd)
    {
    case 'C':
        printf("%d\n", countStr(s, pStr1));
        break;
    case 'D':
        deleteStr(s, pStr1);
        printf("%s\n", s);
        break;
    case 'I':
        insertStr(s, pStr1, pStr2);
        printf("%s\n", s);
        break;
    case 'R':
        printf("%s\n", replaceStr(s, pStr1, pStr2));
        break;
    }
    return 0;
}
