#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

class Rectangle
{

public:
    // 在下面的空格声明 Rectangle 类的成员函数
    Rectangle(double x1, double y1, double x2, double y2)
    {
        _x1=x1;
        _x2=x2;
        _y1=y1;
        _y2=y2;
    }
    void calculate();
    double countS();
    double countC();

private:
    // 左下角坐标
    double _x1;
    double _y1;

    // 右上角坐标
    double _x2;
    double _y2;

    // 宽度和高度
    double _width;
    double _height;
};

// 在下面的空格实现 Rectangle 类的成员函数

void Rectangle::calculate()
{
    _width=fabs(_x1-_x2);
    _height=fabs(_y1-_y2);
}
double Rectangle::countS()
{
    return _width*_height;
}
double Rectangle::countC()
{
    return 2*(_width+_height);
}

int main()
{

    double x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    Rectangle r1(x1, y1, x2, y2);

    Rectangle r2 = r1;

    // 在下面的空格按题目要求输出结果

    r1.calculate();
    r2.calculate();
    double C=r1.countC();
    double S=r1.countS();
    cout<<fixed<<setprecision(2)<<C<<endl;
    cout<<fixed<<setprecision(2)<<S<<endl;
    cout<<fixed<<setprecision(2)<<2*C<<endl;
    cout<<fixed<<setprecision(2)<<2*S<<endl;

    return 0;
}
