/*
 * @Author: zmlad
 * @Date: 2025-11-27 18:36:41
 */
/*
 * 程序目的：读取百分制成绩，根据对照表输出对应的学分绩点。
 * 实现方式：
 * 1. 包含标准输入输出头文件 stdio.h，以使用 scanf 和 printf 函数。
 * 2. 定义主函数 main，作为程序入口点。
 * 3. 声明整数变量 score 存储输入成绩，浮点数变量 grade_point 存储绩点。
 * 4. 使用 scanf 读取成绩 score。
 * 5. 使用 if-else if 链根据成绩范围设置 grade_point 的值。
 * 6. 输出时，如果 grade_point 为 0，输出整数 0；否则输出保留一位小数的浮点数。
 * 7. 返回 0 表示程序正常退出。
 */
#include <stdio.h>

int main() {
    int score;
    double grade_point;
    scanf("%d", &score);
    
    if (score >= 90 && score <= 100) {
        grade_point = 4.0;
    } else if (score >= 86 && score <= 89) {
        grade_point = 3.7;
    } else if (score >= 83 && score <= 85) {
        grade_point = 3.3;
    } else if (score >= 80 && score <= 82) {
        grade_point = 3.0;
    } else if (score >= 76 && score <= 79) {
        grade_point = 2.7;
    } else if (score >= 73 && score <= 75) {
        grade_point = 2.3;
    } else if (score >= 70 && score <= 72) {
        grade_point = 2.0;
    } else if (score >= 66 && score <= 69) {
        grade_point = 1.7;
    } else if (score >= 63 && score <= 65) {
        grade_point = 1.3;
    } else if (score >= 60 && score <= 62) {
        grade_point = 1.0;
    } else {
        grade_point = 0.0;
    }
    
    if (grade_point == 0.0) {
        printf("0\n");
    } else {
        printf("%.1f\n", grade_point);
    }
    return 0;
}