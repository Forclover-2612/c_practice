#include<stdio.h>
#include<string.h>
int main()
{
    //判断数据类型
    //字符串：有字符,没有小数点
    //小数：有小数点又没有字符
    //剩下的是整数
    char str[1005];
    // scanf("%s",str);
    fgets(str,1005,stdin);
    int len=strlen(str);
    double a;
    int b;
    for(int i=0;i<len;i++)
    {
        if(str[i]=='.')
        {
            sscanf(str,"%lf",&a);
            printf("%d",(int)a);
            return 0;
        }
        if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z'))
        {
            for(int j=i;j<len;j++)
            {
                if(str[j]>='a'&&str[j]<='z')
                {
                    str[j]-=32;
                }
            }
            printf("%s",str);
            return 0;
        }
    }
    sscanf(str,"%d",&b);
    printf("%d",b+1);
    return 0;
}