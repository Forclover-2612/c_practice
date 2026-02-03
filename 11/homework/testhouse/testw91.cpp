#include<stdio.h>

int main()
{
    char arr1[10]="0123456";
    char arr2[10];
    arr2[2]=arr1[0]-1;
    //这种数输出方法对于-1后不在数字范围的要讨论
    printf("%c",arr2[2]);
    return 0;
}