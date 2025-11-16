#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
    int n,a,b,c,found=0;//a:手雷，b：冲锋枪 c:大杀器
    scanf("%d",&n);
    for(a=2;a<=(n/2);a+=2)//条件4
    {
        for(b=1;b<=(n/6);b++)
        {
            for(c=8;c<=n;c+=10)//条件5
            {
                if((a>c&&a<b&&b>c)||(a>b&&a<c&&c>b))//条件3,(2),注意细节相不相等
                {
                    if((b>=10)||(b>=1&&b<=9&&a>=10))//条件6
                    {
                        int cost=2*a+6*b+c;
                        if(cost>0.9*n&&cost<=n)//条件7（以上：无等于号）
                        {
                            printf("%d %d %d\n",a,b,c);
                            found=1;
                        }
                    }
                }
            }
        }
    }
    if(!found)
    {
        printf("no answer\n");
    }
    return 0;
}