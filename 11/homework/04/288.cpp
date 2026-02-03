#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    char arr1[102] = {};
    char arr2[102] = {};
    char ch;
    int i=0;
    int j=0;
    // string str1,str2;
    // scanf("%s", arr1);
    // scanf("%s", arr2);
    // cin>>arr1;
    // cin>>arr2;
    while((ch=getchar())!='\n')
    {
        arr1[i]=ch;
        i++;
    }
    while((ch=getchar())!='\n')
    {
        arr2[j]=ch;
        j++;
    }
    if (strlen(arr1) == strlen(arr2))
    {
        if (strcmp(arr1, arr2) == 0)
        {
            printf("0");
        }
        else
        {
            for (int t = 0; t < 100; t++)
            {
                if (arr1[t] != arr2[t])
                {
                    int n = arr1[t] - arr2[t];
                    printf("%d", n);
                    break;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < 100; i++)
            {
                if (arr1[i] != arr2[i])
                {
                    int n = arr1[i] - arr2[i];
                    printf("%d", n);
                    break;
                }
            }
    }
    return 0;
}