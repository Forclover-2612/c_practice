#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int a,b;
    float c,d;
    char e,f;
    scanf("%d,%d",&a,&b);
    scanf("%f %f",&c,&d);
    scanf(" %c, %c",&e,&f);
    printf("%d,%d\n",a,b);
    printf("%.1f %.1f\n",c,d);
    printf(" %c, %c\n",e,f);
    return 0;
}