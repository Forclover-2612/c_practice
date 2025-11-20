#include <stdio.h>
int take[5];
int like[5][5] = {
    {0, 0, 1, 1, 0},
    {1, 1, 0, 1, 1},
    {0, 1, 1, 0, 1},
    {1, 1, 0, 1, 0},
    {0, 1, 1, 0, 1}};
int book[5] = {0, 0, 0, 0, 0};
void assignBook(int i)
{
    int j, k;
    for (j = 0; j <= 4; j++)
    {
        if ((like[i][j] > 0) && (book[j] == 0))
        {
            // 把j号书分给i
            take[i] = j;
            book[j] = 1;
            if (i == 4)
            {
                for (k = 0; k <= 4; k++)
                {
                    printf("%d ", take[k]);
                }
                printf("\n");
            }
            else
                assignBook(i + 1);
            //尝试完一种可能立刻恢复
            take[i] = -1;
            book[j] = 0;
        }
    }
}
int main()
{
    assignBook(0);
    return 0;
}