/*
 * @Author: zmlad
 * @Date: 2025-12-09 15:31:55
 */
#include <stdio.h>

// 全局变量，用于记录方案数
int count = 0;

/**
 * 思路：
 * 1. n皇后问题的经典解法是使用回溯法（深度优先搜索）
 * 2. 由于皇后不能在同一行、同一列或同一对角线上，我们可以逐行放置皇后
 * 3. 使用三个数组来标记列、主对角线（左上到右下）、副对角线（右上到左下）是否已被占用
 * 4. 主对角线规律：row - col 的值相同的格子在同一主对角线上
 * 5. 副对角线规律：row + col 的值相同的格子在同一副对角线上
 * 6. 递归地在每一行尝试放置皇后，如果当前位置合法则放置并标记，然后递归处理下一行
 * 7. 当成功放置n个皇后时，方案数加1
 * 8. 回溯时取消标记，尝试同一行的下一个位置
 */

// 函数声明
void solve(int row, int n, int col_used[], int diag1_used[], int diag2_used[]);

int main() {
    int n;
    scanf("%d", &n);  // 读取棋盘大小
    
    // 初始化标记数组
    // 列标记数组，大小为n
    int col_used[13] = {0};  // n<13，所以分配13个元素足够
    
    // 主对角线标记数组，大小为2*n-1
    int diag1_used[25] = {0};  // 2*12-1=23，分配25个元素足够
    
    // 副对角线标记数组，大小为2*n-1
    int diag2_used[25] = {0};
    
    // 从第0行开始递归求解
    solve(0, n, col_used, diag1_used, diag2_used);
    
    // 输出结果
    printf("%d\n", count);
    
    return 0;
}

// 递归求解n皇后问题
void solve(int row, int n, int col_used[], int diag1_used[], int diag2_used[]) {
    // 递归终止条件：已经成功放置了n个皇后
    if (row == n) {
        count++;  // 找到一个有效方案
        return;
    }
    
    // 尝试在当前行的每一列放置皇后
    for (int col = 0; col < n; col++) {
        // 计算当前格子的两条对角线索引
        int diag1 = row - col + n - 1;  // 主对角线索引，加n-1避免负数
        int diag2 = row + col;          // 副对角线索引
        
        // 检查当前位置是否合法（列、主对角线、副对角线都没有被占用）
        if (!col_used[col] && !diag1_used[diag1] && !diag2_used[diag2]) {
            // 放置皇后，标记当前位置
            col_used[col] = 1;
            diag1_used[diag1] = 1;
            diag2_used[diag2] = 1;
            
            // 递归处理下一行
            solve(row + 1, n, col_used, diag1_used, diag2_used);
            
            // 回溯：取消标记，尝试当前行的下一个位置
            col_used[col] = 0;
            diag1_used[diag1] = 0;
            diag2_used[diag2] = 0;
        }
    }
}