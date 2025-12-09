/*
 * @Author: zmlad
 * @Date: 2025-12-09 16:15:23
 */
#include <iostream>
using namespace std;

int step = 0; // 全局变量，记录当前步数

void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        step++;
        cout << "[step " << step << "]  move plate " << n << "#  from " << from << " to " << to << endl;
        return;
    }
    // 将n-1个盘子从from移动到aux，借助to
    hanoi(n - 1, from, aux, to);
    // 移动第n个盘子从from到to
    step++;
    cout << "[step " << step << "]  move plate " << n << "#  from " << from << " to " << to << endl;
    // 将n-1个盘子从aux移动到to，借助from
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    cin >> n;
    
    // 调用递归函数，从a杆移动到c杆，借助b杆
    hanoi(n, 'a', 'c', 'b');
    
    // 输出总步数
    cout << step << endl;
    
    return 0;
}