#include<stdio.h>
long long step;
void hanoi(int n,char a,char b,char c)
{
    if(n==1)
    {
        step++;
        printf("[step %d] move plate 1# from %c to %c\n",step,a,c);
        return;
    }
    else
    {
        hanoi(n-1,a,c,b);
        step++;
        printf("[step %d] move plate %d# from %c to %c\n",step,n,a,c);
        hanoi(n-1,b,a,c);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    hanoi(n,'a','b','c');
    printf("%lld",step);
    return 0;
}
