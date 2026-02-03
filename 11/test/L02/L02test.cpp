#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    // int a=256;
    // printf("%c",a);
    // cout<<sizeof('abcdef');
    // int a=3;
//    printf("换行：\12或\xA");
    int x=10;
    float y=3.14f;
    double z=2.718;
    printf("%zu\n",sizeof(x+y));
    printf("%zu\n",sizeof(z+y));
    printf("%zu\n",sizeof(x+z));//结果是double型
    return 0;
}