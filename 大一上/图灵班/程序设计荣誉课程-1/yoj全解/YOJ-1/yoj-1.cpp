/*
 * @Author: zmlad
 * @Date: 2025-11-27 18:21:45
 */
/*
 * 程序目的：输出 "hello world" 字符串。
 * 实现方式：
 * 1. 包含输入输出流头文件 iostream，以使用 cout 对象进行输出。
 * 2. 使用命名空间 std，避免重复书写 std:: 前缀。
 * 3. 定义主函数 main，作为程序入口点。
 * 4. 使用 cout 和流插入运算符 << 输出字符串 "hello world"，并添加 endl 以换行并刷新输出缓冲区。
 * 5. 返回 0 表示程序正常退出。
 */
#include <iostream>
using namespace std;

int main() {
    cout << "hello world" << endl;
    return 0;
}