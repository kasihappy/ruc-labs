'''
Author: zmlad
Date: 2025-12-09 16:16:38
'''
def hanoi(n, from_rod, to_rod, aux_rod, step=[0]):
    """递归解决汉诺塔问题"""
    if n == 1:
        step[0] += 1
        print(f"[step {step[0]}]  move plate {n}#  from {from_rod} to {to_rod}")
        return
    
    # 将n-1个盘子从from_rod移动到aux_rod，借助to_rod
    hanoi(n - 1, from_rod, aux_rod, to_rod, step)
    
    # 移动第n个盘子从from_rod到to_rod
    step[0] += 1
    print(f"[step {step[0]}]  move plate {n}#  from {from_rod} to {to_rod}")
    
    # 将n-1个盘子从aux_rod移动到to_rod，借助from_rod
    hanoi(n - 1, aux_rod, to_rod, from_rod, step)

def main():
    n = int(input())
    step = [0]  # 使用列表作为可变对象来记录步数
    hanoi(n, 'a', 'c', 'b', step)
    print(step[0])

if __name__ == "__main__":
    main()