#include<stdio.h>
#include<string.h>

int main()
{
    char str[100]="abcdefghi";
    strrev(str);
    printf("%s\n",str);
    int left,right;
    char temp;
    left=0;
    right=strlen(str)-1;
    while(left<=right)
    {
        temp=str[left];
        str[left]=str[right];
        str[right]=temp;
        left++;
        right--;
    }
    printf("%s",str);
    return 0;
}