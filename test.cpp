#include <stdio.h>
#include <stdint.h>

// 详细的二进制打印函数
void print_binary_detailed(int32_t num) {
    printf("十进制: %d\n", num);
    printf("十六进制: 0x%08X\n", (unsigned int)num);
    printf("二进制: ");
    
    // 打印32位二进制
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0) printf(" ");  // 每4位空格
    }
    printf("\n");
    
    // 标记符号位
    printf("         ↑\n");
    printf("         符号位(第31位): %d\n", (num >> 31) & 1);
}

// 手动演示补码计算过程
void demonstrate_twos_complement(int8_t num) {
    // 使用8位简化演示
    printf("\n=== %d 的8位补码计算过程 ===\n", num);
    
    if (num < 0) {
        int8_t abs_num = -num;  // 绝对值
        
        printf("1. 绝对值 %d 的二进制: ", abs_num);
        for (int i = 7; i >= 0; i--) {
            printf("%d", (abs_num >> i) & 1);
        }
        printf("\n");
        
        printf("2. 取反操作: \n");
        int8_t inverted = ~abs_num;
        printf("   取反后: ");
        for (int i = 7; i >= 0; i--) {
            printf("%d", (inverted >> i) & 1);
        }
        printf(" (十进制: %d)\n", inverted);
        
        printf("3. 加1操作: \n");
        int8_t complement = inverted + 1;
        printf("   加1后: ");
        for (int i = 7; i >= 0; i--) {
            printf("%d", (complement >> i) & 1);
        }
        printf(" (十进制: %d)\n", complement);
        
        printf("4. 验证: 直接输出 %d 的二进制: ", num);
        for (int i = 7; i >= 0; i--) {
            printf("%d", (num >> i) & 1);
        }
        printf("\n");
    }
}

// 统计1的个数并详细分析
int analyze_ones(int32_t num) {
    printf("\n");
    print_binary_detailed(num);
    
    int count = 0;
    uint32_t unum = (uint32_t)num;
    uint32_t temp = unum;
    
    printf("\n1的位位置: ");
    int first = 1;
    for (int i = 31; i >= 0; i--) {
        if ((unum >> i) & 1) {
            if (!first) printf(", ");
            printf("%d", i);
            first = 0;
        }
    }
    if (first) printf("无");
    printf("\n");
    
    // 使用Kernighan算法
    printf("\nKernighan算法过程:\n");
    int step = 1;
    while (temp) {
        printf("步骤%d: 当前值: 0x%08X, 1的个数: %d\n", 
               step, temp, count);
        temp &= (temp - 1);
        count++;
        step++;
    }
    printf("最终结果: %d 个1\n", count);
    
    return count;
}

int main() {
    printf("=== 负数补码详细分析 ===\n");
    
    // 测试几个关键数字
    int32_t test_numbers[] = {5, -5, 12, -12, -1, 0, -2147483648};
    int size = sizeof(test_numbers) / sizeof(test_numbers[0]);
    
    for (int i = 0; i < size; i++) {
        analyze_ones(test_numbers[i]);
        printf("\n%s\n", "=");
    }
    
    // 8位补码演示（更易理解）
    demonstrate_twos_complement(-5);
    demonstrate_twos_complement(-1);
    
    return 0;
}