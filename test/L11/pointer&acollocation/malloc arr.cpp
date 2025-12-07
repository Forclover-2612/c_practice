#include<stdio.h>
#include<stdlib.h>
int main()
{
    //如何动态分配一个二维数组[3][4]
    //二级指针（碎片化内存）其实是先定义一个指针数组
    //先申请“存放行指针”的数组
    int **matrix=(int **)malloc(3*sizeof(int*));
    //给每一行申请空间
    for(int i=0;i<3;i++)
    {
        matrix[i]=(int*)malloc(4*sizeof(int));
    }
    //访问：像正常数组一样访问
    matrix[1][2]=100;
    //释放:像释放里面的（每一行），再释放外面的（行指针数组）
    for(int i=0;i<3;i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    //优点：每一行长度可以不一样
    //第二种：申请一块连续内存，用公式进行访问
    int *arr=(int*)malloc(3*4*sizeof(int));
    //使用：手动算下标
    int val=arr[1*4+2];//访问arr[1][2];
    //释放：只需要一次
    free(arr);
}