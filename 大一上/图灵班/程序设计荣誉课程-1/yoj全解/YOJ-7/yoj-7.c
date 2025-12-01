/*
 * @Author: zmlad
 * @Date: 2025-11-27 18:34:56
 */
/*
 * 程序目的：读取三角形的三条边长，使用海伦公式计算面积，保留两位小数输出。
 * 实现方式：
 * 1. 包含标准输入输出头文件 stdio.h 和数学头文件 math.h，以使用 scanf、printf 和 sqrt 函数。
 * 2. 定义主函数 main，作为程序入口点。
 * 3. 声明三个整数变量 a、b、c，用于存储三角形的三条边长。
 * 4. 使用 scanf 读取三个整数，分别存入 a、b、c。
 * 5. 计算半周长 s = (a + b + c) / 2.0（使用2.0确保浮点数除法）。
 * 6. 使用海伦公式计算面积：area = sqrt(s * (s-a) * (s-b) * (s-c))。
 * 7. 使用 printf 的格式化输出 %.2f 保留两位小数。
 * 8. 返回0表示程序正常退出。
 */
#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c;
    double s, area;
    scanf("%d %d %d", &a, &b, &c);
    s = (a + b + c) / 2.0;
    area = sqrt(s * (s - a) * (s - b) * (s - c));
    printf("%.2f\n", area);
    return 0;
}