/*
 * @Author: zmlad
 * @Date: 2025-11-27 18:26:41
 */
/*
 * 程序目的：读取两个整数，比较大小后输出较大的数。
 * 实现方式：
 * 1. 包含输入输出流头文件 iostream，以使用 cin 和 cout。
 * 2. 使用命名空间 std，避免重复书写 std:: 前缀。
 * 3. 定义主函数 main，作为程序入口点。
 * 4. 声明两个整数变量a和b，用于存储输入的两个整数。
 * 5. 使用 cin 读取两个整数，分别存入a和b。
 * 6. 使用条件运算符（三元运算符）比较a和b的大小：
 *    - 如果a大于b，则输出a
 *    - 否则输出b
 * 7. 返回0表示程序正常退出。
 */
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << (a > b ? a : b) << endl;
    return 0;
}