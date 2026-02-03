#include<stdio.h>
#include<string.h>
int main()
{
    //基础用法；找到子串
    //其他：可以利用返回的指针，直接获取子串之后的部分
    const char *haystack="I love programming, programming is fun!";
    const char *needle="programming";

    // char *pos=strstr(haystack,needle);
    // char *pos=haystack;不安全的写法
    const char *pos=haystack;
    int count=0;
    while((pos=strstr(pos,needle))!=NULL)//注意运算优先级问题！
    {
        printf("%d:%ld\n",++count,pos-haystack);
        pos+=strlen(needle);
    }
    if(count==0)
    {
        printf("No found");
    }
    return 0;
}