#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
    int id;
    int score;
}Stu;
//void*qsort(void*base,size_t n,size_t size,int(*cmp)(const void*,const void*))
int compare_ints(const void*a,const void *b)
{
    int arg1=*(const int*)a;
    int arg2=*(const int*)b;
    //升序排列
    if(arg1<arg2)
    return -1;
    if(arg1>arg2)
    return 1;
    return 0;
    //return arg1-arg2有风险
}
int compare_doubles(const void*a,const void*b)
{
    double n1=*(const double*)a;
    double n2=*(const double*)b;
    //必须手动判断
    if(n1<n2)
    return -1;
    if(n1>n2)
    return 1;
    return 0;
}
int compare_chars(const void*a,const void*b)
{
    //小整数，直接减没问题
    return *(const char*)a-*(const char*)b;
}
int comparre_scores(const void*a,const void*b)
{
    const Stu* n1=(const Stu*)a;
    const Stu* n2=(const Stu*)b;
    //降序排列
    return n2->score-n1->score;
}
int compare_complex(const void *a, const void *b) {
    const Stu *s1 = (const Stu *)a;
    const Stu *s2 = (const Stu *)b;

    // 第一级比较
    if (s1->score != s2->score) {
        return s2->score - s1->score; // 分数降序
    }
    
    // 第二级比较 (当分数相等时)
    return s1->id - s2->id; // 学号升序
}
//字符串数组排序
//int strcmp(const char *s1, const char *s2);
//二维字符数组
int compare_strings_flat(const void*a,const void *b)
{
    return strcmp((const char *)a,(const char *)b);
}
//字符串指针数组
int compare_strings_ptr(const void*a,const void *b)
{
    //这里面给我们的参数实际上是地址的地址（char**)
    //解引用一次，变成char*
    const char *str1=*(const char **)a;
    const char *str2=*(const char **)b;
    return strcmp(str1,str2);
}
int main()
{
    //二维数组
    char names_2d[][10]={"Charlie", "Alice", "Bob"};
    int len1=3;
    qsort(names_2d,len1,sizeof(names_2d[1]),compare_strings_flat);
    printf("二维数组排序结果: %s, %s, %s\n", names_2d[0], names_2d[1], names_2d[2]);
    //指针数组
    const char *names_ptr[]={"Charlie", "Alice", "Bob"};
    int len2=3;
    qsort(names_ptr,len2,sizeof(char*),compare_strings_ptr);
    printf("指针数组排序结果: %s, %s, %s\n", names_ptr[0], names_ptr[1], names_ptr[2]);
    return 0;
}
