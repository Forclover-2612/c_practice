#include <stdio.h>

int main()
{
    char str[50], src[] = "Hi";
    sprintf(str, "%5s", src); // 结果："   Hi"（前面补3个空格，总长度5）
    printf("%s\n",str);
    sprintf(str, "%3s", src); // 结果："Hi"（不足3位补1个空格？不！实际是" Hi"，补1个空格凑3位）
    printf("%s\n",str);
    sprintf(str, "%1s", src); // 结果："Hi"（超出1位，不截断，原样输出）
    printf("%s\n",str);
    return 0;
}