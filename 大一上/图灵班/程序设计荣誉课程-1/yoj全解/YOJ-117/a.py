'''
Author: zmlad
Date: 2025-12-09 15:37:53
'''
def main():
    n = int(input())  # 读取层数
    
    # 创建二维数组，索引从1开始
    peaches = [[0] * (n + 1) for _ in range(n + 1)]
    
    # 读取桃子数
    for i in range(1, n + 1):
        values = list(map(int, input().split()))
        for j in range(1, i + 1):
            peaches[i][j] = values[j-1]
    
    # 动态规划：自底向上计算
    for i in range(n-1, 0, -1):
        for j in range(1, i + 1):
            # 当前位置能获得的最大桃子数 = 下一层左右两个位置中较大的一个 + 当前位置的桃子数
            peaches[i][j] += max(peaches[i+1][j], peaches[i+1][j+1])
    
    # 输出结果
    print(peaches[1][1])

if __name__ == "__main__":
    main()