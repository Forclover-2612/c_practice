#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
// int flag=0;
//输入输出的细节
//先定义mid变量
int bisearch(int ary[], int left, int right, int num)
{
    // if(!flag)
    if (left > right)
    {
        printf("search %d from %d to %d\n",num,left,right);
        return -1;
    }
    else if (num == ary[(right + left) / 2])
    {
        printf("search %d from %d to %d\n",num,left,right);
        return (right + left) / 2;
    }
    else
    {
        printf("search %d from %d to %d\n", num, left, right);
        if (num > ary[(right + left) / 2])
        {
            // flag=1;
            // printf("search %d from %d to %d\n", num, (right + left) / 2 + 1, right);
            // return bisearch(ary, (right + left) / 2 + 1, right, num);
            left = (right + left) / 2 + 1;
        }
        else if (num < ary[(right + left) / 2])
        {
            // flag=1;
            // printf("search %d from %d to %d\n", num, left, (right + left) / 2 - 1);
            // return bisearch(ary, left, (right + left) / 2 - 1, num);
            right = (right + left) / 2 - 1;
        }
        return bisearch(ary, left, right, num);
    }
}

int main()
{
    int n, array[10000], i, num;
    scanf("%d", &n);
    scanf("%d", &num);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("%d", bisearch(array, 0, n - 1, num));
    cout << endl;
    return 0;
}
