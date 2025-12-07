#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ================= 1. 比较函数定义区 =================

// 【场景一】整数比较
int cmp_int(const void *a, const void *b) {
    int arg1 = *(const int *)a;
    int arg2 = *(const int *)b;
    // 这种写法最稳，防溢出
    return (arg1 > arg2) - (arg1 < arg2); 
}

// 【场景二】浮点数比较 (降序：大到小)
int cmp_double_desc(const void *a, const void *b) {
    double arg1 = *(const double *)a;
    double arg2 = *(const double *)b;
    // 注意：降序是 "左 > 右" 返回 -1
    return (arg1 < arg2) - (arg1 > arg2); 
}

// 【场景三】结构体定义与比较
typedef struct {
    int id;
    int score;
} Student;

int cmp_student(const void *a, const void *b) {
    const Student *s1 = (const Student *)a;
    const Student *s2 = (const Student *)b;
    // 按分数降序排
    return s2->score - s1->score;
}

// 【场景四】字符串指针数组比较
// 注意：这里接收的是 char**
int cmp_str_ptr(const void *a, const void *b) {
    // a 是指向 (char*) 的指针
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;
    return strcmp(str1, str2); // 升序 (字典序)
}


// ================= 2. 主函数调用区 =================

int main() {
    // ---------------------------------------------------------
    // 案例 1：普通 int 数组排序
    // ---------------------------------------------------------
    int nums[] = {42, -5, 10, 0, 99};
    // 计算元素个数：总字节数 / 单个元素字节数
    size_t nums_len = sizeof(nums) / sizeof(nums[0]);

    qsort(nums,          // 1. 数组首地址
          nums_len,      // 2. 元素个数
          sizeof(int),   // 3. 每个元素多大 (也可以写 sizeof(nums[0]))
          cmp_int);      // 4. 比较函数

    printf("Int Sort: ");
    for(int i=0; i<nums_len; i++) printf("%d ", nums[i]);
    printf("\n\n");


    // ---------------------------------------------------------
    // 案例 2：double 数组 (降序)
    // ---------------------------------------------------------
    double prices[] = {3.14, 1.5, 9.9, 0.01};
    size_t prices_len = sizeof(prices) / sizeof(prices[0]);

    qsort(prices, 
          prices_len, 
          sizeof(double), // 注意这里是 double
          cmp_double_desc);

    printf("Double Sort: ");
    for(int i=0; i<prices_len; i++) printf("%.2f ", prices[i]);
    printf("\n\n");


    // ---------------------------------------------------------
    // 案例 3：结构体排序 (按分数)
    // ---------------------------------------------------------
    Student class_A[] = { {101, 85}, {102, 95}, {103, 60} };
    size_t class_len = sizeof(class_A) / sizeof(class_A[0]);

    qsort(class_A, 
          class_len, 
          sizeof(Student), // 告诉它搬运单位是整个结构体
          cmp_student);

    printf("Student Sort:\n");
    for(int i=0; i<class_len; i++) {
        printf("  ID: %d, Score: %d\n", class_A[i].id, class_A[i].score);
    }
    printf("\n");


    // ---------------------------------------------------------
    // 案例 4：字符串指针数组 (最难理解的部分)
    // ---------------------------------------------------------
    char *names[] = { "Charlie", "Alice", "Bob", "David" };
    size_t names_len = sizeof(names) / sizeof(names[0]);

    qsort(names, 
          names_len, 
          sizeof(char *), // ⚠️ 关键！每个元素是一个指针(8字节)，不是char
          cmp_str_ptr);

    printf("String Sort: ");
    for(int i=0; i<names_len; i++) printf("%s ", names[i]);
    printf("\n");

    return 0;
}