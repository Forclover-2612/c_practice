#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *infp,*outfp;
    int ch;
    if((infp=fopen("test.txt","r"))==NULL)
    {
        printf("Cannot open input file\n");
        exit(0);
    }
    if((outfp=fopen("test_copy.txt","w"))==NULL)
    {
        printf("Cannot open output file.\n");
        exit(0);
    }
    while((ch=fgetc(infp))!=EOF)
    {
        fputc(ch,outfp);
    }
    fclose(infp);
    fclose(outfp);
    return 0;
}