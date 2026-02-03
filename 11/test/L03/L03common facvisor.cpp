#include<stdio.h>
//最大公约数
int main()
{
    int x,y,n;
    scanf("%d %d",&x,&y);
    int min=(x<y)?x:y;
    while(min>=1)
    {
        if(x%min==0&&y%min==0)
        {
            printf("%d",min);
            break;
        }
        min--;
    }
    return 0;
}