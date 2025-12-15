#include <stdio.h>
#include <stdlib.h> // 为了使用 exit

int main()
{
    // 1. 定义文件指针
    FILE *fp;

    // 2. 打开文件 (比如我们要写入一个叫 data.txt 的文件)
    // "w" 表示如果文件不存在就创建，如果存在就清空
    fp = fopen("data.txt", "w+");
    // fp=fopen("D:\\大一\\大一上\\程序设计\\data.txt","w");

    // 3. 错误检测 (非常重要！)
    // 如果文件打开失败（比如没有权限），fp 会等于 NULL
    if (fp == NULL)
    {
        printf("无法打开文件！\n");
        exit(0); // 退出程序
    }

    // --- 在这里进行读写操作 (我们下一阶段讲) ---
    // 1）读写单个字符
    fputc('H', fp);
    fputc('E', fp);
    fputc('L', fp);
    fputc('L', fp);
    fputc('O', fp);
    fputc('\n', fp);
    // fclose(fp);//如果只有“w”，关闭后重新以只读模式打开
    rewind(fp); // 重置指针
    char ch;
    while ((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
    }
    // 2）读写字符串、行
    char line[] = "WORLD\n";
    char buffer[100];
    fputs(line, fp);
    rewind(fp);
    // if(fgets(buffer,100,fp)!=NULL)
    // {
    //     printf("%s\n",buffer);
    // }
    // 从文件中读取到buffer
    if (fgets(buffer, 100, fp) != NULL)
    {
        // 注意：fgets 遇到换行符就会停止，所以这里可能只读到 "HELLO\n"
        printf("读第一行: %s", buffer);
        // 再读一次才能读到 WORLD
        if (fgets(buffer, 100, fp) != NULL)
            printf("读第二行: %s", buffer);
    }
    // 3）格式化读取
    //  在写入之前想记录当前文件指针的位置
    long current_pos = ftell(fp);
    int num = 12;
    char name[] = "Amy";
    // 格式化写入
    fprintf(fp, "num:%d,name:%s\n", num, name);
    //如果是stdout就是写在屏幕上
    // 格式化读取
    //    fseek(fp,-18L,SEEK_CUR);容易出错
    fseek(fp, current_pos, SEEK_SET); // 文件开头算起
    int read_num;
    char read_name[20];
    //读写格式必须一样
    fscanf(fp, "num:%d,name:%s\n", &read_num, read_name);
    printf("num %d/name %s\n", read_num, read_name);
    // 4. 关闭文件
    fclose(fp);

    return 0;
}