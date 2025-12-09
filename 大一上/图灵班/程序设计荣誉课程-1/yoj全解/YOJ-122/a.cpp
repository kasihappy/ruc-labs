/*
 * @Author: zmlad
 * @Date: 2025-12-09 16:13:11
 */
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> maze;          // 迷宫
vector<vector<bool>> visited;      // 访问标记

// 方向数组：上、下、左、右
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 深度优先搜索函数
bool dfs(int x, int y) {
    // 如果到达终点，返回true
    if (x == n - 1 && y == m - 1) {
        return true;
    }
    
    // 标记当前位置已访问
    visited[x][y] = true;
    
    // 尝试四个方向
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        // 检查新位置是否在迷宫范围内、是道路(1)、且未访问过
        if (nx >= 0 && nx < n && ny >= 0 && ny < m 
            && maze[nx][ny] == 1 && !visited[nx][ny]) {
            // 递归探索该方向
            if (dfs(nx, ny)) {
                return true;  // 如果找到路径，直接返回true
            }
        }
    }
    
    // 所有方向都无法到达终点
    return false;
}

int main() {
    // 读取迷宫大小
    cin >> n >> m;
    
    // 调整容器大小
    maze.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m, false));
    
    // 读取迷宫地图
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }
    
    // 检查起点是否为通路
    if (maze[0][0] == 0) {
        cout << "NO" << endl;
        return 0;
    }
    
    // 从起点(0,0)开始深度优先搜索（注意C++通常使用0-based索引）
    if (dfs(0, 0)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}