#include <stdio.h>
#include<stdlib.h>
struct Data
{
    int id;
    long long money;
    int num;
};
int cmp(const void*a,const void*b)
{
    const Data* x=(const Data*)a;
    const Data* y=(const Data*)b;
    if(x->money!=y->money)
    return x->money>y->money;//钱多在前
    if(x->num!=y->num)
    return x->num>y->num;
    return x->id<y->id;

}
int main()
{
    struct Data data[105];
    int n, count;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        data[i].id = i + 1;
        data[i].money = 0;
        data[i].num = 0;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &count);
        for (int j = 0; j < count; j++)
        {
            int person, mon;
            scanf("%d %d", &person, &mon);
            data[i].money -= mon;
            data[person-1].money += mon;
            data[person-1].num++;
        }
    }
    // 排序
    qsort(data,n,sizeof(data),cmp);
    // for (int i = 0; i < n; i++)
    // {
    //     int max = i;
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (data[j].money > data[max].money)
    //             max = j;
    //         else if (data[j].money == data[max].money)
    //         {
    //             if (data[j].num > data[max].num)
    //                 max = j;
    //             else if (data[j].num == data[max].num)
    //             {
    //                 if (data[j].id < data[max].id)
    //                     max = j;
    //             }
    //         }
    //     }
    //     if (max != i)
    //     {
    //         Data temp;
    //         temp = data[max];
    //         data[max] = data[i];
    //         data[i] = temp;
    //     }
    // }
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %lld\n", data[i].id, data[i].num, data[i].money);
    }
    return 0;
}