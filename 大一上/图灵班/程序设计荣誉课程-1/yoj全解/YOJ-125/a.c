/*
 * @Author: zmlad
 * @Date: 2025-12-09 16:29:46
 */
/*
 * 题目：计算n阶行列式的值
 * 方法：根据行列式定义，计算所有排列的带符号乘积和
 * 思路：
 * 1. 定义式计算：det(A) = Σ(-1)^t * Π(a[i][p_i-1])，其中p是1~n的排列，t是逆序数
 * 2. 生成1~n的所有排列（共n!个）
 * 3. 对每个排列：
 *    a) 计算逆序数t
 *    b) 计算乘积Π(a[i][p_i-1])（注意下标转换）
 *    c) 乘以符号(-1)^t，累加到结果中
 * 4. 由于n≤9，n!最大为362880，可以接受
 * 关键点：
 * - 排列生成：使用递归回溯法
 * - 逆序数计算：对于排列p，统计有多少对(i,j)满足i<j且p[i]>p[j]
 * - 下标处理：题目中矩阵下标从0开始，排列中的p_i是1~n，需要减1得到列下标
 * - 结果范围：元素值-10~10，n≤9，结果在32位整数范围内
 */

#include <stdio.h>
#include <stdlib.h>

int n;
int matrix[9][9];      // 存储行列式矩阵
int temp[9];           // 临时存储当前排列
int used[9] = {0};     // 标记数字是否已使用
long long det = 0;     // 行列式结果

// 计算排列的逆序数
int inversion_count(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                count++;
            }
        }
    }
    return count;
}

// 递归生成所有排列并计算贡献值
void generate_permutation(int depth) {
    if (depth == n) {
        // 计算当前排列的乘积
        long long product = 1;
        for (int i = 0; i < n; i++) {
            product *= matrix[i][temp[i] - 1];  // temp[i]是1~n，转为0~n-1下标
        }
        
        // 计算逆序数并确定符号
        int inv_cnt = inversion_count(temp, n);
        long long sign = (inv_cnt % 2 == 0) ? 1 : -1;
        
        // 累加到行列式值
        det += sign * product;
        return;
    }
    
    // 生成排列：尝试将每个未使用的数字放入当前位置
    for (int i = 1; i <= n; i++) {
        if (!used[i - 1]) {
            used[i - 1] = 1;
            temp[depth] = i;
            generate_permutation(depth + 1);
            used[i - 1] = 0;  // 回溯
        }
    }
}

int main() {
    // 读取输入
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // 计算行列式
    generate_permutation(0);
    
    // 输出结果
    printf("%lld\n", det);
    
    return 0;
}