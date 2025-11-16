#include<stdio.h>
#define MAX 1001
struct student{
    char str[10];
    int a,b,c;
};
int main()
{
    int n;
    int i,j;
    scanf("%d",&n);
    student grades[MAX];
    int data[MAX];
    int max=0,sum=0;
    for(i=0;i<n;i++)
    {
        sum=0;
        scanf("%s",grades[i].str);
        scanf("%d %d %d",&grades[i].a,&grades[i].b,&grades[i].c);
        sum=grades[i].a+grades[i].b+grades[i].c;
        data[i]=sum;
    }
    max=0;
    for(i=1;i<n;i++)
    {
        if(data[i]>data[max])
        max=i;
    }
    printf("%s %d %d %d",grades[max].str,grades[max].a,grades[max].b,grades[max].c);
    return 0;
}