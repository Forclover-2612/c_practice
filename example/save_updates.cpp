#include <stdio.h>
#include <math.h>

int min_(int arr[])
{
    int min = arr[0];
    for (int i = 1; i < 4; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}
int max_(int arr[])
{
    int max = arr[0];
    for (int i = 1; i < 4; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}
int main()
{
    int i, j, t, p,q,r;
    int arrx[4];
    int arry[4];
    int arrz[4];
    int point[1000][3]={0};
    for (i = 0; i < 4; i++)
    {
        scanf("%d %d %d", &arrx[i], &arry[i], &arrz[i]);
    }
    // 求坐标的最小值，最大值
    int minx = min_(arrx);
    int maxx = max_(arrx);
    int miny = min_(arry);
    int maxy = max_(arry);
    int minz = min_(arrz);
    int maxz = max_(arrz);
    int distance = 60000;
    int count=0;
    // 查找问题（如果遇到一个更小的值就加入数组，并清空前面的部分）
    for (i = minx; i <= maxx; i++)
    {
        for (j = miny; j <= maxy; j++)
        {
            for (t = minz; t <= maxz; t++)
            {
                int sum = 0;
                for (p = 0; p < 4; p++)
                {
                    sum += floor(sqrt((i - arrx[p]) * (i - arrx[p]) + (j - arry[p]) * (j - arry[p]) + (t - arrz[p]) * (t - arrz[p])));
                }
                if (sum < distance)
                {
                    distance = sum;
                    //清空数组并存入新的坐标
                    // point[1000][3]={0};这是初始化写法
                    // for(q=0;q<1000;q++)
                    // {
                    //     for(r=0;r<3;r++)
                    //     {
                    //         point[q][r]=0;
                    //     }
                    // }
                    count=0;
                    point[0][0]=i;
                    point[0][1]=j;
                    point[0][2]=t;
                    count++;
                }
                //count自增思路不对
                else if(sum==distance)//else和没有的区别是什么
                {
                    point[count][0]=i;
                    point[count][1]=j;
                    point[count][2]=t;
                    count++;
                }
            }
        }
    }
    printf("%d %d\n",distance,count);
    for(i=0;i<count;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",point[i][j]);
        }
        printf("\n");
    }
   return 0;
}