#include <stdio.h>
#include <string.h>
// 符号判断函数
int sign(char arr[], int n)
{
    if (arr[0] != '-')
        return 1;
    else
    {
        for (int i = 1; i < n; i++)
        {
            // 从前往后操作
            arr[i - 1] = arr[i];
        }
        arr[n - 1] = '\0';
        return 0;
    }
}
// 颠倒函数
void reverse(char arr[], int n) // 或者写char *arr
{
    int left, right;
    left = 0;
    right = n - 1;
    char temp;
    while (left <= right)
    {
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}
// 加法函数
void plus(char arr1[], char arr2[], char result[], int len1, int len2)
{
    int carry = 0; // 进位
    int i, j;
    for (i = 0; i < len2; i++)
    {
        int num1 = arr1[i] - '0';
        int num2 = arr2[i] - '0';
        int sum = carry + num1 + num2;
        result[i] = (sum % 10) + '0';
        // 更新进位
        carry = sum / 10;
    }
    // 多余的部分
    for (i = len2; i < len1; i++)
    {
        int num = arr1[i] - '0';
        int sum = num + carry;
        result[i] = (sum % 10) + '0';
        carry = sum / 10;
    }
    if (carry == 0)
    {
        result[len1] = '\0';
        return;
    }
    else
    {
        result[len1] = 1+'0';//一定要注意！！！
        result[len1 + 1] = '\0';
        return;
    }
}
// 减法函数
// 错误！！未转化回字符
void sub(char arr1[], char arr2[], char result[], int len1, int len2)
{
    int carry = 0; // 借位
    int i, j;
    for (i = 0; i < len2; i++)
    {
        int num1 = arr1[i] - '0';
        int num2 = arr2[i] - '0';
        int sum = num1 - num2 - carry;
        if (sum >= 0)
        {
            result[i] = sum + '0';
            carry = 0;
        }
        if (sum < 0)
        {
            result[i] = 10 + sum + '0';
            carry = 1;
        }
    }
    //多余的部分分类：如果len1多的一位恰好是1且被借位，直接输出
    //但是分类有误，如果是像54-45第一位？
    //这个要怎么解决：统一去除前导0
    // if ((len1 == len2 + 1 && carry == 1 && arr1[len1 - 1] == 1) || len1 == len2)
    // {
    //     result[len2] = '\0';
    //     return;
    // }
    // else
    // {
    //处理剩余高位，借位要传递到底
        if (carry == 1)
        {
            // 先处理第一个元素
            // result[len2] = (arr1[len2]-'0'-1)+'0';//仍有错误，自动转化成数字计算？？
            // for (i = len2 + 1; i < len1; i++)
            // {
            //     result[i] = arr1[i];
            // } 
            //注意这个循环条件的写法
            for(i=len2;i<len1&&carry==1;i++)
            {
                int num=arr1[i]-'0';
                num-=carry;
                if(num>=0)
                {
                    result[i]=num+'0';
                    carry=0;//借位清零，无须继续
                }
                else
                {
                    result[i]=(num+10)+'0';
                    carry=1;
                }
            }  
        }
        else
        {
            for (i = len2; i < len1; i++)
            {
                result[i] = arr1[i];
            }
        }
        result[len1] = '\0';
        return;
    // }
}
//去掉前置0
void deletezero(char arr[],int len)
{
    if(arr[0]=='-')
    {
        if(arr[1]!='0')
        {
            return;
        }
        else
        {
            for(int i=2;i<=len;i++)
            {
                arr[i-1]=arr[i];
            }
            return;
        }
    }
    else
    {
        if(arr[0]!='0')
        return;
        else
        {
            //是否全是0？
            if(arr[1]=='0')
            {
                arr[0]='0';
                arr[1]='\0';
            }
            else
            {
                for(int i=1;i<=len;i++)
                {
                    arr[i-1]=arr[i];
                }
                return;
            }
        }
    }

}
int main()
{
    char arr1[2000];
    char arr2[2000];
    char result[2005];
    char temp[2000];
    int sign1 = 1;
    int sign2 = 1;
    int len;
    int sign0;
    int i, j;
    char ch;
    int flag = 0; // 交换的标志
    // 输入操作
    scanf("%c", &ch);
    // 输入数字
    scanf("%s", arr1);
    scanf("%s", arr2);
    // 保存长度
    int len1 = strlen(arr1);
    int len2 = strlen(arr2);
    // 判断符号并提取数值
    sign1 = sign(arr1, len1);
    sign2 = sign(arr2, len2);
    // 注意：长度发生变化
    if (!sign1)
        len1--;
    if (!sign2)
        len2--;
    // 颠倒字符串便于计算
    reverse(arr1, len1);
    reverse(arr2, len2);
    if (len1 < len2)
    {
        strcpy(temp, arr1);
        strcpy(arr1, arr2);
        strcpy(arr2, temp);
        // 同步交换len1,len2
        len = len1;
        len1 = len2;
        len2 = len;
        // 同步交换符号
        sign0 = sign1;
        sign1 = sign2;
        sign2 = sign0;

        flag = 1;
    }
    if (len1 == len2)
    {
        // 逐个判断，从后往前
        for (i = len1 - 1; i >= 0; i--)
        {
            //判断逻辑有误
            if(arr1[i]>arr2[i])
            break;
            if (arr2[i] > arr1[i])
            {
                strcpy(temp, arr1);
                strcpy(arr1, arr2);
                strcpy(arr2, temp);
                sign0 = sign1;
                sign1 = sign2;
                sign2 = sign0;
                flag = 1;
                break;
            }
        }
    }
    // 判断正负号
    // 四种情况：两个+;+/-;-/+;两个-号
    if (ch == '+')
    {
        if (sign1 == 1 && sign2 == 1)
        {
            plus(arr1, arr2, result, len1, len2);
            len = strlen(result);
            reverse(result, len);
        }
        if (sign1 == 1 && sign2 == 0)
        {
            sub(arr1, arr2, result, len1, len2);
            len = strlen(result);
            reverse(result, len);
        }
        if (sign1 == 0 && sign2 == 1)
        {
            sub(arr1, arr2, result, len1, len2);
            len = strlen(result);
            reverse(result, len);
            for (i = len; i >= 0; i--)
            {
                // 从后往前操作
                result[i + 1] = result[i];
            }
            result[0] = '-';
        }
        if (sign1 == 0 && sign2 == 0)
        {
            plus(arr1, arr2, result, len1, len2);
            len = strlen(result);
            reverse(result, len);
            for (i = len; i >= 0; i--)
            {
                // 从后往前操作
                result[i + 1] = result[i];
            }
            result[0] = '-';
        }
    }
    if (ch == '-')
    {
        if (sign1 == 1 && sign2 == 1)
        {
            if (flag)
            {
                sub(arr1, arr2, result, len1, len2);
                len = strlen(result);
                reverse(result, len);
                for (i = len; i >= 0; i--)
                {
                    // 从后往前操作
                    result[i + 1] = result[i];
                }
                result[0] = '-';
            }
            else
            {
                sub(arr1, arr2, result, len1, len2);
                len = strlen(result);
                reverse(result, len);
            }
        }
        if (sign1 == 1 && sign2 == 0)
        {
            plus(arr1, arr2, result, len1, len2);
            len = strlen(result);
            reverse(result, len);
        }
        if (sign1 == 0 && sign2 == 1)
        {
            plus(arr1, arr2, result, len1, len2);
            len = strlen(result);
            reverse(result, len);
            for (i = len; i >= 0; i--)
            {
                // 从后往前操作
                result[i + 1] = result[i];
            }
            result[0] = '-';
        }
        if (sign1 == 0 && sign2 == 0)
        {
            if(flag)
            {
                sub(arr1, arr2, result, len1, len2);
                len = strlen(result);
                reverse(result, len);
            }
            else
            {
                sub(arr1, arr2, result, len1, len2);
                len = strlen(result);
                reverse(result, len);
                for (i = len; i >= 0; i--)
                {
                    // 从后往前操作
                    result[i + 1] = result[i];
                }
                result[0] = '-';
            }
        }
    }
    len=strlen(result);
    deletezero(result,len);
    printf("%s", result);
    return 0;
}