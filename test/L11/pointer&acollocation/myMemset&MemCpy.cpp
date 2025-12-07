#include <stdio.h>
#include <stdlib.h>
void *myMemset(void *dst, int val, size_t count);
void *Memset(void *dst,int val,size_t count);
void *myMemcpy(void *dest, const void *src, size_t count);
void *myMemmove(void *dest,const void *src,size_t count);
void *myMemcpy_Fast(void *dest,const void* src,size_t count);
void *Memcpy(void *dest,void *src,size_t n);
int main()
{

    return 0;
}
// 目标地址，设置的值，字节数
void *myMemset(void *dst, int val, size_t count)
{
    // 1.指针转换：把无类型指针转化为字节指针
    // p++的时候，每次只走1个字节
    char *p = (char *)dst;
    // 2.数值转换：把int截断成一个字节
    char v = (char)val;
    // 循环：用p指针遍历，把v赋值进去
    while (count > 0)
    {
        *p = v;
        p++;
        count--;
    }
    return dst;
}
void *Memset(void *dst,int val,size_t count)
{
    void* ret=dst;
    while(count--)
    {
        *(char*)dst=(char)val;
        dst=(char *)dst+1;//移动一个字节
    }
    return ret;
}
// 目标地址（通用指针，要复制到哪里去），源地址，字节数
void *myMemcpy(void *dest, const void *src, size_t count)
{
    // 1.把dest转化为字节指针
    char *p = (char *)dest;
    // 2.把src转化为常字节指针
    const char *v = (const char *)src;
    // 3.循环复制
    while (count > 0)
    {
        *p = *v;
        p++;
        v++;
        //*p++=*v++;
        count--;
    }
    return dest;
}
void *myMemmove(void *dest,const void *src,size_t count)
{
    char *p=(char *)dest;
    const char *v=(const char *)src;
    //还是要用转换好的char*指针进行比较，不要用void*
    if(v+count>=p&&p>v)//要被拷贝的目标地址在要拷贝进的地址的后面，且发生了重叠
    {
        //从后往前拷贝
        //对应数组下标：count是10，进入循环是9（先判断后--）
        while(count--)
        {
            *(p+count)=*(v+count);
        }
    }
    else 
    {
        while(count--)
        {
            *p++=*v++;
        }
    }
    return dest;
}
void *myMemcpy_Fast(void *dest,const void* src,size_t count)
{
    //1.先按字符指针理解
    char *d=(char *)dest;
    const char *s=(const char *)src;
    //2.计算8字节整体数量
    size_t chunks=count/8;
    size_t tail=count%8;
    //3.强转成long long类型
    long long *d64=(long long *)d;
    const long long *s64=(const long long *)s;
    //4.整体操作
    while(chunks--)
    {
        *d64++=*s64++;
    }
    //剩下的内容强转char类型
    d=(char*)d64;
    s=(const char*)s64;
    //最后的操作
    while(tail--)
    {
        *d++=*s++;
    }
    return dest;
}
void *Memcpy(void *dest,const void *src,size_t n)
{
    char *csrc=(char*)src;
    char *cdest=(char *)dest;

    for(int i=0;i<n;i++)
    {
        cdest[i]=csrc[i];
    }
    return dest;
}