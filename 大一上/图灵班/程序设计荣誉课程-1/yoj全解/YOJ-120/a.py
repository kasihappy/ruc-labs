'''
Author: zmlad
Date: 2025-12-09 16:04:40
'''
def recursive_selection(arr, start, steps):
    """递归选择排序"""
    n = len(arr)
    if start >= n - 1:
        return
    
    # 在[start, n)范围内找到最小元素的索引
    min_pos = start
    for i in range(start + 1, n):
        if arr[i] < arr[min_pos]:
            min_pos = i
    
    # 如果需要交换，则交换并记录步骤
    if min_pos != start:
        arr[start], arr[min_pos] = arr[min_pos], arr[start]
        # 记录步骤（1-based索引）
        steps.append((start + 1, min_pos + 1, arr.copy()))
    
    # 递归处理剩余部分
    recursive_selection(arr, start + 1, steps)

def main():
    n = int(input())
    if n <= 0:
        return
    
    arr = list(map(int, input().split()))
    steps = []  # 存储所有步骤
    
    # 进行递归选择排序
    recursive_selection(arr, 0, steps)
    
    # 逆序输出步骤（从最后一步到第一步）
    for i in range(len(steps) - 1, -1, -1):
        idx1, idx2, snapshot = steps[i]
        print(f"{idx1}<->{idx2}:", end="")
        print(" ".join(map(str, snapshot)))
    
    print(f"Total steps:{len(steps)}")
    
    # 输出最终排序结果
    print("Right order:", end="")
    print(" ".join(map(str, arr)))

if __name__ == "__main__":
    main()