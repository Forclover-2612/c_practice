#include<iostream>
#define N 5
using namespace std;

int main()
{
    double sheep[10]={};
    double max=0.0;
    int i=0;
    int maxNO=0;
    for(i=0;i<N;i++)
    {
        cout<<"please input the weight of sheep["<<i<<"]=";
        cin>>sheep[i];
        if(max<sheep[i])
        {
            max=sheep[i];
            maxNO=i;
        }
    }
        cout<<"The heaviest sheep weights is"<<max<<"kg";
    return 0;
}