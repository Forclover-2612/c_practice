#include <stdio.h>
#include <string.h>
char str[300];
//"贴纸"--覆盖操作
int main()
{
    // int arr1[4]={0};
    // int arr2[4]={0};
    int arr1[1000][3] = {0};
    int arr2[1000][4] = {0};
    fgets(str, sizeof(str), stdin);
    int len = strlen(str) - 1;
    // 原思路：但是是错的
    //原思路1：单纯统计字符数：漏掉单个字符也代表原来单词的情况（比如说两个单个字符）
    //原思路2：模拟叠加，但是忽略统计成为一层的必须相连
    //思路3：写起来比较冗长，不够清晰
    //  for(int i=0;i<len;i++)
    //  {
    //      if(str[i]=='b')
    //      arr1[0]++;
    //      if(str[i]=='o')
    //      arr1[1]++;
    //      if(str[i]=='y')
    //      arr1[2]++;
    //      if(str[i]=='g')
    //      arr2[0]++;
    //      if(str[i]=='i')
    //      arr2[1]++;
    //      if(str[i]=='r')
    //      arr2[2]++;
    //      if(str[i]=='l')
    //      arr2[3]++;
    //  }
    //  int max1=arr1[0];
    //  int max2=arr2[0];
    //  for(int i=1;i<4;i++)
    //  {
    //      if(arr1[i]>max1)
    //      {
    //          max1=arr1[i];
    //      }
    //      if(arr2[i]>max2)
    //      {
    //          max2=arr2[i];
    //      }
    //  }
    //  printf("%d\n%d",max1,max2);
    // 像层数一样
    //  int count1=0,flag1=0;
    //  int count2=0,flag2=0;
    //  for(int i=0;i<len;i++)
    //  {
    //      if(str[i]=='b')
    //      {
    //          flag1=1;
    //          if(arr1[count1][0])
    //          {
    //              count1++;
    //          }
    //          arr1[count1][0]++;
    //      }
    //      if(str[i]=='o')
    //      {
    //          flag1=1;
    //          if(arr1[count1][1]||arr1[count1][2])
    //          {
    //              count1++;
    //          }
    //          arr1[count1][1]++;
    //      }
    //      if(str[i]=='y')
    //      {
    //          flag1=1;
    //          if(arr1[count1][2])
    //          {
    //              count1++;
    //          }
    //          arr1[count1][2]++;
    //      }
    //      if(str[i]=='g')
    //      {
    //          flag2=1;
    //          if(arr2[count2][0])
    //          {
    //              count2++;
    //          }
    //          arr2[count2][0]++;
    //      }
    //      if(str[i]=='i')
    //      {
    //          flag2=1;
    //          if(arr2[count2][1]||(arr2[count2][2]+arr2[count2][3]))
    //          {
    //              count2++;
    //          }
    //          arr2[count2][1]++;
    //      }
    //      if(str[i]=='r')
    //      {
    //          flag2=1;
    //          if(arr2[count2][2]||arr2[count2][3])
    //          {
    //              count2++;
    //          }
    //          arr2[count2][2]++;
    //      }
    //      if(str[i]=='l')
    //      {
    //          flag2=1;
    //          if(arr2[count2][3])
    //          {
    //              count2++;
    //          }
    //          arr2[count2][3]++;
    //      }
    //  }
    //  // printf("%d\n%d",count1+1,count2+1);
    //  if(flag1)
    //  {
    //      printf("%d\n",count1+1);
    //  }
    //  else
    //  {
    //      printf("0\n");
    //  }
    //  if(flag2)
    //  {
    //      printf("%d\n",count2+1);
    //  }
    //  else
    //  {
    //      printf("0\n");
    //  }
    int count1 = 0, count2 = 0;
    char *pos = str;
    while (*pos != '\n' && *pos != '\0')
    {
        int idx = pos - str;
        if (str[idx] == 'b')
        {
            if (str[idx + 1] == 'o')
            {
                pos += 1;
                if (str[idx + 2] == 'y')
                    pos += 1;
            }
            count1++;
        }
        if (str[idx] == 'o')
        {
            if (str[idx + 1] == 'y')
                pos += 1;
            count1++;
        }
        if (str[idx] == 'y')
        {
            count1++;
        }
        if (str[idx] == 'g')
        {
            if (str[idx + 1] == 'i')
            {
                pos += 1;
                if (str[idx + 2] == 'r')
                {
                    pos += 1;
                    if (str[idx + 3] == 'l')
                        pos += 1;
                }
            }
            count2++;
        }
        if (str[idx] == 'i')
        {
            if (str[idx + 1] == 'r')
            {
                pos += 1;
                if (str[idx + 2] == 'l')
                    pos += 1;
            }
            count2++;
        }
        if (str[idx] == 'r')
        {
            if (str[idx + 1] == 'l')
                pos++;
            count2++;
        }
        if (str[idx] == 'l')
        {
            count2++;
        }
        pos++;
    }
    printf("%d\n%d",count1,count2);
    return 0;
}