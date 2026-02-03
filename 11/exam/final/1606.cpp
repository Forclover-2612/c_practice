#include <stdio.h>
#include <stdlib.h>
int rule[4][4];
char ch;
int n, m;
const int MAX_SIZE=5000;
char matrix[MAX_SIZE][MAX_SIZE];
int Graphsize(int x)
{
    int res=1;
    for(int i=0;i<x;i++)
    {
        res*=m;
    }
    return res;
}
void initGraph()
{
    int size=Graphsize(n-1);

    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            matrix[i][j]=' ';
        }
        matrix[i][size]='\0';
    }
}
void drawGraph(int n,int row,int col)
{
    if(n==1)
    {
        matrix[row][col]=ch;
        return;
    }
    int step=Graphsize(n-2);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(rule[i][j]==1)
            {
                drawGraph(n-1,row+i*step,col+j*step);
            }
        }
    }
}
void print()
{
    int size=Graphsize(n-1);
    for(int i=0;i<size;i++)
    {
        printf("%s\n",matrix[i]);
    }
}
int main()
{
    scanf("%c %d", &ch, &n);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d",&rule[i][j]);
        }
    }
    initGraph();
    drawGraph(n,0,0);
    print();
    return 0;
}