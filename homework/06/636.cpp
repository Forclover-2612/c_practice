#include<stdio.h>

int grades(int points[][7],int i)
{
    int flag=1;
    //每次对points[i][7]进行处理(1到6)
    if(points[i][1]==6)
    {
        return 512;
    }
    else if(points[i][2]==6)
    {
        return 256;
    }
    else if(points[i][2]==5)
    {
        return 64;
    }
    else if(points[i][2]==4)
    {
        return 4;
    }
    else if(points[i][4]==1)
    {
        for(int j=1;j<=5;j++)
        {
            if(points[i][j]!=1)
            {
                flag=0;
                break;
            }
        }
        if(flag)
        return 16;
        else 
        return 1;
    }
    else if(points[i][4]==2)
    {
        return 2;
    }
    else if(points[i][4]==3)
    {
        return 8;
    }
    else if(points[i][4]==4)
    {
        if(points[i][1]==2)
        {
            return 2048;
        }
        else
        return 32;
    }
    else if(points[i][4]==5)
    {
        return 128;
    }
    else if(points[i][4]==6)
    {
        return 1024;
    }
    else
    return 0;
}
int main()
{
    int n;//至多进行的次数
    scanf("%d",&n);
    int i,j,t;
    int arr[n][6];
    int count;
    int points[n][7];
    int sum=0;//记得初始化
    // //注意是至多
    // for(i=0;i<n;i++)
    // {
    //     for(j=0;j<6;j++)
    //     {
    //         scanf("%d",&arr[i][j]);
    //     }

    // }
    // int round=0;
    // while(round <n)
    // {
    //     int count=0;
    //     int num;
    //     while(count<6&&scanf("%d",&num)==1)
    //     {
    //         arr[round][count]=num;
    //         count++;
    //     }
    //     round++;
    // }
    //统计4的数量
    //还是统计123456的数量？
    //先对points数组进行初始化
    for(i=0;i<n;i++)
    {
        for(j=1;j<=6;j++)
        points[i][j]=0;
    }
    //一边储存一边判断
    for(i=0;i<n;i++)//第几行
    {
        for(j=0;j<6;j++)//遍历元素
        {
            scanf("%d",&arr[i][j]);
            for(t=1;t<=6;t++)//判断个点数的个数
            {
                if(arr[i][j]==t)
                {
                    points[i][t]++;
                }
                // printf("%d\n",points[i][t]);                
            }
        }
        //判断积分
        if(grades(points,i)==0)
        break;
        sum+=grades(points,i);
    }
    //测试
    // for(i=0;i<n;i++)
    // {
    //     for(j=1;j<=6;j++)
    //     {
    //         printf("%d",points[i][j]);
    //     }
    // }
    printf("%x",sum);
    return 0;
}