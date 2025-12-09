/*
 * @Author: zmlad
 * @Date: 2025-12-09 15:26:47
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// 比较函数，用于降序排序
bool compare_desc(long long a, long long b) {
    return a > b;
}

int main() {
    long long n;
    
    while (true) {
        // 读取椰子数
        if (!(cin >> n)) break;
        if (n == 0) break; // 结束条件
        
        // 处理特殊情况：n=1时无解
        if (n == 1) {
            cout << "no solution" << endl;
            continue;
        }
        
        // 计算 n-1 的所有约数
        long long d = n - 1;
        vector<long long> divisors;
        
        // 寻找约数，只需遍历到 sqrt(d)
        long long limit = (long long)sqrt(d);
        for (long long i = 1; i <= limit; i++) {
            if (d % i == 0) {
                divisors.push_back(i); // 添加约数 i
                if (i != d / i) {
                    divisors.push_back(d / i); // 添加约数 d/i
                }
            }
        }
        
        // 将约数降序排序
        sort(divisors.begin(), divisors.end(), compare_desc);
        
        bool found = false;
        // 从大到小检查每个约数作为 m
        for (long long m : divisors) {
            if (m <= 1) continue; // m 必须大于 1
            
            long long s = n; // 当前椰子数
            bool ok = true; // 标记是否满足条件
            
            // 模拟 m 天的分配过程
            for (long long day = 1; day <= m; day++) {
                if (s % m != 1) { // 每天必须满足余数为 1
                    ok = false;
                    break;
                }
                // 更新椰子数：s = (s-1)/m * (m-1)
                s = (s - 1) / m * (m - 1);
            }
            
            // 检查第 m+1 天是否能被 m 整除
            if (ok && s % m == 0) {
                cout << m << endl;
                found = true;
                break; // 找到最大的 m，退出循环
            }
        }
        
        if (!found) {
            cout << "no solution" << endl;
        }
    }
    
    return 0;
}