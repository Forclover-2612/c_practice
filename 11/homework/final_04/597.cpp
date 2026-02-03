#include <stdio.h>
#include <stdlib.h>

int matrix[11][11];
int dx[4] = {1, 0, 0, -1}; // 下左右上
int dy[4] = {0, 1, -1, 0};
int min_steps[11][11];//离起点的步数
int min = 100000;
int used[11][11];
int memo[11][11];
void route(int step, int x, int y, int n)
{
    if (x == n - 1 && y == n - 1)
    {
        if (step < min)
            min = step;
        return;
    }
    if (step >= min)
        return;
    if (matrix[x][y] == 0)
    {
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j <= matrix[x][y]; j++)
        {
            int nx = x + j * dx[i];
            int ny = y + j * dy[i];
            // if (nx >= 0 && ny >= 0 && nx < n && ny < n && used[nx][ny] == 0)
            //可以不用used：回头路一定会大于当前的值
            if (nx >= 0 && ny >= 0 && nx < n && ny < n)
            {
                // used[nx][ny] = 1;
                // route(step + 1, nx, ny, n);
                // used[nx][ny] = 0;
                if(step+1<min_steps[nx][ny])
                {
                    //一定要记忆！！
                    min_steps[nx][ny]=step+1;
                    route(step+1,nx,ny,n);
                }
            }
        }
    }
}
// 错误：上下左右走，memo出现了混乱
// 不能这样用记忆化
//  int route(int x, int y, int n)
//  {
//      if (x == n - 1 && y == n - 1)
//      {
//          return 0;
//      }
//      if (memo[x][y] != 0)
//      {
//          return memo[x][y];
//      }
//      if (matrix[x][y] == 0)
//      {
//          return memo[x][y]=100000;
//      }
//      int min=100000;
//      for (int i = 0; i < 4; i++)
//      {
//          for (int j = 1; j <= matrix[x][y]; j++)
//          {
//              int nx = x + j * dx[i];
//              int ny = y + j * dy[i];
//              if (nx >= 0 && ny >= 0 && nx < n && ny < n&&used[nx][ny]==0)
//              {
//                  used[nx][ny]=1;
//                  int sub=route(nx, ny, n);
//                  if(sub!=100000)
//                  {
//                      if(sub+1<min)
//                      {
//                          min=sub;
//                      }
//                  }
//                  used[nx][ny]=0;
//              }
//          }
//      }
//      if(min==100000)
//      {
//          return memo[x][y]=100000;
//      }
//      else
//      {
//          return memo[x][y]=min;
//      }
//  }
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            min_steps[i][j] = 100000;
        }
    }
    // used[0][0] = 1;
    min_steps[0][0]=0;
    route(0, 0, 0, n);
    printf("%d", min);
    // route(0,0,n);
    // printf("%d", memo[0][0]);
    return 0;
}