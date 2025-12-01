/*
 * @Author: zmlad
 * @Date: 2025-11-27 18:31:50
 */
/*
 * 程序目的：读取两个浮点数，计算它们的和，四舍五入保留两位小数输出。
 * 实现方式：
 * 1. 包含输入输出流头文件 iostream 和格式化头文件 iomanip。
 * 2. 使用命名空间 std，避免重复书写 std:: 前缀。
 * 3. 定义主函数 main，作为程序入口点。
 * 4. 声明两个双精度浮点数变量 a 和 b，用于存储输入的两个浮点数。
 * 5. 使用 cin 读取两个浮点数，分别存入 a 和 b。
 * 6. 计算 a 和 b 的和，存储在变量 sum 中。
 * 7. 使用 cout 和 fixed 与 setprecision(2) 来设置输出格式，保留两位小数并四舍五入。
 * 8. 返回0表示程序正常退出。
 */
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double a, b, sum;
    cin >> a >> b;
    sum = a + b;
    cout << fixed << setprecision(2) << sum << endl;
    return 0;
}