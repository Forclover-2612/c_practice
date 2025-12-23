#include<stdio.h>
char map[100][100];

void initGraph(int n)
{
    int size=1;
    for(int i=0;i<n;i++)
    {
        size*=3;
    }
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            map[i][j]=' ';
        }
        map[i][size]='\0';
    }
}
void draw(int row,int col,int n)
{
    if(n==0)
    {
        map[row][col]='#';
        return;
    }
    int step=1;
    for(int i=0;i<n-1;i++)
    {
        step*=3;
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i==1&&j==1)
            continue;
            else{
                draw(row+step*i,col+step*j,n-1);
            }
        }
    }
}
void print(int n)
{
    int size=1;
    for(int i=0;i<n;i++)
    {
        size*=3;
    }
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            printf("%c",map[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    initGraph(n);
    draw(0,0,n);
    print(n);
    return 0;
}