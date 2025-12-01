/*
 * @Author: zmlad
 * @Date: 2025-11-27 18:42:00
 */
/*
 * 程序目的：读取华氏温度，转换为摄氏温度，保留两位小数输出。
 * 实现方式：
 * 1. 包含标准输入输出头文件 stdio.h，以使用 scanf 和 printf 函数。
 * 2. 定义主函数 main，作为程序入口点。
 * 3. 声明整数变量 fahrenheit 存储华氏温度，浮点数变量 celsius 存储摄氏温度。
 * 4. 使用 scanf 读取华氏温度。
 * 5. 使用转换公式 celsius = (fahrenheit - 32) * 5.0 / 9.0 进行计算。
 *    注意：使用 5.0 和 9.0 确保进行浮点数运算，避免整数除法截断。
 * 6. 使用 printf 的格式化输出 %.2f 保留两位小数。
 * 7. 返回0表示程序正常退出。
 */
#include <stdio.h>

int main() {
    int fahrenheit;
    double celsius;
    scanf("%d", &fahrenheit);
    celsius = (fahrenheit - 32) * 5.0 / 9.0;
    printf("%.2f\n", celsius);
    return 0;
}