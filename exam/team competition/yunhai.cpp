#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int height[100001];
int flag[100001];
int main()
{
    int n;
    scanf("%d",&n);
    int min=1000001;
    int max=-1;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&height[i]);
        if(height[i]<min)
        {
            min=height[i];
        }
        if(height[i]>max)
        {
            max=height[i];
        }
    }
    int res=-1;
    for(int i=min;i<=max;i++)
    {
        int count=0;
        for(int j=0;j<n;j++)
        {
            if(height[j]>i)
            flag[j]=1;
            else
            {
                flag[j]=0;
            }
        }
        for(int j=0;j<n;j++)
        {
            int k=0;
            if(flag[j]!=0)
            {
                count++;
                while(flag[j+k+1]!=0&&j+k<n)
                {
                    k++;
                }
            }
            j+=k;
        }
        if(count>res)
        {
            res=count;
        }        
    }
    printf("%d\n",res);
    return 0;
}