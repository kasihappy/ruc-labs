'''
Author: zmlad
Date: 2025-12-09 16:22:06
'''
def solve_skiing():
    R, C = map(int, input().split())
    height = [list(map(int, input().split())) for _ in range(R)]
    
    # 初始化dp数组为0
    dp = [[0] * C for _ in range(R)]
    
    # 方向数组：上、下、左、右
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    
    def dfs(x, y):
        """记忆化搜索函数"""
        # 如果已经计算过，直接返回
        if dp[x][y] != 0:
            return dp[x][y]
        
        # 初始长度为1（自身）
        dp[x][y] = 1
        
        # 探索四个方向
        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            
            # 检查边界和高度递减条件
            if 0 <= nx < R and 0 <= ny < C and height[nx][ny] < height[x][y]:
                dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1)
        
        return dp[x][y]
    
    # 对每个点进行记忆化搜索，并记录最大值
    max_len = 0
    for i in range(R):
        for j in range(C):
            max_len = max(max_len, dfs(i, j))
    
    print(max_len)

if __name__ == "__main__":
    solve_skiing()