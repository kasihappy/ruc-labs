'''
Author: zmlad
Date: 2025-12-09 14:21:16
'''
"""
思路：
1. 读取整数n，表示区间数量。
2. 使用两个列表bounds和rates分别存储分界值和提成率。注意：最后一个分界值为-1。
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
使用format或f-string格式化输出小数。
"""

def main():
    n = int(input())
    bounds = []
    rates = []
    for _ in range(n):
        line = input().split()
        bounds.append(int(line[0]))
        rates.append(float(line[1]))
    
    profit = int(input())
    
    if profit < 0:
        print("NO")
        return
    
    bonus = 0.0
    prev = 0
    for i in range(n):
        if bounds[i] == -1:
            if profit > prev:
                bonus += (profit - prev) * rates[i]
            break
        else:
            if profit > prev:
                if profit <= bounds[i]:
                    bonus += (profit - prev) * rates[i]
                    break
                else:
                    bonus += (bounds[i] - prev) * rates[i]
                    prev = bounds[i]
            else:
                break
    
    print(f"{bonus:.2f}")

if __name__ == "__main__":
    main()