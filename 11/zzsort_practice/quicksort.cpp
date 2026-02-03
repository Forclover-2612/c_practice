#include <stdio.h>
#include <string.h>
struct Data
{
    int diff;
    int rew;
    char name[25];
};
struct Data task[1002];

int cmp(Data a1, Data a2)
{
    //大于0说明要换序
    if (a1.diff != a2.diff)
    {
        if(a1.diff<a2.diff)
        return 1;
        else 
        return -1;
    }
    if (a1.rew != a2.rew)
    {
        if(a1.rew<a2.rew)
        return 1;
        else 
        return -1;
    }
    return strcmp(a1.name,a2.name);
    //<0说明s1字典序小于s2
    //>0说明s1字典序大于s2
}
int partition(int left, int right)
{
    Data x=task[left];
    
    while(left<right)
    {
        //注意是x
        while(cmp(x,task[right])<=0&&right>left)
        {
            right--;
        }
        task[left]=task[right];
        while(cmp(x,task[right])>=0&&left<right)
        {
            left++;
        }
        task[right]=task[left];
    }
    task[left]=x;
    return left;
}
void sort(int left, int right)
{
    if (left >= right)
        return;
    int k = partition(left, right);
    sort(left, k - 1);
    sort(k + 1, right);
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %s", &task[i].diff, &task[i].rew, task[i].name);
    }
    sort(0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d %d %s\n", task[i].diff, task[i].rew, task[i].name);
    }
    return 0;
}