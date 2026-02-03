#include <iostream>
using namespace std;

int main()
{
    int n, min, tmp;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int j = 0; j < n - 1; j++)
    {
        min = j; // 先存下标，不用比较第一个元素（先直接假设第一个元素是最小的）
        for (int t = j + 1; t < n; t++)
        {
            if (arr[min] > arr[t])
                min = t; // 先存下标，后面发现不相等时再做一次交换
            // 一个导致逻辑混乱的交换
            //  if(min!=j)
            //  {
            //      tmp=arr[j];
            //      arr[j]=arr[min];
            //      arr[min]=tmp;
            //  }
        }
        //内层循环只负责找最大，不负责交换
        if (min != j)
        {
            tmp = arr[j];
            arr[j] = arr[min];
            arr[min] = tmp;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
}