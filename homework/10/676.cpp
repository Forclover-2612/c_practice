#include <stdio.h>
//最好还是写成数组映射的形式
//还有每次判断质数即可

void word(char *s)
{
    int map[26]={0};
    char *pos=s;
    while(*pos!='\0')
    {
        if(*pos>='a'&&*pos<='z')
        {
            map[*pos-'a']++;
        }
        pos++;
    }
    int min=101;
    int max=0;
    for(int i=0;i<26;i++)
    {
        if(map[i]==0)continue;
        else if(map[i]>max)
        max=map[i];
        else if(map[i]<min)
        min=map[i];
    }
    int diff=max-min;
    int is_prime=1;

    if(diff<2)
    {
        is_prime=0;
    }
    else{
        for(int i=2;i*i<=diff;i++)
    {
        if(diff%i==0)
        {
            is_prime=0;
            break;
        }
    }
    }
    if (is_prime)
    {
        printf("Lucky Word\n");
        printf("%d\n", diff);
    }
    else
    {
        printf("No Answer\n");
        printf("0\n");
    }
}
int main(void)
{
    char s[102];
    scanf("%s", s);
    word(s);
    return 0;
}
// void word(char *s)
// {
//     int i,j;
//     int flag;
//     int count=0;
//     char letter[100];
//     //有垃圾值
//     for(i=0;i<100;i++)
//     {
//         letter[i]='\0';
//     }
//     int letter_count[100]={0};
//     int nLetter=0;
//     char *pos=s;
//     // int len=strlen(s);
//     //首先打印1~100的质数表
//     int primes[30];
//     for(i=2;i<=100;i++)
//     {
//         flag=0;
//         for(j=2;j*j<=i;j++)
//         {
//             if(i%j==0)
//             {
//                 flag=1;
//                 break;
//             }
//         }
//         if(!flag)
//         primes[count++]=i;
//     }
//     //统计每个字母出现的次数
//     while(*pos!='\0')
//     {
//         flag=0;
//         for(i=0;i<nLetter;i++)
//         {
//             if(*pos==letter[i])
//             {
//                 letter_count[i]++;
//                 flag=1;
//                 break;
//             }
//         }
//         if(!flag)
//         {
//             letter[nLetter]=*pos;
//             letter_count[nLetter]++;
//             nLetter++;
//         }
//         pos++;
//     }
//     //排序/直接找出最大值最小值
//     int min=101;
//     int max=0;
//     for(i=0;i<nLetter;i++)
//     {
//         if(letter_count[i]>max)
//         max=letter_count[i];
//         if(letter_count[i]<min)
//         min=letter_count[i];
//     }
//     flag=0;
//     for(i=0;i<count;i++)
//     {
//         if(max-min==primes[i])
//         {
//             flag=1;
//             printf("Lucky Word\n");
//             printf("%d\n",max-min);
//             break;
//         }
//     }
//     if(!flag)
//     {
//         printf("No Answer\n");
//         printf("0\n");
//     }
// }