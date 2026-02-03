#include <stdio.h>

float maxScore(float ary[], int n)
{
    int maxScore = ary[0], i, k = 0;

    for (i = 1; i < n; i++)
    {
        if (ary[i] > maxScore)
        {
            maxScore = ary[i];
            k = i; // 最大元素的下标
        }
    }
    ary[k] = ary[0];
    //如果重复调用不用把值赋回去
    //但如何返回一个排好序的数组？
    return maxScore;
}

void my_sort(float *ary,int n)
{
    int max;
    int i,j;
    float temp;
    for(i=0;i<n-1;i++)
    {
        max=i;
        for(j=i+1;j<n;j++)
        {
            if(ary[j]>ary[i])
            max=j;
        }
        if(max!=i)
        {
            temp=ary[max];
            ary[max]=ary[i];
            ary[i]=temp;
        }
    }
}
int main()
{
    int i;
    int n;
    scanf("%d", &n);
    float score[n] = {0};
    for (i = 0; i < n; i++)
    {
        scanf("%f", &score[i]);
    }
    // my_sort(score,n);
    // for(i=0;i<n;i++)
    // {
    //     printf("%f\n",score[i]);
    // }
    for (i = 0; i < n; i++)
    {
        printf("%f\n", maxScore(score + i, n - i)); // 注意是n-i
    }
    // printf("%s",score);
    //不能这么输出浮点型数组，没有'\0'且浮点数与字符的ASCII值也不同
    return 0;
}