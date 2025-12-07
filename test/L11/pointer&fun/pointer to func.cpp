#include<stdio.h>
typedef int(*calculate)(int,int);
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int min(int a, int b) {
    return (a < b) ? a : b;
}
int max(int a, int b) {
    return (a > b) ? a : b;
}
int fun(int x,int y,int(*p)(int,int))
{
    int res;
    res=p(x,y);
    return res;
}
int main()
{
    calculate a[]={add,sub,mul,min,max};
    int n;
    // int (*p)(int,int);
    // p=add;
    // int c=p(3,5);
    // printf("%d\n",c);
    // int res=fun(3,5,mul);
    // printf("%d\n",res);
    scanf("%d",&n);
    int c=(a[n])(3,5);
    printf("%d\n",c);
    return 0;
}