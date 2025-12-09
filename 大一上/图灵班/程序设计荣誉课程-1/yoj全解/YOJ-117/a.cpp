/*
 * @Author: zmlad
 * @Date: 2025-12-09 15:37:43
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;  // 读取层数
    
    // 使用vector动态分配二维数组，索引从1开始
    vector<vector<int>> peaches(n + 1, vector<int>(n + 1, 0));
    
    // 读取桃子数
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> peaches[i][j];
        }
    }
    
    // 动态规划：自底向上计算
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            // 当前位置能获得的最大桃子数 = 下一层左右两个位置中较大的一个 + 当前位置的桃子数
            peaches[i][j] += max(peaches[i+1][j], peaches[i+1][j+1]);
        }
    }
    
    // 输出结果
    cout << peaches[1][1] << endl;
    
    return 0;
}