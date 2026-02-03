#include<stdio.h>
#include<math.h>
int main()
{
    double n;
    scanf("%lf",&n);

    int id,count=0;
    double a,b,c;
    for(int i=0;i<n;i++){
        scanf("%d %lf %lf",&id,&a,&b);
        c=b-a;
        if(c>=0){
            printf("%d %.2lf\n",id,c);//加上.2输出
            count++;
        }
    }

    double x;
    x = count/n*100;
    printf("%.2f%%\n",x);
    return 0;
}