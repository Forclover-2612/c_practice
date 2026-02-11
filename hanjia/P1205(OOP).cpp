//struct 和 class（类）几乎是一样的
//可以包含函数（数据自带操作），可以重新定义运算符，把数组包在struct里面可以直接赋值，不用写双重循环
#include <iostream>
#include <algorithm>
using namespace std;

int n;

// 定义一个结构体来存图，方便复制和传参
struct Grid {
    char a[15][15];

    // 重载 == 运算符，方便直接用 if(g1 == g2) 比较
    bool operator==(const Grid &other) const {
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(a[i][j] != other.a[i][j]) return false;
        return true;
    }

    // 返回顺时针旋转90度后的新图
    Grid rotate() {
        Grid res;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                res.a[j][n-1-i] = a[i][j];
        return res;
    }

    // 返回水平翻转后的新图
    Grid reflect() {
        Grid res;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                res.a[i][n-1-j] = a[i][j];
        return res;
    }
} start, target;

int main() {
    cin >> n;
    for(int i=0; i<n; i++) cin >> start.a[i];   // 读入初始图
    for(int i=0; i<n; i++) cin >> target.a[i];  // 读入目标图

    // 1. 转 90度
    Grid temp = start.rotate();
    if(temp == target) { cout << 1; return 0; }

    // 2. 转 180度 (在90度的基础上再转一次)
    temp = temp.rotate();
    if(temp == target) { cout << 2; return 0; }

    // 3. 转 270度 (在180度的基础上再转一次)
    temp = temp.rotate();
    if(temp == target) { cout << 3; return 0; }

    // 4. 反射
    temp = start.reflect();
    if(temp == target) { cout << 4; return 0; }

    // 5. 组合 (反射后的图形，尝试转 1~3 次)
    // 此时 temp 已经是 reflect 过的了
    for(int i=1; i<=3; i++) {
        temp = temp.rotate();
        if(temp == target) { cout << 5; return 0; }
    }

    // 6. 不改变
    if(start == target) { cout << 6; return 0; }

    // 7. 无效
    cout << 7;
    return 0;
}