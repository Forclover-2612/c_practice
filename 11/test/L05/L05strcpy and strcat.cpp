#include<stdio.h>
#include<string.h>

int main()
{
    char s1[10]="abc";
    char s2[10]="def";
    // strcpy(s1,s2);
    strcat(s1,s2);
    // int m=strlen(s1);
    // int n=strlen(s2);
    // for(int j=0;j<m;j++)
    // {
    //     s1[j]='\0';
    // }
    // for(int i=0;i<n;i++)
    // {
    //     s1[i]= s2[i];
    // }
    printf("%s",s1);
    return 0;
}