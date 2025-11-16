#include<stdio.h>

unsigned long long fabonacci(unsigned int n)
{
    printf("调用：%u\n",n);
    if(n==0)
    return 0;
    else if(n==1)
    {
        return 1;
    }
    else{
        return fabonacci(n-1)+fabonacci(n-2);
    }
}

int main()
{
    unsigned int num;
    scanf("%u",&num);
    unsigned long long result=fabonacci(num);
    printf("%llu",result);
    return 0;
}