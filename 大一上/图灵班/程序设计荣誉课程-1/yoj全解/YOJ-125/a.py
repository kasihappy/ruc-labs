'''
Author: zmlad
Date: 2025-12-09 16:31:51
'''
import itertools

def determinant(matrix):
    """计算行列式的值"""
    n = len(matrix)
    if n == 1:
        return matrix[0][0]
    if n == 2:
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]
    
    det = 0
    
    # 生成0到n-1的所有排列
    for perm in itertools.permutations(range(n)):
        # 计算当前排列的乘积
        product = 1
        for i in range(n):
            product *= matrix[i][perm[i]]
        
        # 计算逆序数
        inv_cnt = 0
        for i in range(n):
            for j in range(i + 1, n):
                if perm[i] > perm[j]:
                    inv_cnt += 1
        
        # 根据逆序数的奇偶性确定符号
        if inv_cnt % 2 == 0:
            det += product
        else:
            det -= product
    
    return det

def main():
    n = int(input())
    matrix = []
    for _ in range(n):
        row = list(map(int, input().split()))
        matrix.append(row)
    
    result = determinant(matrix)
    print(result)

if __name__ == "__main__":
    main()