#include<stdio.h>

unsigned long long factorial(unsigned int n);

int main()
{
    unsigned int num;
    scanf("%u",&num);

    unsigned long long result=factorial(num);
    printf("%llu",result);
    return 0;
}

unsigned long long factorial(unsigned int n)
{
    if(n==0)
    {
        return 1;
    }
    else{
        return n*factorial(n-1);
    }
}
