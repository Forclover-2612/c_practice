#include <iostream>
#include <stdio.h>
using namespace std;

// int devide_num(int num)
// {
//     int arr[5];
//     for(int i=0;i<4;i++)
//     {
//         arr[4]=num%10;
//         num=num/10;
//     }
//     return
// }
// 问题：如何返回一个数组

//bug：没有指定验证哪一轮:还要传递轮数吗/或者直接传递该轮的数字
// 判断正确位置上的数字
int correct_pos(int num, int arr[][4],int row) // 传递二维数组时，要指定第二维的大小
{
    int n,count=0;
    // 先拆数字num,储存到数组1中
    int arr1[5];
    int arr2[5];
    for (int i = 0; i < 4; i++)
    {
        arr1[4 - i] = num % 10;
        num = num / 10;
    }
    // 再拆输入的数字
    n=arr[row][1];
    for (int i = 0; i < 4; i++)
    {
        // n =arr[i][1];//取数错误
        arr2[4 - i] = n % 10;
        n = n / 10;
    }
    //对相同位置的数字进行计数
    for(int j=1;j<=4;j++)
    {
        if(arr1[j]==arr2[j])
        {
            count++;
        }
    }
    return count;
}

//判断猜对的数字个数
int correct_num(int num,int arr[][4],int row)
{
    int n,count=0,sum=0;
    int arr1[10];
    int arr2[10];
    int num1[5];
    int num2[5];
    //先拆分数字num，存在num1中
    for (int i = 0; i < 4; i++)
    {
        num1[4 - i] = num % 10;
        num = num / 10;
    }
    // 再拆输入的数字，存在num2中
    n=arr[row][1];
    for (int i = 0; i <4; i++)
    {
        num2[4 - i] = n % 10;
        n = n / 10;
    }
    //统计两个数字中0到9的个数，并存在数组中
    for(int j=0;j<=9;j++)
    {
        count=0;
        for(int t=1;t<=4;t++)
        {
            if(num1[t]==j)
            {
                count++;
            }
        }
        arr1[j]=count;
    }
    for(int j=0;j<=9;j++)
    {
        count=0;
        for(int t=1;t<=4;t++)
        {
            if(num2[t]==j)
            {
                count++;
            }
        }
        arr2[j]=count;
    }
    //对应位取最小值求和
    for(int p=0;p<=9;p++)
    {
        n=(arr1[p]<arr2[p])?arr1[p]:arr2[p];
        sum+=n;
    }
    return sum;
}

int main()
{
    int n, j, i;
    int flag=1;
    int arr[11][4]; // 11行(0行不用)每行储存一个输入的总数据
    int answer=0;//记录符合条件的结果
    int count=0;//记录满足条件的个数 
    int num;
    // char ch;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) // 下标1到n被使用
    {
        for (j = 1; j <= 3; j++)
        {
            scanf("%d", &arr[i][j]);
            getchar();
        }
    }
    for (num = 1000; num < 10000; num++)
    {
        flag=1;
        //比较猜对的数字和正确位置上的数字
        for(i=1;i<=n;i++)
        {
            if(correct_num(num,arr,i)!=arr[i][2])
            {
                flag=0;
                break;
            }
            if(correct_pos(num,arr,i)!=arr[i][3])
            {
                flag=0;
                break;
            }
        }
        //问题：一个num被标记为不符合时，后续num会继承
        if(flag)
        {
            answer=num;
            count++;
        }
    }
    if(count==1)
    {
        printf("%d",answer);
    }
    if(count!=1)
    {
        printf("Not sure");
    }
        return 0;
}