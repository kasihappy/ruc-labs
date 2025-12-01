/*
 * @Author: zmlad
 * @Date: 2025-11-27 18:24:00
 */
/*
 * 程序目的：读取正整数n，输出n行"hello world"。
 * 实现方式：
 * 1. 包含输入输出流头文件 iostream，以使用 cin 和 cout。
 * 2. 使用命名空间 std，避免重复书写 std:: 前缀。
 * 3. 定义主函数 main，作为程序入口点。
 * 4. 声明整数变量n，用于存储输入的数值。
 * 5. 使用 cin 读取输入的整数n。
 * 6. 使用 for 循环，从0到n-1循环n次。
 * 7. 在循环体内，每次使用 cout 输出"hello world"并换行。
 * 8. 返回0表示程序正常退出。
 */
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "hello world" << endl;
    }
    return 0;
}