#include<stdio.h>
#include<string.h>
#include<algorithm>
char str[300];
int main()
{
    // 读取输入
    fgets(str, sizeof(str), stdin);
    int len = strlen(str);
    int left=0,right=0;
    int cnt[256]={0};//记录每个字符出现的次数
    int types=0;//记录窗口内凑齐了几个目标字符
    int min_len=1e9;
    while(right<len)
    {
        //step1:扩大窗口并记录
        char c=str[right];
        if(c=='b'||c=='o'||c=='y')
        {
            if(cnt[c]==0)
            types++;
            cnt[c]++;
        }
        //step2:向左缩小窗口
        while(types==3)
        {
            //更新答案
            min_len=std::min(min_len,right-left+1);

            //step3：缩小窗口
            char d=str[left];
            if(d=='b'||d=='o'||d=='y')
            {
                cnt[d]--;
                if(cnt[d]==0)
                types--;
            }
            left++;
        }
        right++;
    }
    if(min_len==1e9)
    printf("No solution\n");
    else
    printf("%d",min_len);
    return 0;
}