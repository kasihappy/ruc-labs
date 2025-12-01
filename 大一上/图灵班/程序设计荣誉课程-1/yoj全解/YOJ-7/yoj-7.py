'''
Author: zmlad
Date: 2025-11-27 18:35:20
'''
"""
程序目的：读取三角形的三条边长，使用海伦公式计算面积，保留两位小数输出。
实现方式：
1. 使用input函数读取一行输入，然后用split方法分割成三个字符串。
2. 使用map函数将三个字符串转换为整数。
3. 计算半周长 s = (a + b + c) / 2.0。
4. 使用海伦公式计算面积：area = sqrt(s * (s-a) * (s-b) * (s-c))。
5. 使用格式化字符串"{:.2f}"来保留两位小数。
"""
import math

a, b, c = map(int, input().split())
s = (a + b + c) / 2.0
area = math.sqrt(s * (s - a) * (s - b) * (s - c))
print("{:.2f}".format(area))