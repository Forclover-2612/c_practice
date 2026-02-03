#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
    int sno;
    char name[20];
    char sex;
    short age;
}Stu;
//结构体传地址效率较高
void check(Stu *stu)
{
    if(stu->sex=='M')
    {
        printf("%d\n",stu->sno);
    }
}
int main()
{
    Stu* stu=(Stu*)calloc(2,sizeof(Stu));
    if(stu==NULL)
    {
        printf("failed to memory");
    }
    scanf("%d %s %c %d",&stu[0].sno,stu[0].name,&stu[0].sex,&stu[0].age);
    scanf("%d %s %c %d",&stu[1].sno,stu[1].name,&stu[1].sex,&stu[1].age);
    for(int i=0;i<2;i++)
    {
        check(&stu[i]);
    }
    free(stu);
    return 0;
}