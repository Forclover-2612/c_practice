#include<stdio.h>

typedef struct{
    int id;
    char name[10];
}Student;
int main()
{
    Student s1={101,"Alice"};//准备写入的数据
    Student s_read;//准备读取到的数据

    FILE *fp=fopen("students.dat","wb+");
    if(fp==NULL)
    {
        return 1;
    }
    //块数量
    fwrite(&s1,sizeof(Student),1,fp);
    rewind(fp);
    fread(&s_read,sizeof(Student),1,fp);    
    printf("%d %s",s_read.id,s_read.name);
    return 0;
}