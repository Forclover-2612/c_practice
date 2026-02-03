#include <stdio.h>
#include <string.h>
// int snprintf(char *str, size_t size, const char *format, ...);
int main()
{
    char buf[50];
    char name[] = "Alice";
    int id = 101;

    // 直接告诉它：我有 50 个字节，剩下的你自己看着办
    snprintf(buf, sizeof(buf), "User: %s ID: %d", name, id);

    printf("%s\n", buf); // 输出: User: Alice ID: 101

    // 追加字符串
    char str[100] = "Hello"; // 假设这里面已经有东西了
    int len = strlen(buf);   // 算出目前用了多少

    // 这里的逻辑是：
    // 1. dest 地址偏移到末尾： buf + len
    // 2. 剩余空间大小： sizeof(buf) - len
    snprintf(buf + len, sizeof(str) - len, ", World!");
    // size参数包含\0
    // 不能让原字符串和目标字符串重叠
    // char buf[20] = "Apple";
    // // ❌ 错误用法：想给自己追加内容
    // // 有些系统上会成功，有些会乱码，有些会崩溃
    // snprintf(buf, sizeof(buf), "%sPie", buf);
    return 0;
}