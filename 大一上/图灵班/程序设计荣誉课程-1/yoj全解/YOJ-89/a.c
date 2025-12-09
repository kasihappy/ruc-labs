/*
 * @Author: zmlad
 * @Date: 2025-12-09 14:18:10
 */
#include <stdio.h>

/*
思路：
1. 读取整数n，表示区间数量。
2. 使用两个数组bounds和rates分别存储分界值和提成率。注意：最后一个分界值为-1。
3. 读取当月利润profit，如果profit < 0，直接输出"NO"。
4. 否则，计算奖金：
   - 初始化奖金bonus为0，前一个边界prev为0。
   - 遍历每个区间（共n个）：
        a. 如果当前分界值为-1（最后一个区间）：
            若profit > prev，则bonus += (profit - prev) * 当前提成率，然后退出循环。
        b. 否则（普通区间）：
            若profit > prev：
                若profit <= 当前分界值，则bonus += (profit - prev) * 当前提成率，退出循环。
                否则，bonus += (当前分界值 - prev) * 当前提成率，更新prev为当前分界值。
   - 输出bonus，保留两位小数。
注意：区间是连续且递增的，计算时只处理profit超过prev的部分。
*/

int main() {
    int n;
    scanf("%d", &n);
    int bounds[100];        // 分界值数组，最多100个
    double rates[100];      // 提成率数组

    for (int i = 0; i < n; i++) {
        scanf("%d %lf", &bounds[i], &rates[i]);
    }

    int profit;
    scanf("%d", &profit);

    if (profit < 0) {
        printf("NO\n");
        return 0;
    }

    double bonus = 0.0;
    int prev = 0;

    for (int i = 0; i < n; i++) {
        if (bounds[i] == -1) {
            // 最后一个区间，处理超出之前边界的部分
            if (profit > prev) {
                bonus += (profit - prev) * rates[i];
            }
            break;
        } else {
            if (profit > prev) {
                if (profit <= bounds[i]) {
                    // profit落在当前区间内
                    bonus += (profit - prev) * rates[i];
                    break;
                } else {
                    // profit超过当前区间，累加整个区间的奖金
                    bonus += (bounds[i] - prev) * rates[i];
                    prev = bounds[i];  // 更新边界，进入下一个区间
                }
            } else {
                // profit <= prev，说明已处理完或profit为0，退出
                break;
            }
        }
    }

    printf("%.2f\n", bonus);
    return 0;
}