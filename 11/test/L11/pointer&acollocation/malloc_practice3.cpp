#include<stdio.h>
#include<stdlib.h>
//二级指针 **p 有一个非常重要的真实用途：
//当函数需要修改“指针变量本身”的指向时。
typedef struct 
{
    int sno;
    char name[20];
    char sex;
    short age;
}Student;
// 错误写法：只传一级指针
void init_wrong(Student *s) {
    // 这里的 s 只是 main 函数里 stu 的一个“复印件”
    // 你改变 s 的指向，main 函数里的 stu 根本不知道，还是指向 NULL
    s = (Student *)calloc(2, sizeof(Student)); 
}

// 正确写法：传二级指针（指针的地址）
void init_right(Student **s) { // 接收指针的地址
    // *s 代表修改那个地址里存的内容（即修改 main 里的 stu 指向哪里）
    *s = (Student *)calloc(2, sizeof(Student));
}

int main() {
    Student *stu = NULL;
    
    // init_wrong(stu); // 跑完之后 stu 还是 NULL，程序崩溃
    
    init_right(&stu);   // 把 stu 变量的地址传进去，函数就能修改 stu 了！
    
    // ...
}