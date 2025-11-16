#include<stdio.h>
long long step;
void move(int n,char a,char b,char c)//两侧是起始和目标组织，中间是辅助柱子
{
    if(n==1)
    {
        printf("%d:%c to %c\n",n,a,c);
        return;
    }
    else
    {
        //先把前n-1个盘子移到b柱（辅助柱）
        move(n-1,a,c,b);
        //再把第n个盘子放到c
        // printf("%d:%c to %c\n",n,a,c);
        move(1,a,b,c);
        //最后把前n-1个盘子移动到c
        move(n-1,b,a,c);
        return;
    }
}
int move_count(int n)
{
    if(n==1)
    return 1;
    else{
        return move_count(n-1)+1+move_count(n-1);
    }
}
int main()
{
    char a='a';
    char b='b';
    char c='c';
    move(3,a,b,c);
    printf("%d",move_count(3));
    return 0;
}