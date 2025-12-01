/*
 * @Author: zmlad
 * @Date: 2025-11-27 18:31:36
 */
/*
 * 程序目的：读取两个浮点数，计算它们的和，四舍五入保留两位小数输出。
 * 实现方式：
 * 1. 包含标准输入输出头文件 stdio.h，以使用 scanf 和 printf 函数。
 * 2. 定义主函数 main，作为程序入口点。
 * 3. 声明两个双精度浮点数变量 a 和 b，用于存储输入的两个浮点数。
 * 4. 使用 scanf 读取两个浮点数，分别存入 a 和 b。
 * 5. 计算 a 和 b 的和，存储在变量 sum 中。
 * 6. 使用 printf 的格式化输出，%.2f 表示保留两位小数，会自动进行四舍五入。
 * 7. 返回0表示程序正常退出。
 */
#include <stdio.h>

int main() {
    double a, b, sum;
    scanf("%lf %lf", &a, &b);
    sum = a + b;
    printf("%.2f\n", sum);
    return 0;
}