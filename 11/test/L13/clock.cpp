#include<iostream>
using namespace std;

class Clock{
    public:
    void SetHour(int hour)
    {
        // hour=hour;错误的，我自己赋值给自己，成员变量没变
        this->hour=hour;
        //把参数hour，赋给这个对象指向的hour成员
    }
    void showTime()
    {
        cout<<hour<<":"<<minute<<endl;
    }
    void setTime(int newH=0,int newM=0,int newS=0);
    private:
    int hour,minute,second;
};
void Clock::setTime(int newH, int newM, int newS)
{
    //能够访问私有成员，加了clock::
    hour=newH;
    minute=newM;
    second=newS;
}
int main()
{

    return 0;
}