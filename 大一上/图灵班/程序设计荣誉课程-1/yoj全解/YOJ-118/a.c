/*
 * @Author: zmlad
 * @Date: 2025-12-09 15:42:41
 */
#include <stdio.h>

/*
思路：
使用矩阵快速幂计算Fibonacci数列的第n项，并输出后四位（即模10000的结果）。
由于n可以很大（0 <= N <= 1e9），直接递推会超时，因此利用矩阵乘法和快速幂来加速。

Fibonacci数列的矩阵表示：
设矩阵 M = [[1, 1], [1, 0]]，则 M^n = [[F_{n+1}, F_n], [F_n, F_{n-1}]]。
因此，计算M的n次幂后，取左下角元素即为F[n]。

步骤：
1. 定义2x2矩阵结构，以及矩阵乘法和矩阵快速幂函数。
2. 读取整数n。
3. 若n=0，直接输出0。
4. 否则，计算矩阵M的n次幂（快速幂），结果矩阵的matrix[1][0]即为F[n]（因为矩阵下标从0开始）。
5. 输出结果模10000（即后四位）。

注意：矩阵乘法中每次运算都要取模10000，避免溢出。
*/

#define MOD 10000

// 定义2x2矩阵结构
typedef struct {
    int m[2][2];
} Matrix;

// 矩阵乘法：计算a*b，结果模MOD
Matrix multiply(Matrix a, Matrix b) {
    Matrix result;
    result.m[0][0] = (a.m[0][0] * b.m[0][0] + a.m[0][1] * b.m[1][0]) % MOD;
    result.m[0][1] = (a.m[0][0] * b.m[0][1] + a.m[0][1] * b.m[1][1]) % MOD;
    result.m[1][0] = (a.m[1][0] * b.m[0][0] + a.m[1][1] * b.m[1][0]) % MOD;
    result.m[1][1] = (a.m[1][0] * b.m[0][1] + a.m[1][1] * b.m[1][1]) % MOD;
    return result;
}

// 矩阵快速幂：计算矩阵base的exp次幂
Matrix matrix_pow(Matrix base, int exp) {
    Matrix result = {{{1, 0}, {0, 1}}}; // 单位矩阵
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
    scanf("%d", &n);

    if (n == 0) {
        printf("0\n");
        return 0;
    }

    // 定义矩阵 M = [[1, 1], [1, 0]]
    Matrix M = {{{1, 1}, {1, 0}}};
    
    // 计算 M^n
    Matrix result = matrix_pow(M, n);
    
    // 输出 F[n] 的后四位
    printf("%d\n", result.m[1][0] % MOD);
    
    return 0;
}