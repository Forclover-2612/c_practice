#include<stdio.h>
#include<string.h>
int compareTo(char g1[],char g2[],char p[])
{
    int n=strlen(g1);
    for(int i=0;i<n;i++)
    {
        if(g1[i]==g2[i])
        continue;
        for(int j=0;j<4;j++)
        {
            if(p[j]==g1[i])
            return 1;
            else if(p[j]==g2[i])
            return -1;
        }
    }
    return 0;
}
int main()
{
    int n;
    int i,j;
    scanf("%d",&n);
    // getchar();
    char p[5];//预留更大的位置
    scanf("%s",p);
    char arr[1000][22];
    char temp[20];
    for(i=0;i<n;i++)
    {
        scanf("%s",arr[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            int t=compareTo(arr[j],arr[j+1],p);
            if(t==-1)
            {
                strcpy(temp,arr[j]);
                strcpy(arr[j],arr[j+1]);
                strcpy(arr[j+1],temp);
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%s\n",arr[i]);
    }
    return 0;
}