#include<iostream>
using namespace std;

int main()
{
    int d1,d2;
    char weekday[7][10]={"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday","Sunday"};
    cin>>d1>>d2;
    if((d1+2)<=7)
    {
        printf("%s\n",weekday[d1]);
    }
    if((d1+2)>7)
    {
        printf("Monday\n");
    }
    if((d2-1)>0)
    {
        printf("%s",weekday[d2-2]);
    }
    if((d2-1)==0)
    {
        printf("Sunday");
    }
    return 0;
}