#include <stdio.h>
#include <string.h>

char str[300];

int main()
{
     // 读取输入
    fgets(str, sizeof(str), stdin);
    int len = strlen(str);

    int count_boy = 0;
    int count_girl = 0;

    for(int i=0;i<len;i++)
    {
        if(str[i]=='b'||str[i+1]=='o'||str[i+2]=='y')
        {
            count_boy++;
        }
        if(str[i]=='g'||str[i+1]=='i'||str[i+2]=='r'||str[i+3]=='l')
        {
            count_girl++;
        }
    }
    printf("%d\n%d", count_boy, count_girl);
    return 0;
}