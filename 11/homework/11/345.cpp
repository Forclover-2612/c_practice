#include <iostream>
#include <string.h>
#include <cmath>
#include <algorithm>

using namespace std;

class Point
{
public:
    Point(int xx = 0, int yy = 0)
    {
        _x = xx;
        _y = yy;
    }
    Point(Point &p);

    int getX();
    int getY();

private:
    int _x;
    int _y;
};

Point::Point(Point &p)
{ // 复制构造函数的实现
    _x = p._x;
    _y = p._y;
}

int Point::getX()
{
    return this->_x;
}
int Point::getY()
{
    return this->_y;
}

class Line
{
public:
    Line(Point &a, Point &b);
    int getLength(); // 得到len的长度

private:
    void calLength(); // 计算线段长度，并保存到属性 _len 中
    Point _pa, _pb;
    int _len;
};

Line::Line(Point &a, Point &b) : _pa(a), _pb(b)
{
    this->calLength(); // 这一行是什么意思
    // 应该是调用：只要定义一个对象就进行线段长度的计算
    // 为什么要this
}

int Line::getLength()
{
    return this->_len;
}

// 只考虑平行状况
void Line::calLength()
{
    // 计算线段长度，并保存到属性 _len 中
    int x = abs(_pa.getX() - _pb.getX());
    int y = abs(_pa.getY() - _pb.getY());
    if (x != 0)
    {
        _len = x;
    }
    else
    {
        _len = y;
    }
}

class Rectangle
{
public:
    Rectangle(Point &lb_pt, Point &rt_pt); // 两个输入参数分别是左下角，右上角

    int getPerimeter();                    // 周长
    int getArea();                         // 面积
    int getOverlappedArea(Rectangle &rec); // 计算与另一个矩形重合面积

private:
    bool isOverlapped(Rectangle &rec);
    Point _LB, _RT, _LT, _RB; // 左下角，右上角，左上角，右下角
    Line _horizontal_line;
    Line _vertical_line;
};

Rectangle::Rectangle(Point &lb_pt, Point &rt_pt) : _LB(lb_pt),
                                                   _RT(rt_pt),
                                                   _LT(_LB.getX(), _RT.getY()),
                                                   _RB(_RT.getX(), _LB.getY()),
                                                   _horizontal_line(_LB, _RB),
                                                   _vertical_line(_LB, _LT)
{
}
// 得到周长
int Rectangle::getPerimeter()
{
    return 2 * (this->_horizontal_line.getLength() + this->_vertical_line.getLength());
}
// 得到面积
int Rectangle::getArea()
{
    return this->_horizontal_line.getLength() * this->_vertical_line.getLength();
}
// 得到重叠面积
int Rectangle::getOverlappedArea(Rectangle &rec)
{
    if (!this->isOverlapped(rec))
    {
        return 0;
    }
    else
    {
        int my_left = _LB.getX();
        int my_right = _RB.getX();
        int my_top = _LT.getY();
        int my_bottom = _RB.getY();

        int rec_left = rec._LB.getX();
        int rec_right = rec._RB.getX();
        int rec_top = rec._LT.getY();
        int rec_bottom = rec._RB.getY();

        int left = max(my_left,rec_left);
        int right=min(my_right,rec_right);
        int top=min(my_top,rec_top);
        int bottom=max(my_bottom,rec_bottom);

        return abs((left-right)*(top-bottom));
    }
}

bool Rectangle::isOverlapped(Rectangle &rec)
{
    // 判断是否有重叠面积
    // 底下的长方形的右上角的点在上面长方形的区域里面
    //  if(_RT.getX()>rec._LB.getX()&&_RT.getX()<rec._RB.get)
    // 如果不考虑包含关系
    // 逆向思维：排除法
    int my_left = _LB.getX();
    int my_right = _RB.getX();
    int my_top = _LT.getY();
    int my_bottom = _RB.getY();

    int rec_left = rec._LB.getX();
    int rec_right = rec._RB.getX();
    int rec_top = rec._LT.getY();
    int rec_bottom = rec._RB.getY();

    if (my_right <= rec_left || my_left >= rec_right || my_bottom >= rec_top || my_top <= rec_bottom)
        return false;

    return true;
}

int main()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int x3, y3, x4, y4;
    cin >> x3 >> y3 >> x4 >> y4;

    Point p1(x1, y1), p2(x2, y2), p3(x3, y3), p4(x4, y4);

    Rectangle rec1(p1, p2);
    Rectangle rec2(p3, p4);
    cout << rec1.getPerimeter() << " " << rec1.getArea();
    cout << " " << rec2.getPerimeter() << " " << rec2.getArea();
    cout << " " << rec1.getOverlappedArea(rec2);
    return 0;
}
