#include <iostream>
using namespace std;

int main()
{
    int i = 0;
    int n = 0;
    cin >> n;
    int arr[n + 1] = {0, 1};
    if (n <= 1)
        printf("第%d个数为1\n", n); // bug：多输出了一行
    // 错误原因：没有大括号（很严重）
    else
    {
        for (i = 2; i <= n; i++)
        {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
        printf("第%d个数为%d", n, arr[n]); // 还是要在函数中先计算后返回？
                                           // 注意参数：不能写成arr[i],越界了
    }
    return 0;
}