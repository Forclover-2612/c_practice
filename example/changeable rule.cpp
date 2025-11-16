#include<stdio.h>

int cmp(int arr1[],int arr2[],int size);
int main()
{
    int i,j;
    int n;
    int sum=0;
    scanf("%d",&n);
    const int size=6;
    const int n_pattern=12;
    //可以灵活改变规则
    int arr[size];
    int pattern[][size]={
       {4,4,4,4,1,1},{4,4,4,4,4,4},{1,1,1,1,1,1},{2,2,2,2,2,2},
        {4,4,4,4,4,0},{2,2,2,2,2,0},{4,4,4,4,0,0},{1,2,3,4,5,6},
        {4,4,4,0,0,0},{2,2,2,2,0,0},{4,4,0,0,0,0},{4,0,0,0,0,0}
    };
    int award[n_pattern] = {2048, 1024, 512,256, 128, 64, 32, 16, 8, 4, 2, 1};
    for(i=0;i<n;i++) //至少循环的次数
    {
        for(j=0;j<size;j++)
        {
            scanf("%d",&arr[j]);
        }
        for(j=0;j<n_pattern;j++)
        {
            if(cmp(pattern[j],arr,size)==0)
            {
                sum+=award[j];
                break;
            }
        }
        //根据循环次数的判断
        if(j==n_pattern)
        break;
    }
    printf("%x",sum);
    return 0;
}
//数组1是规则中的点数，数组2是实际的点数
int cmp(int arr1[],int arr2[],int size)
{
    int i,j;
    int arr[size];
    //避免对原数组进行改变，先复制一份
    for(i=0;i<size;i++)
    {
        arr[i]=arr2[i];
    }
    for(i=0;i<size;i++)
    {
        //处理：如果规则是0的数，跳过，将一个数字一次比较规则内的所有数，比较过的数=-1
        //比较，是以实际数组为基准在规则进行查数还是以规则为基准在实际数组内查数（后者更好）
        //只要规则内有一个没有查到就跳出
        if(arr1[i]==0)
        continue;
        for(j=0;j<size;j++)
        {
            if(arr1[i]==arr[j])
            {
                arr[j]=-1;
                break;
            }
        }
        //如果循环次数，说明没查到，直接return
        if(j==size)
        return -1;
    }
    return 0;
}