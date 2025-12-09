/*
 * @Author: zmlad
 * @Date: 2025-12-09 16:15:13
 */
/*
思路：
1. 汉诺塔问题是一个经典的递归问题。要将n个盘子从A杆移动到C杆，可以分解为三个步骤：
   a. 将上面n-1个盘子从A借助C移动到B杆
   b. 将最大的盘子（第n个）从A直接移动到C杆
   c. 将n-1个盘子从B借助A移动到C杆
2. 递归终止条件：当只有一个盘子时，直接将它从起始杆移动到目标杆。
3. 使用全局变量step来记录当前步数，每移动一次就递增并输出。
4. 移动步数公式为2^n - 1，但我们通过递归输出每一步，最后step的值就是总步数。

实现细节：
- 递归函数hanoi(n, from, to, aux)：
   n: 当前要移动的盘子数
   from: 起始杆
   to: 目标杆
   aux: 辅助杆
- 当n==1时，直接输出移动步骤。
- 否则，先递归移动n-1个盘子到辅助杆，然后移动第n个盘子到目标杆，最后递归移动n-1个盘子到目标杆。
- 注意：题目要求输出格式中杆的名称是小写字母，且格式中空格要严格匹配。
*/

#include <stdio.h>

int step = 0; // 全局变量，记录当前步数

void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        step++;
        printf("[step %d]  move plate %d#  from %c to %c\n", step, n, from, to);
        return;
    }
    // 将n-1个盘子从from移动到aux，借助to
    hanoi(n - 1, from, aux, to);
    // 移动第n个盘子从from到to
    step++;
    printf("[step %d]  move plate %d#  from %c to %c\n", step, n, from, to);
    // 将n-1个盘子从aux移动到to，借助from
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    scanf("%d", &n);
    
    // 调用递归函数，从a杆移动到c杆，借助b杆
    hanoi(n, 'a', 'c', 'b');
    
    // 输出总步数
    printf("%d\n", step);
    
    return 0;
}