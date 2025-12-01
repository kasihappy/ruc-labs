'''
Author: zmlad
Date: 2025-11-27 18:50:02
'''
import math
import sys

def main():
    # 读取输入
    data = sys.stdin.read().splitlines()
    n, m = map(int, data[0].split())
    
    # 解析图片数据
    image = []
    for i in range(1, n + 1):
        tokens = data[i].split()
        row = []
        for j in range(m):
            # 每个点占用6个token: R, r_val, G, g_val, B, b_val
            idx = j * 6
            r_val = int(tokens[idx + 1])
            g_val = int(tokens[idx + 3])
            b_val = int(tokens[idx + 5])
            row.append([r_val, g_val, b_val])
        image.append(row)
    
    # 修复过程
    changed = True
    while changed:
        changed = False
        # 深拷贝当前图片状态
        temp = [[[p[0], p[1], p[2]] for p in row] for row in image]
        
        for i in range(n):
            for j in range(m):
                # 如果是坏点
                if image[i][j][0] == 0 and image[i][j][1] == 0 and image[i][j][2] == 0:
                    sum_r, sum_g, sum_b = 0, 0, 0
                    count = 0
                    
                    # 检查四个方向的相邻点
                    if i > 0 and not (image[i-1][j][0] == 0 and image[i-1][j][1] == 0 and image[i-1][j][2] == 0):
                        sum_r += image[i-1][j][0]
                        sum_g += image[i-1][j][1]
                        sum_b += image[i-1][j][2]
                        count += 1
                    
                    if i < n-1 and not (image[i+1][j][0] == 0 and image[i+1][j][1] == 0 and image[i+1][j][2] == 0):
                        sum_r += image[i+1][j][0]
                        sum_g += image[i+1][j][1]
                        sum_b += image[i+1][j][2]
                        count += 1
                    
                    if j > 0 and not (image[i][j-1][0] == 0 and image[i][j-1][1] == 0 and image[i][j-1][2] == 0):
                        sum_r += image[i][j-1][0]
                        sum_g += image[i][j-1][1]
                        sum_b += image[i][j-1][2]
                        count += 1
                    
                    if j < m-1 and not (image[i][j+1][0] == 0 and image[i][j+1][1] == 0 and image[i][j+1][2] == 0):
                        sum_r += image[i][j+1][0]
                        sum_g += image[i][j+1][1]
                        sum_b += image[i][j+1][2]
                        count += 1
                    
                    # 如果有可用相邻点，进行修复
                    if count > 0:
                        temp[i][j][0] = int(math.ceil(sum_r / count))
                        temp[i][j][1] = int(math.ceil(sum_g / count))
                        temp[i][j][2] = int(math.ceil(sum_b / count))
                        changed = True
        
        image = temp  # 更新图片
    
    # 输出结果
    for i in range(n):
        line_parts = []
        for j in range(m):
            line_parts.append(f"R {image[i][j][0]} G {image[i][j][1]} B {image[i][j][2]}")
        print(" ".join(line_parts))

if __name__ == "__main__":
    main()