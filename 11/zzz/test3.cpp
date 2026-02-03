#include <stdio.h>
#include <math.h>
int main()
{
    double p, q, r, s;
    for (p = 2; p < 4; p++)
    {
        for (q = p; q < (3 / (1 - 1 / p)); q++)
        {
            for (r = q; r < (2 / (1 - 1 / p - 1 / q)); r++)
            {
                double remain = 1 - 1 / p - 1 / q - 1 / r;
                if (remain > 0)
                {
                    s = 1 / remain;
                    if (fabs(s - (int)s) < 1e-6 && s >= r)
                        printf("%lf %lf %lf %lf", p, q, r, s);
                }
                // if(fabs(s-(int)s)<1e-6&&s>=r)
                // printf("%lf %lf %lf %lf",p,q,r,s);
            }
        }
    }
    return 0;
}