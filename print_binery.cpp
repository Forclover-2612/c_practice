#include<iostream>
using namespace std;

int count_ones_kernighan(int num)
{
    int count=0;
    unsigned int unum=(unsigned int)num;

    while(unum)
    {
        unum&=(unum-1);
        count++;
    }
    return count;
}
int main()
{
    int numbers[]={5,-5,7,-7,12,-1};
    int size=sizeof(numbers)/sizeof(numbers[0]);
    int i=0;
    for(i=0;i<size;i++)
    {
        int num=numbers[i];
        int ones=count_ones_kernighan(num);
        printf("%d %d\n",num,ones);
    }
    return 0;
}