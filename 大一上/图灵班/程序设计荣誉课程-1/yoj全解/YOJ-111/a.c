/*
 * @Author: zmlad
 * @Date: 2025-12-09 15:21:11
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 比较函数，用于降序排序
int compare(const void *a, const void *b) {
    long long x = *(long long *)a;
    long long y = *(long long *)b;
    if (x < y) return 1;
    if (x > y) return -1;
    return 0;
}

int main() {
    long long n;
    while (1) {
        // 读取椰子数
        if (scanf("%lld", &n) != 1) break;
        if (n == 0) break; // 结束条件

        // 处理特殊情况：n=1时无解
        if (n == 1) {
            printf("no solution\n");
            continue;
        }

        // 计算 n-1 的所有约数
        long long d = n - 1;
        long long divisors[2000]; // 存储约数，约数个数不会太多
        int count = 0;

        // 寻找约数，只需遍历到 sqrt(d)
        long long limit = (long long)sqrt(d);
        for (long long i = 1; i <= limit; i++) {
            if (d % i == 0) {
                divisors[count++] = i; // 添加约数 i
                if (i != d / i) {
                    divisors[count++] = d / i; // 添加约数 d/i
                }
            }
        }

        // 将约数降序排序
        qsort(divisors, count, sizeof(long long), compare);

        int found = 0;
        // 从大到小检查每个约数作为 m
        for (int idx = 0; idx < count; idx++) {
            long long m = divisors[idx];
            if (m <= 1) continue; // m 必须大于 1

            long long s = n; // 当前椰子数
            int ok = 1; // 标记是否满足条件

            // 模拟 m 天的分配过程
            for (long long day = 1; day <= m; day++) {
                if (s % m != 1) { // 每天必须满足余数为 1
                    ok = 0;
                    break;
                }
                // 更新椰子数：s = (s-1)/m * (m-1)
                s = (s - 1) / m * (m - 1);
            }

            // 检查第 m+1 天是否能被 m 整除
            if (ok && s % m == 0) {
                printf("%lld\n", m);
                found = 1;
                break; // 找到最大的 m，退出循环
            }
        }

        if (!found) {
            printf("no solution\n");
        }
    }
    return 0;
}