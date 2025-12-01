/*
 * @Author: zmlad
 * @Date: 2025-11-27 18:30:20
 */
/*
 * 程序目的：读取一个英文字母，切换其大小写后输出。
 * 实现方式：
 * 1. 包含输入输出流头文件 iostream 和字符处理头文件 cctype。
 * 2. 使用命名空间 std，避免重复书写 std:: 前缀。
 * 3. 定义主函数 main，作为程序入口点。
 * 4. 声明一个字符变量 c，用于存储输入的字母。
 * 5. 使用 cin 读取一个字符。
 * 6. 使用 cctype 中的 isupper 和 islower 函数判断字母的大小写：
 *    - 如果是大写字母，使用 tolower 转换为小写
 *    - 如果是小写字母，使用 toupper 转换为大写
 * 7. 使用 cout 输出转换后的字符。
 * 8. 返回0表示程序正常退出。
 */
#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char c;
    cin >> c;
    if (isupper(c)) {
        c = tolower(c);
    } else if (islower(c)) {
        c = toupper(c);
    }
    cout << c << endl;
    return 0;
}