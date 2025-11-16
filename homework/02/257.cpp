#include<stdio.h>

int main()
{
    double Sn;
    int k,n;
    scanf("%d",&k);
    for(n=1;;n++)
    {
        Sn=Sn+1.0/n;
        if(Sn>k)
        {
            printf("%d",n);
            break;//记得及时跳出循环
        }
    }
    return 0;
}