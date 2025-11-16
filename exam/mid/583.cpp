#include<stdio.h>

int main()
{
    int i;
    char str[20];
    int arr[20];
    scanf("%s",str);
    for(i=0;i<15;i++)
    {
        arr[i]=(int)str[i]-48;
    }
    int sum;
    sum=arr[0]*7+arr[1]*9+arr[2]*10+arr[3]*5+arr[4]*8+arr[5]*4+1*2+9*1+arr[6]*6+arr[7]*3+arr[8]*7+arr[9]*9+arr[10]*10+arr[11]*5+arr[12]*8+arr[13]*4+arr[14]*2;
    int num=sum%11;
    for(i=0;i<6;i++)
    {
        printf("%d",arr[i]);
    }
    printf("19");
    for(i=6;i<15;i++)
    {
        printf("%d",arr[i]);
    }
    if(num==0)
    printf("1");
    else if(num==1)
    printf("0");
    else if(num==2)
    printf("X");
    else if(num==3)
    printf("9");
    else if(num==4)
    printf("8");
    else if(num==5)
    printf("7");
    else if(num==6)
    printf("6");
    else if(num==7)
    printf("5");
    else if(num==8)
    printf("4");
    else if(num==9)
    printf("3");
    else if(num==10)
    printf("2");
    return 0;
}