#include <stdio.h>
#include <string.h>
#define max 22

int main()
{
    int n;
    char str[5];
    int arr[5];
    scanf("%d", &n);
    scanf("%s", str);
    int i, j,t,p;
    char input[1001][max];
    int num[1001][max] = {0};
    int no[1001];
    int len = 0;
    char temp[max];
    int tmp;
    //简化：下标对应优先级
    for (i = 1; i <= 4; i++)
    {
        if (str[i-1] == 'A')
        {
            arr[1] = 5-i;
        }
        if (str[i-1] == 'C')
        {
            arr[2] = 5-i;
        }
        if (str[i-1] == 'G')
        {
            arr[3] = 5-i;
        }
        if (str[i-1] == 'T')
        {
            arr[4] = 5-i;
        }
    }
    for (i = 0; i < n; i++)
    {
        len=0;
        scanf("%s", &input[i]);
        for (j = 0; j < 20; j++)
        {
            if (input[i][j] == 'A')
            {
                num[i][j] = arr[1];
                len++;
            }
            else if (input[i][j] == 'C')
            {
                num[i][j] = arr[2];
                len++;
            }
            else if (input[i][j] == 'G')
            {
                num[i][j] = arr[3];
                len++;
            }
            else if (input[i][j] == 'T')
            {
                num[i][j] = arr[4];
                len++;
            }
            else
            {
                break;
            }
        }
    }
    //len是碱基对长度
    //比较num大小
    //向前比较(冒泡排序思路)但需要三重循环？
    //一轮比较之后，只保证最小的排到了后面
    for(i=0;i<n-1;i++)
    {
        for(j=1;j<n-i;j++)
        {
            for(t=0;t<len;t++)
            {
                //比较的是它们对应的数字，但是我并没有交换数字导致错误
                //而且我逐位比较，这是错误的
                if(num[j-1][t]>num[j][t])
                break;
                else if(num[j][t]>num[j-1][t])
                {
                    //是否可以用结构体简化
                    strcpy(temp,input[j]);
                    strcpy(input[j],input[j-1]);
                    strcpy(input[j-1],temp);
                    for(p=0;p<len;p++)
                    {
                        tmp=num[j][p];
                        num[j][p]=num[j-1][p];
                        num[j-1][p]=tmp;
                    }
                    break;
                }
            }
        }
    }
    //输出
    for(i=0;i<n;i++)
    {
        printf("%s\n",input[i]);
    }
    return 0;
}
//考虑长度不相同的情况