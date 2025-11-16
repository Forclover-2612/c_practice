#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    scanf("%s", str);
    // 在什么位置填入加号
    int i, j, t, p;
    int len = strlen(str);
    int gaps = len - 1;
    long long a, b, c, d;
    long n = gaps * (gaps - 1) * (gaps - 2) / 6;//计算可能情况数
    long long arr[n];//用于存放结果
    int y = 0; // 数组下标
    long long temp;
    // 生成三个插入的位置（i,j,t分别代表在第几个字符后面跟着+号）
    char expr[100];
    for (i = 0; i <= gaps - 3; i++)//i必须从0开始
    {
        for (j = i + 1; j <= gaps - 2; j++)
        {
            for (t = j + 1; t <= gaps - 1; t++)
            {
                // 初始化expr为空
                // for (p = 0; p < 100; p++)
                // {
                //     expr[p] = '\0';
                // }
                // int idx = 0;
                // // 先遍历字符串
                // //核心代码
                // for (int x = 0; x < len; x++)
                // {
                //     expr[idx++] = str[x];
                //     if (x == i || x == j || x == t)
                //     {
                //         expr[idx++] = '+'; // 不能写成双引号
                //     }
                // }
                // int ret = sscanf(expr, "%lld+%lld+%lld+%lld", &a, &b, &c, &d);
                // long long sum = a + b + c + d;
                // arr[y]=sum;//赋值不能颠倒
                // y++;
                //另一种写法
                long long sum=0;
                long long cur=0;

                for(p=0;p<=i;p++)
                {
                    cur*=10;
                    cur+=str[p]-'0';
                }
                sum+=cur;
                cur=0;

                for(p=i+1;p<=j;p++)
                {
                    cur*=10;
                    cur+=str[p]-'0';
                }
                sum+=cur;
                cur=0;

                for(p=j+1;p<=t;p++)
                {
                    cur*=10;
                    cur+=str[p]-'0';
                }
                sum+=cur;
                cur=0;

                for(p=t+1;p<len;p++)
                {
                    cur*=10;
                    cur+=str[p]-'0';
                }
                sum+=cur;
                cur=0;

                arr[y++]=sum;
            }
        }
    }
    // 排序输出
    for (i = 0; i < n - 1; i++)
    {
        int max = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[max] < arr[j])
            {
                max = j;
            }
        }
        if (max != i)
        {
            temp = arr[max];
            arr[max] = arr[i];
            arr[i] = temp;
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%lld ", arr[i]);
    }
    return 0;
}