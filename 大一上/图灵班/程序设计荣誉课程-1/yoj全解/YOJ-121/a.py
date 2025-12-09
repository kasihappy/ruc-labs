'''
Author: zmlad
Date: 2025-12-09 16:08:36
'''
def main():
    # 读取两个整数，Python会自动处理大整数
    a, b = map(int, input().split())
    
    # 计算乘积
    product = a * b
    
    # 输出结果
    print(product)

if __name__ == "__main__":
    main()