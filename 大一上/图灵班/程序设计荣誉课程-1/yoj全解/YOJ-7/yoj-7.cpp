/*
 * @Author: zmlad
 * @Date: 2025-11-27 18:35:08
 */
/*
 * 程序目的：读取三角形的三条边长，使用海伦公式计算面积，保留两位小数输出。
 * 实现方式：
 * 1. 包含输入输出流头文件 iostream、数学头文件 cmath 和格式化头文件 iomanip。
 * 2. 使用命名空间 std，避免重复书写 std:: 前缀。
 * 3. 定义主函数 main，作为程序入口点。
 * 4. 声明三个整数变量 a、b、c，用于存储三角形的三条边长。
 * 5. 使用 cin 读取三个整数，分别存入 a、b、c。
 * 6. 计算半周长 s = (a + b + c) / 2.0（使用2.0确保浮点数除法）。
 * 7. 使用海伦公式计算面积：area = sqrt(s * (s-a) * (s-b) * (s-c))。
 * 8. 使用 cout 和 fixed 与 setprecision(2) 来设置输出格式，保留两位小数。
 * 9. 返回0表示程序正常退出。
 */
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int a, b, c;
    double s, area;
    cin >> a >> b >> c;
    s = (a + b + c) / 2.0;
    area = sqrt(s * (s - a) * (s - b) * (s - c));
    cout << fixed << setprecision(2) << area << endl;
    return 0;
}