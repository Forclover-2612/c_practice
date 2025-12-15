#include<stdio.h>
#include<string.h>

// 工具函数1：将字符转换为数值 (支持 '0'-'9', 'A'-'F', 'a'-'f')
int charToInt(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
    if (c >= 'a' && c <= 'z') return c - 'a' + 10;
    return 0;
}
//工具函数2：将数值转换为字符
char intToChar(int v)
{
    if(v>=0&&v<=9)
    return v+'0';
    if(v>=10&&v<=35)
    return v+'a'-10;
    return '?';
}
//任意进制->十进制
long long toDecimal(char *n,int base)
{
    long long res=0;
    int len=strlen(n);
    for(int i=0;i<len;i++)
    {
        res=res*base+charToInt(n[i]);
    }
    return res;
}
//十进制->任意进制
void fromDecimal(long long num,int base)
{
    if(num==0)
    {
        printf("0\n");
        return ;
    }
    char res[100];
    int count;
    while(num!=0)
    {
        int t=num%base;
        res[count++]=intToChar(t);
        num/=base;
    }
    for(int i=count-1;i>=0;i--)
    {
        printf("%c",res[i]);
    }
}
int main()
{
    int sourceBase, targetBase;
    char n[100];
    scanf("%d %d %s",&sourceBase,&targetBase,n);
    //先转化为十进制
    long long num=toDecimal(n,sourceBase);
    //再转化为目标进制
    fromDecimal(num,targetBase);
    return 0;
}