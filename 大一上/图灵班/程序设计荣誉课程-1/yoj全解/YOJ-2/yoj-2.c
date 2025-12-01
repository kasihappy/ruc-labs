/*
 * @Author: zmlad
 * @Date: 2025-11-27 18:23:48
 */
/*
 * 程序目的：读取正整数n，输出n行"hello world"。
 * 实现方式：
 * 1. 包含标准输入输出头文件 stdio.h，以使用 scanf 和 printf 函数。
 * 2. 定义主函数 main，作为程序入口点。
 * 3. 声明整数变量n，用于存储输入的数值。
 * 4. 使用 scanf 读取输入的整数n。
 * 5. 使用 for 循环，从0到n-1循环n次。
 * 6. 在循环体内，每次使用 printf 输出"hello world"并换行。
 * 7. 返回0表示程序正常退出。
 */
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("hello world\n");
    }
    return 0;
}