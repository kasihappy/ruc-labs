/*
 * @Author: zmlad
 * @Date: 2025-12-09 16:21:43
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int R, C;
vector<vector<int>> height;
vector<vector<int>> dp;  // 记忆化数组

// 方向数组：上、下、左、右
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 记忆化搜索函数
int dfs(int x, int y) {
    // 如果已经计算过，直接返回
    if (dp[x][y] != 0) {
        return dp[x][y];
    }
    
    // 初始长度为1（自身）
    dp[x][y] = 1;
    
    // 探索四个方向
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        // 检查边界和高度递减条件
        if (nx >= 0 && nx < R && ny >= 0 && ny < C && height[nx][ny] < height[x][y]) {
            dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
        }
    }
    
    return dp[x][y];
}

int main() {
    // 读取输入
    cin >> R >> C;
    
    height.resize(R, vector<int>(C));
    dp.resize(R, vector<int>(C, 0));  // 初始化为0
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> height[i][j];
        }
    }
    
    // 对每个点进行记忆化搜索，并记录最大值
    int maxLen = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            maxLen = max(maxLen, dfs(i, j));
        }
    }
    
    // 输出最长滑坡长度
    cout << maxLen << endl;
    
    return 0;
}