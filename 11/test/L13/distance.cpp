#include<iostream>
#include<cmath>
using namespace std;

class Point{
    private:
    int x;
    int y;
    public:
    Point(int xx=0,int yy=0):x(xx),y(yy)
    {

    }
    int distTo(const Point &p)
    {
        int d_x=p.x-this->x;//你的x-我的x
        int d_y=p.y-y;//你的y-我的y
        return (int)sqrt(d_x*d_x+d_y*d_y);
    }
    void printInfo()
    {
        cout<<"Point("<<x<<","<<y<<")"<<endl;
    }
};

int main()
{
    // Point p1();这会被当作函数声明
    Point p1(0,0);
    Point p2(3,4);
    cout<<"pos1:";
    p1.printInfo();
    cout<<"pos2:";
    p2.printInfo();

    int distance=p1.distTo(p2);//this是p1，参数p是p2
    cout<<distance<<endl;

    return 0;
}

