#include <stdio.h>
// 思路1，利用结构体，遍历数组考虑是否出现（向前逐个查找）
//如果没找到，成为数组中的新元素，count=1
//如果找到，count++
struct Data
{
    int count;
    int num;
};
int findInArr(int num, int k, struct Data arr[]) // 向前寻找的个数
{
    for (int i = 0; i < k; i++)
    {
        if (num == arr[i].num)
            return i; // 返回下标（巧妙的写法）
    }
    return -1; // return 0不好，也有可能是下标
}
int main()
{
    int n;
    int i, j;
    scanf("%d", &n);
    int num;
    struct Data arr[1000];
    struct Data temp;
    int k = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &num);                // 边输入变判断边储存
        if (findInArr(num, k, arr) == -1) // 如果没找到，count=1,并且储存这个数(向前寻找的个数增加)
        {
            arr[k].num = num; // 注意保存的下标k,代表储存的个数
            arr[k].count = 1;
            k++;
        }
        else
            arr[findInArr(num, k, arr)].count++;
    }
    // 排序()
    for (i = 0; i < k - 1; i++)
    {
        int min = i;
        for (j = i + 1; j < k; j++)
        {
            if (arr[min].num > arr[j].num)
                min = j;
        }
        if (min != i)
        {
            temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
    int flag=0;
    // 有bug
    for (i = 0; i < k; i++)
    {
        if (arr[i].count > 1)
        {
            printf("%d:%d\n", arr[i].num, arr[i].count);
            flag=1;
        }
    }
    if(!flag)
    {
        printf("NO");
    }
    return 0;
}