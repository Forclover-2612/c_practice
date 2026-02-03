#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max_size 50

int main()
{
    int n, m, x, i, j;//n是实际使用量
    int cla[max_size];//最大容量
    int sno[max_size];
    int used[max_size]={0};
    scanf("%d %d", &n, &m);
    //按班级和号数输入学生信息
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &cla[i],&sno[i]);
    }
    srand(time(NULL));//初始化随机数生成器
    printf("The lucky guy:\n");
    for(i=0;i<m;i++)
    {
        j=rand()%n;//生成0到n-1的数
        if(used[j])//标记：不重复
        {
            m+=1;
            continue;
        }
        if(!used[j])
        {
            printf("the class and the number is %d %d\n",cla[j],sno[j]);
            used[j]=1;
        }
    }
    return 0;
}