#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int n = 0, num;
    int index = 0;
    int arr[100] = {};
    cin >> num;
    if (num == 0)
    {
        printf("0,1");
    }
    else
    {
        while (num != 0)
    {
        arr[index++] = num % 10;
        num = num / 10;
        n++;
    }
    for (int i = 0; i < index; i++)
    {
        printf("%d,", arr[i]);
    }
    printf("%d", n);
    }    
    return 0;
}