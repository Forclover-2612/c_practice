#include<stdio.h>

int main()
{
    FILE*fp;
    fp=fopen("test.txt","w+");
    if(fp==NULL)
    {
        printf("fail to read&write\n");
        return 1;
    }
    char str[7]="ABCDE";
    fputs(str,fp);
    fseek(fp,0L,SEEK_SET);
    fseek(fp,2L,SEEK_CUR);
    fputc('X',fp);
    char ch;
    rewind(fp);
    while((ch=fgetc(fp))!=EOF)//从头读取
    {
        printf("%c",ch);
    }
    fclose(fp);
    return 0;
}