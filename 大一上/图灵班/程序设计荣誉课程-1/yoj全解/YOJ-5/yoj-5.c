/*
 * @Author: zmlad
 * @Date: 2025-11-27 18:29:34
 */
/*
 * 程序目的：读取一个英文字母，切换其大小写后输出。
 * 实现方式：
 * 1. 包含标准输入输出头文件 stdio.h 和字符处理头文件 ctype.h。
 * 2. 定义主函数 main，作为程序入口点。
 * 3. 声明一个字符变量 c，用于存储输入的字母。
 * 4. 使用 getchar 或 scanf 读取一个字符。
 * 5. 使用 ctype.h 中的 isupper 和 islower 函数判断字母的大小写：
 *    - 如果是大写字母，使用 tolower 转换为小写
 *    - 如果是小写字母，使用 toupper 转换为大写
 * 6. 输出转换后的字符。
 * 7. 返回0表示程序正常退出。
 */
#include <stdio.h>
#include <ctype.h>

int main() {
    char c;
    c = getchar();
    if (isupper(c)) {
        c = tolower(c);
    } else if (islower(c)) {
        c = toupper(c);
    }
    putchar(c);
    return 0;
}