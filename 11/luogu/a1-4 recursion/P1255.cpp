#include <stdio.h>
#include <string.h>
// TLE：处理，高精度计算
//  unsigned long long stair(int n)
//  {
//      if(n==1)
//      return 1;
//      else if(n==2)
//      return 2;
//      else{
//          return stair(n-1)+stair(n-2);
//      }
//  }
//  int main()
//  {
//      int n;
//      scanf("%d",&n);
//      unsigned long long result=stair(n);
//      printf("%llu",result);
//      return 0;
//  }

int a[5000], b[5000], c[5000]; // 这是一个数字数组

int main()
{
    int n;
    int x = 1;
    scanf("%d", &n);
    // 观察到n<=2的时候，恰好等于自身
    if (n < 3)
    {
        printf("%d", n);
        return 0;
    }

    a[1] = 1, b[1] = 2;
    for (int i = 3; i <= n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            c[j] = a[j] + b[j];
        }
        for (int j = 1; j <= x; j++)
        {
            if (c[j] > 9)
            {
                c[j + 1] = c[j + 1] + c[j] / 10;
                c[j] = c[j] % 10;
                if (j + 1 > x)
                    x ++; // 更新长度
            }
        }
        for (int j = 1; j <= x; j++)
        {
            a[j] = b[j]; // 递推更新
        }
        for (int j = 1; j <= x; j++)
        {
            b[j] = c[j];
        }
    }
    // 逆序输出
    // 注意更新的时刻，b已经被更新为第n项
    for (int i = x; i > 0; i--)
    {
        printf("%d", b[i]);
    }
    return 0;
}