'''
Author: zmlad
Date: 2025-12-09 15:34:15
'''
def solve_n_queens(n):
    """解决n皇后问题，返回解决方案数量"""
    if n <= 0:
        return 0
    
    count = 0  # 记录方案数
    
    # 初始化标记数组
    col_used = [False] * n
    diag1_used = [False] * (2 * n - 1)  # 主对角线：2n-1条
    diag2_used = [False] * (2 * n - 1)  # 副对角线：2n-1条
    
    def backtrack(row):
        nonlocal count
        # 递归终止条件：已经成功放置了n个皇后
        if row == n:
            count += 1
            return
        
        # 尝试在当前行的每一列放置皇后
        for col in range(n):
            # 计算当前格子的两条对角线索引
            diag1 = row - col + n - 1  # 主对角线索引，加n-1避免负数
            diag2 = row + col          # 副对角线索引
            
            # 检查当前位置是否合法
            if not col_used[col] and not diag1_used[diag1] and not diag2_used[diag2]:
                # 放置皇后，标记当前位置
                col_used[col] = True
                diag1_used[diag1] = True
                diag2_used[diag2] = True
                
                # 递归处理下一行
                backtrack(row + 1)
                
                # 回溯：取消标记
                col_used[col] = False
                diag1_used[diag1] = False
                diag2_used[diag2] = False
    
    # 从第0行开始递归求解
    backtrack(0)
    
    return count

def main():
    n = int(input())
    result = solve_n_queens(n)
    print(result)

if __name__ == "__main__":
    main()