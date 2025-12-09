'''
Author: zmlad
Date: 2025-12-09 15:27:11
'''
import math

def solve_coconut_problem():
    while True:
        try:
            # 读取椰子数
            line = input().strip()
            if not line:
                continue
                
            n = int(line)
            if n == 0:
                break  # 结束条件
            
            # 处理特殊情况：n=1时无解
            if n == 1:
                print("no solution")
                continue
            
            # 计算 n-1 的所有约数
            d = n - 1
            divisors = set()  # 使用集合避免重复
            
            # 寻找约数，只需遍历到 sqrt(d)
            limit = int(math.sqrt(d))
            for i in range(1, limit + 1):
                if d % i == 0:
                    divisors.add(i)  # 添加约数 i
                    divisors.add(d // i)  # 添加约数 d//i
            
            # 将约数转换为列表并降序排序
            divisors = sorted(list(divisors), reverse=True)
            
            found = False
            # 从大到小检查每个约数作为 m
            for m in divisors:
                if m <= 1:  # m 必须大于 1
                    continue
                
                s = n  # 当前椰子数
                ok = True  # 标记是否满足条件
                
                # 模拟 m 天的分配过程
                for day in range(1, m + 1):
                    if s % m != 1:  # 每天必须满足余数为 1
                        ok = False
                        break
                    # 更新椰子数：s = (s-1)/m * (m-1)
                    s = (s - 1) // m * (m - 1)
                
                # 检查第 m+1 天是否能被 m 整除
                if ok and s % m == 0:
                    print(m)
                    found = True
                    break  # 找到最大的 m，退出循环
            
            if not found:
                print("no solution")
                
        except EOFError:
            break

if __name__ == "__main__":
    solve_coconut_problem()