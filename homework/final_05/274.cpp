#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 40
#define M 300000


char allRes[M][N] = {0};    //保存所有结果
char szRes[N] = {0};        // 全局变量，保存n对括号组成的一个序列
//指针操作
//如何知道答案的数量
void genParentheses(int x,int y,int n,int *nRes,int count)//左括号和右括号的个数,当前括号数量
{
    if(x==n&&y==n)
    {
        for(int i=0;i<2*n;i++)
        {
            allRes[*nRes][i]=szRes[i];
        }
        (*nRes)++;
        return;
    }
    if(x<y||x>n||y>n)
    return;
    //两种操作方法
    szRes[count]='(';
    genParentheses(x+1,y,n,nRes,count+1);
    szRes[count]=')';
    genParentheses(x,y+1,n,nRes,count+1);
}
//更标准的写法
void genParentheses(int x, int y, int n, int *nRes, int count) 
{
    // 1. 基准情况：括号正好填满
    if (x == n && y == n) {
        szRes[count] = '\0'; // 记得给字符串加结束符，printf才能正常打印
        strcpy(allRes[*nRes], szRes); // 使用strcpy更简洁
        (*nRes)++; // 必须加括号！
        return;
    }

    // 2. 尝试放左括号
    // 只要左括号还没用完，就可以放
    if (x < n) {
        szRes[count] = '(';
        genParentheses(x + 1, y, n, nRes, count + 1);
    }

    // 3. 尝试放右括号
    // 只有当前右括号数量比左括号少时，才能放右括号（保证合法性）
    if (y < x) {
        szRes[count] = ')';
        genParentheses(x, y + 1, n, nRes, count + 1);
    }
}

int main()
{
    int n, nRes = 0, i;
    
    scanf("%d", &n);
    genParentheses(0,0,n,&nRes,0);

    printf("%d\n", nRes);
    for(i = 0; i < nRes; i ++)
        printf("%s\n", allRes[i]);

    return 0;
}