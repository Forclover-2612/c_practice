#include <stdio.h> 
#include <math.h>
/*int main() 
{ 
double a1= 20.0/180*3.1415926;
double a2= 10.0/180*3.1415926;   
double c=sin(a1)*cos(a1)-cos(a2)/tan(a2);
printf("%lf",c);
return 0;
} */
#define M_PI 3.14159265358979323846  // 高精度π

int main() { 
    double a1 = 20.0 / 180 * M_PI;
    double a2 = 10.0 / 180 * M_PI;   
    double c = sin(a1)*cos(a1) - cos(a2)/tan(a2);
    printf("%.6lf", c);  // 输出约为 -5.263660
    return 0;
}
//需要分别计算三角函数值再运算吗