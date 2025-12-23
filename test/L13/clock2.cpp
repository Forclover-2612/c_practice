#include<iostream>
using namespace std;

class Clock{
    int hour;
    public:
    //默认构造函数
    Clock()
    {
        hour=0;
        cout<<"clock comes out"<<endl;
    }
    // Clock(int h)
    // {
    //     hour=h;
    //     cout<<"clock comes out"<<endl;
    // }
    //上下两个是一样的
    Clock(int h):hour(h)//相当于int hour=h;
    {
        cout<<"this is list"<<endl;
    }
};
int main()
{
    Clock c1;
    Clock c2(10);
    Clock c3(10);
    return 0;
}