#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE_BUF_SIZE 2048
typedef struct
{
    char isbn[11]; // 10 digits isbn
    char name[LINE_BUF_SIZE];
    char author[LINE_BUF_SIZE];
    char publisher[LINE_BUF_SIZE];
    int year;
} book_record_t;
typedef struct
{
    // 指向一个存放所有图书数据的数组。
    // 特别注意：函数调用时，本数组并未分配空间，需要你根据读入的数据合理地动态分配空间

    book_record_t *data;

    int size; // 图书库中记录的条数（即数组元素的个数)
} book_manager_t;
int book_manager_load(book_manager_t *mgr, char *file_name)
{
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL)
    {
        return -1;
    }
    int n;
    fscanf(fp, "%d", &n);
    mgr->data = (book_record_t *)malloc(n * sizeof(book_record_t));
    if (mgr->data == NULL)
    {
        fclose(fp);
        return -1;
    }
    mgr->size = n;
    // 处理换行符？？？
    char temp[1000];
    // fgets的特性：从头开始覆盖，且后面会填上新的\0
    fgets(temp, 1000, fp); // n后面的换行符
    fgets(temp, 1000, fp);
    for (int i = 0; i < n; i++)
    {
        // 循环读取，但是fgets会读\n
        //数组比较短，直接fgets、容易溢出，先读到数组
        if (fgets(temp, 1000, fp) != NULL)
        {
            temp[strcspn(temp, "\n")] = '\0';
            strcpy(mgr->data[i].isbn, temp);
        }
        if (fgets(mgr->data[i].name, 1000, fp) != NULL)
        {
            mgr->data[i].name[strcspn(mgr->data[i].name,"\n")]='\0';
        }
        if(fgets(mgr->data[i].author,1000,fp)!=NULL)
        {
            mgr->data[i].author[strcspn(mgr->data[i].author,"\n")]='\0';
        }
        if(fgets(mgr->data[i].publisher,1000,fp)!=NULL)
        {
            mgr->data[i].publisher[strcspn(mgr->data[i].publisher,"\n")]='\0';
        }
        fscanf(fp,"%d",&mgr->data[i].year);
        //处理记录之间的空行
        fgets(temp,1000,fp);
        fgets(temp,1000,fp);
    }
    fclose(fp);
    return 0;
}
int main()
{

    return 0;
}