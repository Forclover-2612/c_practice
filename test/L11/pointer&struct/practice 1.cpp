#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student
{
    char name[20];
    int age;
    int score[10];
} Stu;
// 用法1：高效传递结构体
void PrintStudent(const Stu *s)
{
    printf("%s %d\n", s->name, s->age);
}
// 用法2：申请内存
Stu *createStudent(const char *s, int n, int *arr)
{
    Stu *p = (Stu *)malloc(sizeof(Stu));
    if (p != NULL)
    {
        p->age = n;
        strcpy(p->name, s);
        // 比较安全的做法：要先传入元素个数再储存比较好
        for (int i = 0; i < 3; i++)
        {
            p->score[i] = arr[i];
        }
    }
    return p;
}
int main()
{
    Stu s = {"Alice", 18, {12, 36, 24, 64, 78}};
    PrintStudent(&s);
    // createStudent("Bob",20,{12,34,51});这种初始化列表只能用于变量初始化
    int scores[] = {12, 34, 51};
    Stu *p = createStudent("Bob", 20, scores);
    // 用法3：管理大量的结构体
    Stu *Data[2];
    Data[0] = &s;
    Data[1] = p;
    printf("%s %d\n", Data[1]->name, Data[1]->age);
    free(p);
    p = NULL;
    return 0;
}