#include <stdio.h>
#include <stdbool.h>

int main()
{
    int a, b, c, d, i, t, m, n, found = 0;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int arr[] = {120, 40, 85, 50, 100, 140, 70, 100};
    bool used[9] = {false};
    // 可以再多一个数组记录占用情况，循环嵌套结尾变为0
    //  for (i = 0; i < 8; i++)
    //  {
    //      if (a <= arr[i])
    //      {
    //          for (t = 0; t < 8; t++)
    //          {
    //              if (b <= arr[t] && t != i)
    //              {
    //                  for (m = 0; m < 8; m++)
    //                  {
    //                      if (c <= arr[m] && m != i && m != t)
    //                      {
    //                          for (n = 0; n < 8; n++)
    //                          {
    //                              if (d <= arr[n] && n != i && n != t && n != m)
    //                              {
    //                                  printf("%d %d %d %d\n", i + 1, t + 1, m + 1, n + 1);
    //                                  found = 1;
    //                              }
    //                          }
    //                      }
    //                  }
    //              }
    //          }
    //      }
    //  }
    for (i = 0; i < 8; i++)
    {
        if (a <= arr[i])
        {
            used[i] = true;
            for (t = 0; t < 8; t++)
            {
                if (used[t])
                    continue;
                if (b <= arr[t])
                {
                    used[t] = true;
                    for (m = 0; m < 8; m++)
                    {
                        if (used[m])
                            continue;
                        if (c <= arr[m])
                        {
                            used[m] = true;
                            for (n = 0; n < 8; n++)
                            {
                                if (used[n])
                                    continue;
                                if (d <= arr[n])
                                {
                                    printf("%d %d %d %d\n", i + 1, t + 1, m + 1, n + 1);
                                    found = 1;
                                }
                                used[n]=false;
                            }
                        }
                        used[m]=false;
                    }
                }
                used[t]=false;
            }
        }
        used[i] = false;
    }
    if (!found)
    {
        printf("-1");
    }
    return 0;
}