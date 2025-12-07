#include<stdio.h>
void swap(int *p1,int *p2)//p1,p2是main中p1,p2的副本指针
{
    int *temp;
    temp=p1;
    p1=p2;
    p2=temp;
    //交换的是副本指针的指向，和原指针无关
}
//交换值的写法
void pptswap(int *p1,int *p2)
{
    //实际拿到了指针中的内容，可行
    //实参的内容得到了交换
    int temp;
    temp=*p1;
    *p1=*p2;
    *p2=temp;
}
//交换指向的写法
void swap_right(int **p1,int **p2)
{
    int *temp;
    temp=*p1;//这样就能拿到原指针了
    *p1=*p2;
    *p2=temp;
}
int main()
{
    int a=5,b=9;
    int *p1,*p2;
    p1=&a;
    p2=&b;
    swap(p1,p2);
    pptswap(p1,p2);
    swap_right(&p1,&p2);
    printf("%d %d",*p1,*p2);
    //代码有什么错误：我想改变指向
    return 0;
}