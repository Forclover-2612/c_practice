#include<stdio.h>

int main()
{
    // long long num[1000];
    long long sum=0;
    char str[1000];
    int i=0;
    fgets(str,1000,stdin);
    //这要怎么移动指针
    // while(sscanf(str,"%lld",&num[i])!=0)
    // {

    // }
    char *read=str;
    while(*read!='\n')
    {
        int count=1;
        char temp[16];
        long long num;
        //遇到一个数字
        if(*read>='0'&&*read<='9')
        {
            temp[0]=*read;
            while(*(read+count)>='0'&&*(read+count)<='9')
            {
                temp[count]=*(read+count);
                count++;
            }
            temp[count]='\0';
            sscanf(temp,"%lld",&num);
            sum+=num;
            read+=count-1;
        }
        read++;
    }
    printf("%lld",sum);
    return 0;
}