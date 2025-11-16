#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_C 7//共有几个班级
#define MAX_S 40//每个班级最多允许的学生个数

int main()
{
    int n,m,x,i,j,cla;
    int sno[MAX_C][MAX_S],count[MAX_C]={0};
     int used[MAX_S]={0};
    scanf("%d %d %d",&n,&m,&x);
    for(i=0;i<n;i++)
    {
        scanf("%d",&cla);
        scanf("%d",&sno[cla][count[cla]]);//记录到班级对应的数组
        count[cla]++;//对每个班级学生进行计数（记录输入数据的个数）
    }
    srand(time(NULL));
    for(i=0;i<m;i++)
    {
        j=rand()%count[x];
        // printf("the lucky guy %d:%d\n",i,sno[x][j]); 
        if(used[i])//标记：不重复
        {
            m+=1;
            continue;
        }
        if(!used[i])
        {
            printf("the class and the number is %d %d\n",i+1,sno[x][j]);
            used[i]=1;
        }
    }
    return 0;
}