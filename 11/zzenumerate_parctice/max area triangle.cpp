#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct Point{
    int x;
    int y;
};
int main()
{
    int n;
    scanf("%d",&n);
    struct Point point[101];
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&point[i].x,&point[i].y);
    }
    int max=0;
    for(int i=0;i<n-2;i++)
    {
        for(int j=i+1;j<n-1;j++)
        {
            for(int t=j+1;t<n;t++)
            {
                int sum=abs(point[i].x*(point[j].y-point[t].y)+point[j].x*(point[t].y-point[i].y)+point[t].x*(point[i].y-point[j].y));
                if(sum>max)
                max=sum;
            }
        }
    }
    printf("%d",max);
    return 0;
}