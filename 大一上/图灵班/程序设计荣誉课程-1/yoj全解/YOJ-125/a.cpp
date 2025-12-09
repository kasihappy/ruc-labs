/*
 * @Author: zmlad
 * @Date: 2025-12-09 16:31:37
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

long long determinant(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n == 1) return matrix[0][0];
    if (n == 2) return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    
    long long det = 0;
    
    // 生成1到n的所有排列
    vector<int> perm(n);
    for (int i = 0; i < n; i++) perm[i] = i;
    
    do {
        // 计算当前排列的乘积
        long long product = 1;
        for (int i = 0; i < n; i++) {
            product *= matrix[i][perm[i]];
        }
        
        // 计算逆序数
        int inv_cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (perm[i] > perm[j]) {
                    inv_cnt++;
                }
            }
        }
        
        // 根据逆序数的奇偶性确定符号
        if (inv_cnt % 2 == 0) {
            det += product;
        } else {
            det -= product;
        }
        
    } while (next_permutation(perm.begin(), perm.end()));
    
    return det;
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    long long result = determinant(matrix);
    cout << result << endl;
    
    return 0;
}