#include<stdio.h>

int main()
{
    // int n,floor,unit;
    int n;
    scanf("%d",&n);
    //十分割裂的写法
    // if(n%12==0)
    // {
    //     unit=n/12;
    // }
    // else
    // {
    //     unit=n/12+1;
    // }
    // if(n%12==0)
    // {
    //     floor=6;
    // }
    // else 
    // {
    //     if((n%12)%2==0)
    //     {
    //         floor=(n%12)/2;
    //     }
    //     else
    //     {
    //         floor=(n%12)/2+1;
    //     }
        
    // }
    // int num=n%12;
    // printf("%d-%d0",unit,floor);
    // if(num%2==0)
    // printf("2");
    // else 
    // printf("1");
    //技巧：先-1，将问题转化为从0开始的索引

    int idx=n-1;

    int unit=idx/12+1;

    int pos_in_unit=idx%12;

    int floor=pos_in_unit/2+1;

    int room=pos_in_unit%2+1;

    printf("%d-%d0%d",unit,floor,room);
    return 0;
}