#include <stdio.h>
struct Data
{
    int no;
    double OLD;
    double NEW;
};
int main()
{
    int n;
    int i, j;
    int count=0;
    scanf("%d", &n);
    struct Data arr[10000];
    for (i = 0; i < n; i++)
    {
        scanf("%d %lf %lf", &arr[i].no, &arr[i].OLD, &arr[i].NEW);
        if (arr[i].OLD <= arr[i].NEW)
        {
            printf("%d %.2lf\n", arr[i].no, arr[i].NEW - arr[i].OLD);
            count++;
        }
    }
    double m=(double)count/n;
    printf("%.2lf%%",m*100);
    return 0;
}