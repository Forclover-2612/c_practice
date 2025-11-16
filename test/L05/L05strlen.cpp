#include<stdio.h>
#define MAX_SIZE 100

int main()
{
    char buf[MAX_SIZE];
    int len=0;
    // while(fgets(buf,MAX_SIZE,stdin)!=NULL)//比较的应该是返回值
    // {
    //     len++;
    // }
    fgets(buf,MAX_SIZE,stdin);
    //fgets也会将换行符算在里面
    // gets(buf);
    while(buf[len]!='\n')
    len++;
    printf("%d\n",len);
    return 0;
}