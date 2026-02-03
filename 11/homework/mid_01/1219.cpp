#include<stdio.h>

int main()
{
    int t;
    int i,j,p;
    scanf("%d",&t);
    int num[52];
    int arr[52][4][13]={0};//52组，4种花色（DCHS），13种点数
    char str[2];
    int count;
    for(i=0;i<t;i++)//组数
    {
        scanf("%d",&num[i]);
        for(j=0;j<num[i];j++)//组中元素个数
        {
            scanf("%s",str);
            if(str[0]=='D')
            {
                if(str[1]=='A')
                {
                    arr[i][0][0]=1;
                }
                else if(str[1]=='2')
                {
                    arr[i][0][1]=1;
                }
                else if(str[1]=='3')
                {
                    arr[i][0][2]=1;
                }
                else if(str[1]=='4')
                {
                    arr[i][0][3]=1;
                }
                else if(str[1]=='5')
                {
                    arr[i][0][4]=1;
                }
                else if(str[1]=='6')
                {
                    arr[i][0][5]=1;
                }
                else if(str[1]=='7')
                {
                    arr[i][0][6]=1;
                }
                else if(str[1]=='8')
                {
                    arr[i][0][7]=1;
                }
                else if(str[1]=='9')
                {
                    arr[i][0][8]=1;
                }
                else if(str[1]=='T')
                {
                    arr[i][0][9]=1;
                }
                else if(str[1]=='J')
                {
                    arr[i][0][10]=1;
                }
                else if(str[1]=='Q')
                {
                    arr[i][0][11]=1;
                }
                else if(str[1]=='K')
                {
                    arr[i][0][12]=1;
                }
            }
            else if(str[0]=='C')
            {
                if(str[1]=='A')
                {
                    arr[i][1][0]=1;
                }
                else if(str[1]=='2')
                {
                    arr[i][1][1]=1;
                }
                else if(str[1]=='3')
                {
                    arr[i][1][2]=1;
                }
                else if(str[1]=='4')
                {
                    arr[i][1][3]=1;
                }
                else if(str[1]=='5')
                {
                    arr[i][1][4]=1;
                }
                else if(str[1]=='6')
                {
                    arr[i][1][5]=1;
                }
                else if(str[1]=='7')
                {
                    arr[i][1][6]=1;
                }
                else if(str[1]=='8')
                {
                    arr[i][1][7]=1;
                }
                else if(str[1]=='9')
                {
                    arr[i][1][8]=1;
                }
                else if(str[1]=='T')
                {
                    arr[i][1][9]=1;
                }
                else if(str[1]=='J')
                {
                    arr[i][1][10]=1;
                }
                else if(str[1]=='Q')
                {
                    arr[i][1][11]=1;
                }
                else if(str[1]=='K')
                {
                    arr[i][1][12]=1;
                }
            }
            else if(str[0]=='H')
            {
                if(str[1]=='A')
                {
                    arr[i][2][0]=1;
                }
                else if(str[1]=='2')
                {
                    arr[i][2][1]=1;
                }
                else if(str[1]=='3')
                {
                    arr[i][2][2]=1;
                }
                else if(str[1]=='4')
                {
                    arr[i][2][3]=1;
                }
                else if(str[1]=='5')
                {
                    arr[i][2][4]=1;
                }
                else if(str[1]=='6')
                {
                    arr[i][2][5]=1;
                }
                else if(str[1]=='7')
                {
                    arr[i][2][6]=1;
                }
                else if(str[1]=='8')
                {
                    arr[i][2][7]=1;
                }
                else if(str[1]=='9')
                {
                    arr[i][2][8]=1;
                }
                else if(str[1]=='T')
                {
                    arr[i][2][9]=1;
                }
                else if(str[1]=='J')
                {
                    arr[i][2][10]=1;
                }
                else if(str[1]=='Q')
                {
                    arr[i][2][11]=1;
                }
                else if(str[1]=='K')
                {
                    arr[i][2][12]=1;
                }
            }
            else if(str[0]=='S')
            {
                if(str[1]=='A')
                {
                    arr[i][3][0]=1;
                }
                else if(str[1]=='2')
                {
                    arr[i][3][1]=1;
                }
                else if(str[1]=='3')
                {
                    arr[i][3][2]=1;
                }
                else if(str[1]=='4')
                {
                    arr[i][3][3]=1;
                }
                else if(str[1]=='5')
                {
                    arr[i][3][4]=1;
                }
                else if(str[1]=='6')
                {
                    arr[i][3][5]=1;
                }
                else if(str[1]=='7')
                {
                    arr[i][3][6]=1;
                }
                else if(str[1]=='8')
                {
                    arr[i][3][7]=1;
                }
                else if(str[1]=='9')
                {
                    arr[i][3][8]=1;
                }
                else if(str[1]=='T')
                {
                    arr[i][3][9]=1;
                }
                else if(str[1]=='J')
                {
                    arr[i][3][10]=1;
                }
                else if(str[1]=='Q')
                {
                    arr[i][3][11]=1;
                }
                else if(str[1]=='K')
                {
                    arr[i][3][12]=1;
                }
            }
        }
    }
    for(i=0;i<t;i++)
    {
        count=0;
        for(j=0;j<4;j++)//访问花色
        {
            for(p=0;p<13;p++)
            {
                if(arr[i][j][p]==0)
                {
                    count++;
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}