#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Data
{
    long long num;
    int count;
    long long end;
};
int isPalindromeStr(char str[])
{
    int left = 0;
    int right = strlen(str) - 1;
    while (left <= right)
    {
        if (str[left] != str[right])
            return 0;
        left++;
        right--;
    }
    return 1;
}
void reverse(char str[])
{
    int left = 0;
    int n = strlen(str);
    int right = n - 1;
    char temp;
    while (str[right] == '0' && right >= 0)
    {
        str[right] = '\0';
        right--;
    }
    while (left <= right)
    {
        temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}
int calculate(char str[])
{
    int i;
    int count = 0;
    char str1[20]; // 存现在的数组
    char str2[20]; // 进行颠倒
    char *end;
    long long num1;
    long long num2;
    while (!isPalindromeStr(str))
    {
        // 注意长度的更新！
        int n = strlen(str);
        for (i = 0; i <= n; i++)
        {
            str1[i] = str[i];
            str2[i] = str[i];
        }
        reverse(str2);
        // long long num1=strtoll(str1,&end,10);
        // long long num2=strtoll(str2,&end,10);
        sscanf(str1, "%lld", &num1);
        sscanf(str2, "%lld", &num2);
        long long num3 = num1 + num2;
        sprintf(str, "%lld", num3);
        count++;
    }
    return count;
}
int main()
{
    // freopen("error (3).in", "r", stdin);
    int i, j;
    struct Data arr[10];
    struct Data temp;
    char str[20];
    for (i = 0; i < 10; i++)
    {
        scanf("%lld", &arr[i].num);
        sprintf(str, "%lld", arr[i].num);
        arr[i].count = calculate(str);
        sscanf(str, "%lld", &arr[i].end);
    }
    int max;
    for (i = 0; i < 10; i++)
    {
        max = i;
        for (j = i + 1; j < 10; j++)
        {
            if (arr[j].count > arr[max].count)
                max = j;
            else if (arr[j].count == arr[max].count && arr[j].end < arr[max].end)
                max = j;
            else if (arr[j].count == arr[max].count && arr[j].end == arr[max].end && arr[j].num < arr[max].num)
            max=j;
        }
        if (max != i)
        {
            temp = arr[i];
            arr[i] = arr[max];
            arr[max] = temp;
        }
    }
    for (i = 0; i < 10; i++)
    {
        printf("%lld %d %lld\n", arr[i].num, arr[i].count, arr[i].end);
    }
    return 0;
}