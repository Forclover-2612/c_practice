#include <iostream>
#include <stdio.h>
#include <math.h>
#define PI 3.1415926
using namespace std;

double normalize_x(double x)
{
    if (x < 0)
    {
        while (x <= (-2.0) * PI)
        {
            x += 2.0 * PI;
        }
        return x;
    }
    else if (x > 0)
    {
        while (x >= 2.0 * PI)
        {
            x -= 2.0 * PI;
        }
        return x;
    }
    else
        return x;
}

double step(double x)
{
    int i = 1;
    long double s = 1;
    if (x == 0)
        return 1;
    else
    {
        for (i = 1; i <= x; i++)
        {
            s *= i;
        }
        return s;
    }
}

long double my_sin(double x, double k)
{
    long double sum = 0;
    x = normalize_x(x);
    for (int i = 1;; i += 4)
    {
        sum += (pow(x, i) / step(i) - pow(x, i + 2) / step(i + 2));
        if (fabs(sum - sin(x)) < k)
            break;
    }
    return sum;
}

long double my_cos(double x, double k)
{
    long double sum = 0;
    x = normalize_x(x);
    for (int i = 0;; i += 4)
    {
        sum += (pow(x, i) / step(i) - pow(x, i + 2) / step(i + 2));
        if (fabs(sum - cos(x)) < k)
            break;
    }
    return sum;
}

int main()
{
    double x, k;
    scanf("%lf %lf", &x, &k);
    printf("%lf\n", my_sin(x, k));
    printf("%lf\n", my_cos(x, k));
    return 0;
}