#include <stdio.h>
#include <stdlib.h>

int power(int x,int y)
{
    int sum=1;
    for(int i=0;i<y;i++)
    {
        sum*=x;
    }
    return sum;
}

int main()
{
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d", power(x, y));
    return 0;

}