/*
 * @Author: zmlad
 * @Date: 2025-12-09 15:44:29
 */
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 10000;

// 定义2x2矩阵
struct Matrix {
    int m[2][2];
    
    // 构造函数，初始化矩阵
    Matrix(int a = 0, int b = 0, int c = 0, int d = 0) {
        m[0][0] = a; m[0][1] = b;
        m[1][0] = c; m[1][1] = d;
    }
};

// 矩阵乘法：计算a*b，结果模MOD
Matrix multiply(const Matrix& a, const Matrix& b) {
    Matrix result;
    result.m[0][0] = (a.m[0][0] * b.m[0][0] + a.m[0][1] * b.m[1][0]) % MOD;
    result.m[0][1] = (a.m[0][0] * b.m[0][1] + a.m[0][1] * b.m[1][1]) % MOD;
    result.m[1][0] = (a.m[1][0] * b.m[0][0] + a.m[1][1] * b.m[1][0]) % MOD;
    result.m[1][1] = (a.m[1][0] * b.m[0][1] + a.m[1][1] * b.m[1][1]) % MOD;
    return result;
}

// 矩阵快速幂：计算矩阵base的exp次幂
Matrix matrix_pow(Matrix base, int exp) {
    Matrix result(1, 0, 0, 1); // 单位矩阵
    while (exp > 0) {
        if (exp & 1) { // 当前位为1
            result = multiply(result, base);
        }
        base = multiply(base, base); // 底数平方
        exp >>= 1; // 指数右移一位
    }
    return result;
}

int main() {
    int n;
    
    while (cin >> n && n != -1) {
        if (n == 0) {
            cout << 0 << endl;
            continue;
        }
        
        // 定义矩阵 M = [[1, 1], [1, 0]]
        Matrix M(1, 1, 1, 0);
        
        // 计算 M^n
        Matrix result = matrix_pow(M, n);
        
        // 输出 F[n] 的后四位
        cout << result.m[1][0] % MOD << endl;
    }
    
    return 0;
}