#include<stdio.h>

int main()
{
    int n_cocks,n_hens,n_chicks;
    for(n_cocks=1;n_cocks<=20;n_cocks++)
    {
        for(n_hens=1;n_hens<=33;n_hens++)
        {
            n_chicks=100-n_cocks-n_hens;
            if(n_chicks>=0&&n_chicks%3==0&&5*n_cocks+3*n_hens+n_chicks/3==100)
            {
                printf("%d %d %d\n",n_cocks,n_hens,n_chicks);
            }
        }
    }
    return 0;
}