/*
 * @Author: zmlad
 * @Date: 2025-11-27 18:42:12
 */
/*
 * 程序目的：读取华氏温度，转换为摄氏温度，保留两位小数输出。
 * 实现方式：
 * 1. 包含输入输出流头文件 iostream 和格式化头文件 iomanip。
 * 2. 使用命名空间 std，避免重复书写 std:: 前缀。
 * 3. 定义主函数 main，作为程序入口点。
 * 4. 声明整数变量 fahrenheit 存储华氏温度，浮点数变量 celsius 存储摄氏温度。
 * 5. 使用 cin 读取华氏温度。
 * 6. 使用转换公式 celsius = (fahrenheit - 32) * 5.0 / 9.0 进行计算。
 *    注意：使用 5.0 和 9.0 确保进行浮点数运算，避免整数除法截断。
 * 7. 使用 cout 和 fixed 与 setprecision(2) 来设置输出格式，保留两位小数。
 * 8. 返回0表示程序正常退出。
 */
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int fahrenheit;
    double celsius;
    cin >> fahrenheit;
    celsius = (fahrenheit - 32) * 5.0 / 9.0;
    cout << fixed << setprecision(2) << celsius << endl;
    return 0;
}