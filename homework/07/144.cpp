#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cstring>
using namespace std;

int replaceStr(char A[], const char B[], const char C[])
{
    // 补充代码，完成此函数
    int lena = strlen(A);
    int lenb = strlen(B);
    int lenc = strlen(C);
    int flag = 0;
    for(int i=0;i<lena;i++)
    {
        //移动lena个字符
        A[lena-i]=A[lena-1-i];
    }
    //第一个字符为\n
    A[0]='\n';
    for (int i = 1; i <= lena; i++)
    {
        if (A[i] == B[0])
        {
            // 向后寻找
            for (int j = 1; j < lenb && i + j < lena; j++)
            {
                if (B[j] != A[i + j])
                break;
            }
            flag = 1;
        }
        // 此时的i是第一个相同元素的位置
        if (flag)
        {
            // 后面的元素往后移lenc个单位
            // 分三种情况
            if (lenc == lenb)
            {
                for (int t = 0; t < lenc; t++)
                {
                    A[i + t] = C[t];
                    return 1;
                }
            }
            if (lenc > lenb)
            {
                // 向后移动lenc-lenb个长度
                // 从后往前操作(lena-lenb-i)个数
                for (int t = 0; t <= lena - lenb - i; t++)
                {
                    A[(lenc - lenb) + lena -t] = A[lena -t];
                }
                //插入结束标志
                A[lena+(lenc-lenb)+1]='\0';
                //空白处插入C
                for(int p=0;p<lenc;p++)
                {
                    A[i+p]=C[p];
                }
                return 1;
            }
            if(lenc<lenb)
            {
                //往前移动lenb-lenc个长度
                //从前往后操作
                for(int t=0;t<=lena-lenb-i;t++)
                {
                    A[i+lenb+t-(lenb-lenc)]=A[i+lenb+t];
                }
                //bug：多输出了后面的多余元素
                A[lena-(lenb-lenc)+1]='\0';
                for(int p=0;p<lenc;p++)
                {
                    A[i+p]=C[p];
                }
                return 1;
            }
        }
    }
    for(int i=0;i<lenc;i++)
    {
        A[lena+i+1]=C[i];
    }
    A[lena+1+lenc]='\0';
    return 0;
}
//要怎么写换行：在字符串第一个元素加上\n

int main()
{
    char str1[110], str2[110], str3[110];
    int nRes;

    cin.getline(str1, 100);
    cin.getline(str2, 100);
    cin.getline(str3, 100);

    nRes = replaceStr(str1, str2, str3);
    printf("%d", nRes);
    printf("%s", str1);
    return 0;
}
