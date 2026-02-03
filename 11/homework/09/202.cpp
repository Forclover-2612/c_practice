#include <stdio.h>
int book[11];
int arr[11][11];
int answer[5000][11];
int total;
int res[11];
void assign(int i, int n)
{
    // int res[11];
    // 不能是局部变量
    if (i == n)
    {
        for (int j = 0; j < n; j++)
        {
            answer[total][j] = res[j];
        }
        total++;
        // for(int j=0;j<n;j++)
        // {
        //     printf("B%d",res[j]);
        // }
        // printf("\n");
        return;
    }
    for (int j = 0; j < n; j++)
    {
        if (book[j] == 0 && arr[i][j] == 1)
        {
            book[j] = 1;
            res[i] = j;
            assign(i + 1, n);
            book[j] = 0;
        }
    }
}
int main()
{
    int i, j;
    int n;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            // arr[i][j]=getchar()-'0';//输入的隐患？认为是一个数字
            scanf("%1d", &arr[i][j]);
        }
        // getchar();
    }
    // printf("%d\n",total);
    // 注意，要先储存
    assign(0, n);
    if (total != 0)
    {
        printf("%d\n", total);
        for (i = 0; i < total; i++)
        {
            for (j = 0; j < n; j++)
            {
                printf("B%d", answer[i][j] + 1);
            }
            printf("\n");
        }
    }
    else{
        printf("NO\n");
    }
    return 0;
}