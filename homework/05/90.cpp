#include <stdio.h>
struct list
{
    int sno;//学号
    int p;//刷题数量
    int title[100];//刷题题号
    int num;//有效题目数量
};

int main()
{
    int n, m, k;
    int i, j, t, r,h;
    scanf("%d", &n);//n是要求题目的数量
    int request[100];
    int count = 0, max;
    int sum;//应输出的学生的数量
    int rank=1;//真正排名
    int plus=0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &request[i]);
    }
    scanf("%d %d", &m, &k);//m是学生数量，k是应该输出的数量
    sum=k;
    struct list arr[m];
    struct list temp;
    // 存入学生数据
    for (j = 0; j < m; j++)
    {
        scanf("%d %d", &arr[j].sno, &arr[j].p);
        for (t = 0; t < arr[j].p; t++)
        {
            scanf("%d", &arr[j].title[t]);
        }
    }
    // 计算学生的刷题数据
    for (j = 0; j < m; j++) // 访问结构体中的学生数据
    {
        count = 0;
        for (t = 0; t < arr[j].p; t++) // 依次访问学生的刷题题号
        {
            for (r = 0; r < n; r++) // 访问要求学生作答的题号，还是要写n比较保险
            {
                if (arr[j].title[t] == request[r])
                {
                    count++;
                    break;
                }
            }
        }
        // 将count存放在实际刷题数量num中
        arr[j].num = count;
    }
    //测试
    //输出学号和刷题数量
    // for(j=0;j<m;j++)
    // {
    //     printf("%d %d\n",arr[j].sno,arr[j].num);
    // }
    // 根据num进行排序
    for (j = 0; j < m; j++)
    {
        max = j;
        for (t = j + 1; t < m; t++)
        {
            if (arr[t].num > arr[max].num)
            {
                max=t;
            }
            else if(arr[t].num==arr[max].num)
            {
                if(arr[t].sno<arr[max].sno)
                max=t;
            }
        }
        if(max!=j)
        {
            temp=arr[max];
            arr[max]=arr[j];
            arr[j]=temp;
        }
    }
    //测试
    // for(j=0;j<m;j++)
    // {
    //     printf("test:%d %d\n",arr[j].sno,arr[j].num);
    //     if(j==k-1)
    //     printf("%d\n",k);
    // }
    //控制输出的数量
    //考察k之后的数据
    //出现问题
    int base=arr[k-1].num;//以第k名的分数为基准
    // for(j=k;j<m;j++)
    // {
    //     if(arr[j].num==base)
    //     sum++;
    //     else
    //     break;
    // }
    // for(j=0;j<sum;j++)
    // {
    //     printf("%d ",arr[j].sno);
    // }
    //题意理解错了（把并列的当成一个人算，如果最终实际人数小于k，全部输出）
    //向后寻找/向前比较
    j=1;
    rank=1;
    //确定多输出的人数
    while(j<m&&rank<=k)//数组不能越界
    {
        if(arr[j].num==arr[j-1].num)
        {
            plus++;//如果相等，多输出人数加一
        }
        else
        rank++;//如果不等，组数加一
        j++;
    }
    if(k+plus<=m)
    {
        for(j=0;j<k+plus;j++)
        {
            printf("%d ",arr[j].sno);
        }
    }
    else
    {
        for(j=0;j<m;j++)
        {
            printf("%d ",arr[j].sno);
        }
    }
    return 0;
}