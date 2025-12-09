'''
Author: zmlad
Date: 2025-12-09 16:13:20
'''
def solve_maze():
    # 读取迷宫大小
    n, m = map(int, input().split())
    
    # 读取迷宫地图
    maze = []
    for _ in range(n):
        row = list(map(int, input().split()))
        maze.append(row)
    
    # 创建访问标记数组
    visited = [[False] * m for _ in range(n)]
    
    # 方向数组：上、下、左、右
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    
    def dfs(x, y):
        """深度优先搜索"""
        # 如果到达终点，返回True
        if x == n - 1 and y == m - 1:
            return True
        
        # 标记当前位置已访问
        visited[x][y] = True
        
        # 尝试四个方向
        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            
            # 检查新位置是否在迷宫范围内、是道路(1)、且未访问过
            if 0 <= nx < n and 0 <= ny < m and maze[nx][ny] == 1 and not visited[nx][ny]:
                # 递归探索该方向
                if dfs(nx, ny):
                    return True  # 如果找到路径，直接返回True
        
        # 所有方向都无法到达终点
        return False
    
    # 检查起点是否为通路
    if maze[0][0] == 0:
        print("NO")
        return
    
    # 从起点(0,0)开始深度优先搜索
    if dfs(0, 0):
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    solve_maze()