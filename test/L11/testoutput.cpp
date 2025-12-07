#include <stdio.h>
#include<string.h>
#include <iostream>
using namespace std;
void sort(const char *name[]);
void print(const char *name[]);
int main()
{
    // int arr[3][2]={1,2,3,4,5,6};
    // // int*p=arr;这样是错误的
    // int (*p)[2];
    // int *q;
    // for(p=arr;p<arr+3;p++)
    // {
    //     printf("%d\n",*(*p));
    // }
    // for(q=arr[0];q<arr[0]+6;q++)
    // {
    //     printf("%d\n",*q);
    // }
    // int aa[4] = {1, 3, 5, 7};
    // int (*p)[4]; // 定义指向包含4个元素的一维数组的指针变量
    // p = &aa; // 使p指向一维数组
    // // cout << p << " " << p + 1 << endl;
    // // cout << *p << endl;
    // // cout << (*p)[3] << endl; //*p 相当于 aa, 即输aa[3]
    // cout << sizeof(p) << " " << sizeof(aa)<< " " << sizeof(&aa) << endl;
    const char *name[] = {"Follow me", "BASIC", "Great Wall","FORTRAN", "Computer design"}; //指针数组
    // printf("%p\n",*name);
    // printf("%s\n",*name);
    printf("%c\n",**name);
    // sort(name);
    // print(name);
    return 0;
}
void sort(const char *name[])
{
    const char *temp;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<5-i-1;j++)
        {
            if(strcmp(name[j],name[j+1])>0)
            {
                temp=name[j];
                name[j]=name[j+1];
                name[j+1]=temp;
            }
        }
    }
}
void print(const char *name[])
{
    for(int i=0;i<5;i++)
    {
        printf("%s\n",name[i]);
    }
}