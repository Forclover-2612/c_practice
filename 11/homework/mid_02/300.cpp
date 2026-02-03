#include<stdio.h>

int main()
{
    int n;
    int i,j;
    scanf("%d",&n);
    char arr[50][3];
    int count[3]={n,n,n};
    for(i=0;i<50;i++)
    {
        scanf("%s",arr[i]);
        if(arr[i][0]=='1')
        {
            if(arr[i][1]=='A')
            {
                if(arr[i][2]=='B')
                count[0]--;
                else if(arr[i][2]=='C')
                {
                    count[0]--;
                    count[1]--;
                }
                else if(arr[i][2]=='D')
                {
                    count[0]--;
                    count[1]--;
                    count[2]--;
                }
            }
            else if(arr[i][1]=='B')
            {
                if(arr[i][2]=='C')
                {
                    count[1]--;
                }
                else if(arr[i][2]=='D')
                {
                    count[1]--;
                    count[2]--;
                }
            }
            else
            count[2]--;
        }
        else if(arr[i][0]=='2')
        {
            if(arr[i][1]=='A')
            {
                if(arr[i][2]=='B')
                count[0]++;
                else if(arr[i][2]=='C')
                {
                    count[0]++;
                    count[1]++;
                }
                else if(arr[i][2]=='D')
                {
                    count[0]++;
                    count[1]++;
                    count[2]++;
                }
            }
            else if(arr[i][1]=='B')
            {
                if(arr[i][2]=='C')
                {
                    count[1]++;
                }
                else if(arr[i][2]=='D')
                {
                    count[1]++;
                    count[2]++;
                }
            }
            else
            count[2]++;
        }
        else if(arr[i][0]=='0')
        break;
    }
    int min=101;
    for(i=0;i<3;i++)
    {
        if(count[i]<min)
        min=count[i];
    }
    printf("%d",min);
    return 0;
}