#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int grade;
    cin>>grade;
    if(grade>=90)
    printf("4.0");
    else if(grade<90&&grade>85)
    printf("3.7");
    else if(grade<=85&&grade>=83)
    printf("3.3");
    else if(grade<83&&grade>=80)
    printf("3.0");
    else if(grade<80&&grade>75)
    printf("2.7");
    else if(grade<=75&&grade>=73)
    printf("2.3");
    else if(grade<=72&&grade>=70)
    printf("2.0");
    else if(grade<70&&grade>65)
    printf("1.7");
    else if(grade<=65&&grade>=63)
    printf("1.3");
    else
    printf("1.0");
    return 0;
}