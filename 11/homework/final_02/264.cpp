#include<stdio.h>
#include<string.h>
char text[100100][300];
int main()
{
    // freopen("error (4).in","r",stdin);
    int n;
    char str[15];
    char cmd[5];
    // char text[200][200];
    int row;
    scanf("%d",&n);
    getchar();
    fgets(str,sizeof(str),stdin);
    //fgets会读取换行符，并结束
    sscanf(str,"%s %d",cmd,&row);//不要再写&cmd
    for(int i=0;i<n;i++)
    {
        // scanf("%s",text[i]);
        fgets(text[i],300,stdin);
    }
    if(strcmp(cmd,"head")==0)
    {
        for(int i=0;i<row;i++)
        {
            printf("%s",text[i]);
        }
    }
    else{
        for(int i=0;i<row;i++)
        {
            printf("%s",text[n-row+i]);
        }
    }
    return 0;
}