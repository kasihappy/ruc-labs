/*
 * @Author: zmlad
 * @Date: 2025-12-09 14:18:22
 */
#include <iostream>
#include <iomanip>
using namespace std;

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
使用cout输出，用fixed和setprecision(2)控制小数位数。
*/

int main() {
    int n;
    cin >> n;
    int bounds[100];
    double rates[100];

    for (int i = 0; i < n; i++) {
        cin >> bounds[i] >> rates[i];
    }

    int profit;
    cin >> profit;

    if (profit < 0) {
        cout << "NO" << endl;
        return 0;
    }

    double bonus = 0.0;
    int prev = 0;

    for (int i = 0; i < n; i++) {
        if (bounds[i] == -1) {
            if (profit > prev) {
                bonus += (profit - prev) * rates[i];
            }
            break;
        } else {
            if (profit > prev) {
                if (profit <= bounds[i]) {
                    bonus += (profit - prev) * rates[i];
                    break;
                } else {
                    bonus += (bounds[i] - prev) * rates[i];
                    prev = bounds[i];
                }
            } else {
                break;
            }
        }
    }

    cout << fixed << setprecision(2) << bonus << endl;
    return 0;
}