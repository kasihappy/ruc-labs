/*
 * @Author: zmlad
 * @Date: 2025-12-09 15:33:57
 */
#include <iostream>
#include <vector>
using namespace std;

class NQueens {
private:
    int count; // 记录方案数
    
public:
    NQueens() : count(0) {}
    
    // 递归求解n皇后问题
    void solve(int row, int n, vector<bool>& col_used, 
               vector<bool>& diag1_used, vector<bool>& diag2_used) {
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
            
            // 检查当前位置是否合法
            if (!col_used[col] && !diag1_used[diag1] && !diag2_used[diag2]) {
                // 放置皇后，标记当前位置
                col_used[col] = true;
                diag1_used[diag1] = true;
                diag2_used[diag2] = true;
                
                // 递归处理下一行
                solve(row + 1, n, col_used, diag1_used, diag2_used);
                
                // 回溯：取消标记
                col_used[col] = false;
                diag1_used[diag1] = false;
                diag2_used[diag2] = false;
            }
        }
    }
    
    // 计算n皇后问题的解决方案数
    int totalNQueens(int n) {
        if (n <= 0) return 0;
        
        // 重置计数器
        count = 0;
        
        // 初始化标记数组
        vector<bool> col_used(n, false);
        vector<bool> diag1_used(2 * n - 1, false);  // 主对角线：2n-1条
        vector<bool> diag2_used(2 * n - 1, false);  // 副对角线：2n-1条
        
        // 从第0行开始递归求解
        solve(0, n, col_used, diag1_used, diag2_used);
        
        return count;
    }
};

int main() {
    int n;
    cin >> n;  // 读取棋盘大小
    
    NQueens solver;
    int result = solver.totalNQueens(n);
    
    // 输出结果
    cout << result << endl;
    
    return 0;
}