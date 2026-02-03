#include <stdio.h>
#define ROW 8
#define COL 8
int attack[ROW][COL]; // 标记可以放置的位置
int conflict(int arrack[ROW][COL])
{

}
void put_queen(int attack[ROW][COL], char arr[ROW][COL], int x, int y)
{
    int i, j;
    int flag=0;
    for (i = 0; i < ROW; i++)
    {
        attack[i][y] = 1;
    }
    
    if (x > 7)
    {
        for (i = 0; i < 8; i++)
        {
            for (j = 0; j < 8; j++)
            {
                printf("%c", arr[i][j]);
            }
            printf("*");
        }
        return;
    }
    else
    {
        for(i=0;i<8;i++)
        {
            attack[x][i]=1;
            for(j=0;j<8;j++)
            {
                if(attack[i+1][j]==0)
                {
                    attack[i+1][j]=1;
                    flag=1;
                    put_queen(attack,arr,x+1,j);
                }
            }
            if(!flag)
            {
                attack[x][i]=0;
                return put_queen(attack,arr,x-1,y);
            }
        }
    }
}
int main()
{
    int i, j;
    // 实际的棋盘
    char arr[ROW][COL];
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            arr[i][j] = '*';
        }
    }
    put_queen(attack,arr,0,0);
    return 0;
}