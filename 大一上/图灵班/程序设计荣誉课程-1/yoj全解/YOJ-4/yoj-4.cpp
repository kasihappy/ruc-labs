/*
 * @Author: zmlad
 * @Date: 2025-11-27 18:28:12
 */
/*
 * 程序目的：读取一段连续的字符串，然后直接输出。
 * 实现方式：
 * 1. 包含输入输出流头文件 iostream 和字符串头文件 string。
 * 2. 使用命名空间 std，避免重复书写 std:: 前缀。
 * 3. 定义主函数 main，作为程序入口点。
 * 4. 声明一个字符串变量 str。
 * 5. 使用 cin 读取字符串，它会读取连续的字符直到遇到空白字符。
 * 6. 使用 cout 输出读取的字符串。
 * 7. 返回0表示程序正常退出。
 */
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;
    cout << str << endl;
    return 0;
}