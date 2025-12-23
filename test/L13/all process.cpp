#include<iostream>
using namespace std;

class Point{
    public:
    Point(int x)
    {
        cout<<"construct"<<x<<endl;
    }
    Point(const Point &p)
    {
        cout<<"copy"<<endl;
    }
    ~Point()
    {
        cout<<"destruct"<<endl;
    }
};
void func(Point p)
{
    cout<<"in func"<<endl;
}
int main()
{
    Point a(1);//construct 1
    cout<<endl;
    Point b=a;//copy
    cout<<endl;
    func(a);//copy->in func->destruct
    cout<<"End"<<endl;
    return 0;//a/b destruct
}