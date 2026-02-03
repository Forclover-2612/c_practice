#include<stdio.h>

int main()
{
    int a,b,c,d,e,f;
    for(a=0;a<=1;a++)
    {
        for(b=0;b<=1;b++)
        {
            for(c=0;c<=1;c++)
            {
                for(d=0;d<=1;d++)
                {
                    for(e=0;e<=1;e++)
                    {
                        for(f=0;f<=1;f++)
                        {
                            if(a+b>=1 && a+d<2 && a+e+f>=2 && b==c && c+d==1 && e<=d)
                            //如何理解若D没参与，E也不可能参与（如果D参与了，E就一定参与吗）
                            //等价于若E参与，D一定参与
                            //不能这么写 b+c==2||0
                            {
                                printf("%d %d %d %d %d %d\n",a,b,c,d,e,f);
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}