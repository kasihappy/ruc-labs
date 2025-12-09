'''
Author: zmlad
Date: 2025-12-09 14:12:05
'''
n = int(input())

# 初始化矩阵，注意Python下标从0开始，所以需要调整逻辑
matrix = [[0] * (n + 2) for _ in range(n + 2)]
count = 1

matrix[1][1] = count
count += 1
i, j = 1, 1  # i行，j列

while count <= n * n:
    # 1. 第一行向右走，只走一格
    j += 1
    matrix[i][j] = count
    count += 1

    # 2. 从第一行向下走，比上一列多走一格
    while matrix[i][j - 1] != 0:
        i += 1
        matrix[i][j] = count
        count += 1

    # 3. 向左走，走到头
    while j > 1:
        j -= 1
        matrix[i][j] = count
        count += 1

    # 4. 第一列向下走，只走一格
    i += 1
    matrix[i][j] = count
    count += 1

    # 5. 向右走，比上一行多走一格
    while matrix[i - 1][j] != 0:
        j += 1
        matrix[i][j] = count
        count += 1

    # 6. 向上走，走到头
    while i > 1:
        i -= 1
        matrix[i][j] = count
        count += 1

# 输出矩阵
for i in range(1, n + 1):
    for j in range(1, n + 1):
        print(matrix[i][j], end=" ")
    print()