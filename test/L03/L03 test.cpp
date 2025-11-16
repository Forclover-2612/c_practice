#include<stdio.h>

int main()
{
    float value;
    for(value=36;value>0;value/=21)
    {
        printf("%10lf\n",value);
    }
    return 0;
}