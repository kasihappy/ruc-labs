/*
 * @Author: zmlad
 * @Date: 2025-11-27 18:39:18
 */
/*
 * 程序目的：读取三行不同格式的输入，然后按照指定格式输出。
 * 实现方式：
 * 1. 包含输入输出流头文件 iostream 和格式化头文件 iomanip。
 * 2. 使用命名空间 std，避免重复书写 std:: 前缀。
 * 3. 定义主函数 main，作为程序入口点。
 * 4. 第一行：使用 getline 读取整行，然后使用字符串流处理两个整数。
 * 5. 第二行：使用 cin 读取两个浮点数。
 * 6. 第三行：使用 getline 读取整行，保留空格格式。
 * 7. 输出时，第一行原样输出读取的字符串。
 * 8. 输出时，第二行输出两个浮点数，使用 fixed 和 setprecision(1) 保留一位小数。
 * 9. 输出时，第三行原样输出读取的字符串。
 * 10. 返回0表示程序正常退出。
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string line1, line3;
    double x, y;
    
    // 读取第一行：两个整数，中间用逗号隔开
    getline(cin, line1);
    
    // 读取第二行：两个浮点数，中间用空格隔开
    cin >> x >> y;
    
    // 读取第三行：两个字母，每个字母前面有空格，中间有逗号
    cin.ignore(); // 忽略第二行后的换行符
    getline(cin, line3);
    
    // 输出第一行：原样输出
    cout << line1 << endl;
    
    // 输出第二行：浮点数保留一位小数
    cout << fixed << setprecision(1) << x << " " << y << endl;
    
    // 输出第三行：原样输出
    cout << line3 << endl;
    
    return 0;
}