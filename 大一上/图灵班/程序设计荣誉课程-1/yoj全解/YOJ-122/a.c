/*
 * @Author: zmlad
 * @Date: 2025-12-09 16:11:17
 */
/*
思路：
1. 这是一个迷宫寻路问题，需要判断从起点(1,1)到终点(n,m)是否存在一条由1组成的路径
2. 只能横向和纵向移动（上下左右四个方向），不能斜向移动
3. 使用深度优先搜索(DFS)进行路径探索
4. 使用visited数组记录已访问的位置，避免重复访问和走回头路
5. 递归终止条件：到达终点(n,m)则返回true，表示找到路径
6. 递归过程：从当前位置向四个方向探索，如果下一个位置在迷宫范围内、值为1且未访问过，则递归探索该方向
7. 如果所有方向都无法到达终点，则返回false
8. 注意：坐标从1开始，数组下标也从1开始存储

实现细节：
- 定义方向数组dx,dy表示上下左右四个方向的坐标变化
- 使用全局变量n,m表示迷宫大小，map存储迷宫，visited记录访问状态
- DFS函数参数为当前坐标(x,y)，返回bool值表示是否找到路径
- 主函数中读取输入，初始化visited数组，从起点开始DFS，根据结果输出YES或NO
*/

#include <stdio.h>
#include <stdbool.h>

int n, m;
int map[10][10];        // 迷宫，下标从1开始
bool visited[10][10];   // 访问标记数组

// 方向数组：上、下、左、右
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 深度优先搜索函数
bool dfs(int x, int y) {
    // 如果到达终点，返回true
    if (x == n && y == m) {
        return true;
    }
    
    // 标记当前位置已访问
    visited[x][y] = true;
    
    // 尝试四个方向
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        // 检查新位置是否在迷宫范围内、是道路(1)、且未访问过
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m 
            && map[nx][ny] == 1 && !visited[nx][ny]) {
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
    scanf("%d %d", &n, &m);
    
    // 读取迷宫地图
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    
    // 初始化visited数组为未访问状态
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            visited[i][j] = false;
        }
    }
    
    // 从起点(1,1)开始深度优先搜索
    // 题目保证起点和终点都是1，所以不需要额外检查起点是否为1
    if (dfs(1, 1)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}