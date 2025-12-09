/*
 * @Author: zmlad
 * @Date: 2025-12-09 16:19:38
 */
/*
思路：
1. 这是一个滑雪问题，需要在给定的高度矩阵中找到最长的递减路径（每次只能向上下左右四个方向移动，且高度必须递减）。
2. 使用记忆化搜索（DFS+记忆化数组）来解决问题，避免重复计算。
3. 定义dp[i][j]表示从点(i,j)开始的最长滑坡长度。
4. 对于每个点(i,j)，递归地探索其四个方向，如果相邻点的高度小于当前点的高度，则可以从当前点滑向相邻点，所以dp[i][j] = max(dp[i][j], 1 + dfs(ni, nj))。
5. 递归终止条件：当没有更低的位置可走时，返回1（只包含自己）。
6. 使用记忆化数组dp记录已经计算过的点，避免重复计算。
7. 最终答案就是所有dp[i][j]中的最大值。

实现细节：
- 定义方向数组dx,dy表示上下左右四个方向。
- dfs函数：如果dp[i][j]已经计算过，直接返回；否则初始化为1，然后向四个方向递归探索，更新dp[i][j]。
- 注意边界检查，确保探索的点在矩阵范围内。
- 由于矩阵大小最大为50x50，所以递归深度不会太大，可以使用递归。
*/

#include <stdio.h>
#include <string.h>

#define MAX_R 55
#define MAX_C 55

int R, C;
int height[MAX_R][MAX_C];
int dp[MAX_R][MAX_C];  // 记忆化数组，存储从(i,j)开始的最长滑坡长度

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
            int nextLen = dfs(nx, ny) + 1;
            if (nextLen > dp[x][y]) {
                dp[x][y] = nextLen;
            }
        }
    }
    
    return dp[x][y];
}

int main() {
    // 读取输入
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf("%d", &height[i][j]);
        }
    }
    
    // 初始化dp数组为0（表示未计算）
    memset(dp, 0, sizeof(dp));
    
    // 对每个点进行记忆化搜索，并记录最大值
    int maxLen = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int len = dfs(i, j);
            if (len > maxLen) {
                maxLen = len;
            }
        }
    }
    
    // 输出最长滑坡长度
    printf("%d\n", maxLen);
    
    return 0;
}