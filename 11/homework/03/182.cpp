#include<stdio.h>

int main()
{
    int n,count=0,m=0;
    char ch='A';
    char t;
    char a,b,c,d,e,f,g,h;
    scanf("%d",&n);
    //a='H'||'F'不能这么写
    for(;ch<='H';ch++)
    {
        count=0;
        // if(ch=='H'||'F')也不能这么写
        if(ch=='H'||ch=='F')
        count++; 
        if(ch=='B')
        count++;
         if(ch=='G')
        count++;
         if(ch!='B')
        count++;
        if(ch!='F'&&ch!='H')
        count++;
         if(ch!='F'&&ch!='H')
        count++;
         if(ch!='C')
        count++;
         if(ch=='H'||ch=='F')
        count++;
        if(count==n)
        {
            t=ch;
            m++;
        }
    }
    if(m==1)
    {
        printf("%c",t);
    }
    else
    printf("DONTKNOW");
    return 0;
}