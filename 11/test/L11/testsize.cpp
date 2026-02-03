#include<stdio.h>

int main()
{
    int* p;
    int arr[]={1,6,4,2,7};
    char *q,str[]="computer";
    int *p1,*p2;
    // printf("%lu\n",sizeof(* p));//这边等价于sizeof(int)
    // printf("%lu",sizeof(p));
    // p1=&arr[2];
    // p2=&arr[3];
    // printf("%d",*p1++);
    // printf("%d",*p1);
    // for(p=arr;p<arr+5;p++)
    // {
    //     printf("%d\n",*p);
    // }
    q=str;
    while(*q)
    {
        printf("%c",*q);
        q++;
    }
    return 0;
}