#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main()
{
    // int a,b;
    // printf("%d %d",a,b);
    // int arr[] = {};
    // printf("%d", arr[0]); // 乱码
    int n=4;

    int a[5]={2,4,6}; // 声明项
    cout << a[0] << endl;
    cout << a[1] << endl;
    cout << a[2] << endl;
    cout << a[3] << endl;
    cout<<a[4]<<endl;
    // char name[3]={'W','a'};//如果中括号中的数值<=2或没有，没有‘\0’，会出错
    // cout<<name<<endl;
    // printf("%zu",strlen(name));//如果中括号的数字>2,最后默认\0，正确输出
    // int arr[][4]={1,2,4};
    // for(int i=0;i<2;i++)
    // {
    //     for(int j=0;j<4;j++)
    //     {
    //         printf("%d\n",arr[i][j]);
    //     }
    // }
    return 0;
}