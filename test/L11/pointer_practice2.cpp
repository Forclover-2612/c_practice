#include<stdio.h>

int main()
{
    int a[3][4];
    printf("%p %p %p %p",a+2,a[2],(a+2)+1,a[2]+1);
    return 0;
}