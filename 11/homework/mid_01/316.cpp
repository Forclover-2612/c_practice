#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int count=(n-1)%7;
    switch(count)
    {
        case 0:
        printf("SUN");
        break;
        case 1:
        printf("MON");
        break;
        case 2:
        printf("TUE");
        break;
        case 3:
        printf("WED");
        break;
        case 4:
        printf("THU");
        break;
        case 5:
        printf("FRI");
        break;
        case 6:
        printf("SAT");
        break;
    }
    return 0;
}