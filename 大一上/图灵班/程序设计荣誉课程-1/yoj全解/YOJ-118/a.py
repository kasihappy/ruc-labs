'''
Author: zmlad
Date: 2025-12-09 15:42:37
'''
MOD = 10000

class Matrix:
    """2x2矩阵类"""
    def __init__(self, a=0, b=0, c=0, d=0):
        self.m = [[a, b], [c, d]]
    
    def multiply(self, other):
        """矩阵乘法"""
        a = (self.m[0][0] * other.m[0][0] + self.m[0][1] * other.m[1][0]) % MOD
        b = (self.m[0][0] * other.m[0][1] + self.m[0][1] * other.m[1][1]) % MOD
        c = (self.m[1][0] * other.m[0][0] + self.m[1][1] * other.m[1][0]) % MOD
        d = (self.m[1][0] * other.m[0][1] + self.m[1][1] * other.m[1][1]) % MOD
        return Matrix(a, b, c, d)
    
    def pow(self, exp):
        """矩阵快速幂"""
        result = Matrix(1, 0, 0, 1)  # 单位矩阵
        base = self
        while exp > 0:
            if exp & 1:
                result = result.multiply(base)
            base = base.multiply(base)
            exp >>= 1
        return result

def fibonacci_mod(n):
    """计算Fibonacci数列第n项模10000"""
    if n == 0:
        return 0
    
    M = Matrix(1, 1, 1, 0)
    result = M.pow(n)
    return result.m[1][0] % MOD

def main():
    while True:
        try:
            n = int(input())
            if n == -1:
                break
            print(fibonacci_mod(n))
        except EOFError:
            break

if __name__ == "__main__":
    main()