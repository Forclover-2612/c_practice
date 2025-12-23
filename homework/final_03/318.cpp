#include <stdio.h>
char horizonal[55][55];
char vertical[55][55];
char left_diag[55][55];
char right_diag[55][55];
// 不能用二级指针传！
void change0(char photo[][55], int n)
{
    // 水平
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        // char ch;
        for (int i = 0; i < n; i++)
        {
            // ch=photo[i][left];
            horizonal[i][left] = photo[i][right];
            horizonal[i][right] = photo[i][left];
        }
        left++;
        right--;
    }
}
void change1(char photo[][55], int n)
{
    // 垂直
    int upper = 0;
    int lower = n - 1;
    while (upper <= lower)
    {
        // char ch;
        for (int i = 0; i < n; i++)
        {
            // ch=photo[i][left];
            vertical[upper][i] = photo[lower][i];
            vertical[lower][i] = photo[upper][i];
        }
        upper++;
        lower--;
    }
}
void change2(char photo[][55], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            right_diag[i][j] = photo[n - 1 - j][n - 1 - i];
        }
    }
}
void change3(char photo[][55], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            left_diag[i][j] = photo[j][i];
        }
    }
}
char ans[4][55][55];
//统一四个变化
void generate_all(int n,char arr[][55])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            //水平翻转
            ans[0][i][j]=arr[i][n-1-j];
            //垂直翻转
            ans[1][i][j]=arr[n-1-j][i];
            //次对角线翻转
            ans[2][i][j]=arr[n-1-j][n-1-i];
            //主对角线翻转
            ans[3][i][j]=arr[i][j];
        }
        for(int j=0;j<n;j++)
        {
            ans[j][i][n]='\0';
        }
    }
    
}
int judge(char (*arr1)[55], char (*arr2)[55], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr1[i][j] != arr2[i][j])
                return 0;
        }
    }
    return 1;
}
void print(char (*arr)[55], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c", arr[i][j]);
            //或：字符串输出
            //printf("%s\n",ans[id][i]);
        }
        printf("\n");
    }
    printf("\n");
}
int main()
{
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    char photo[55][55];
    for (int i = 0; i < n; i++)
    {
        // for(int j=0;j<n;j++)
        // {
        // scanf("%c",&photo[i][j]);
        // 换行也会读进去！
        scanf("%s", photo[i]);
        // }
    }
    if (m == 0)
    {
        // 只做水平翻转和垂直翻转
        // 行与行之间的交换
        change0(photo, n);
        change1(photo, n);
        // 判断是否相同
        if (!judge(horizonal, vertical, n))
        {
            printf("2\n");
            print(horizonal, n);
            // printf("\n");
            print(vertical, n);
            // printf("\n");
        }
        else
        {
            printf("1\n");
            print(horizonal, n);
        }
    }
    else if (m == 1)
    {
        int sign[4] = {0};
        change0(photo, n);
        change1(photo, n);
        if (judge(horizonal, vertical, n))
        {
            sign[1] = 1;
        }
        change2(photo, n);
        if ((judge(horizonal, right_diag, n)))
        {
            sign[2] = 1;
        }
        if (judge(vertical, right_diag, n))
        {
            sign[2] = 1;
        }
        change3(photo, n);
        if ((judge(horizonal, left_diag, n)))
        {
            sign[3] = 1;
        }
        if (judge(vertical, left_diag, n))
        {
            sign[3] = 1;
        }
        if (judge(right_diag, left_diag, n))
        {
            sign[3] = 1;
        }
        int count = 0;
        for (int i = 0; i < 4; i++)
        {
            if (sign[i] == 0)
                count++;
        }
        printf("%d\n", count);
        print(horizonal, n);
        if (sign[1] == 0)
            print(vertical, n);
        if (sign[2] == 0)
            print(right_diag, n);
        if (sign[3] == 0)
            print(left_diag, n);
    }
    // for (int i = 0; i < limit; i++) {
    //     int duplicate = 0;
    //     // 与前面已经确认为有效的矩阵进行比较
    //     for (int j = 0; j < i; j++) {
    //         // 如果前面的矩阵 j 有效，且当前矩阵 i 与 j 相同，则 i 是重复的
    //         if (is_valid[j] && is_same(i, j, n)) {
    //             duplicate = 1;
    //             break;
    //         }
    //     }
    //     // 如果不重复，标记为有效并计数
    //     if (!duplicate) {
    //         is_valid[i] = 1;
    //         count++;
    //     }
    // }
    return 0;
}