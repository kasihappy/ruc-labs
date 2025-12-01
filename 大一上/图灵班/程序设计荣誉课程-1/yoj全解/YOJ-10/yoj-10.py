'''
Author: zmlad
Date: 2025-11-27 18:42:22
'''
"""
程序目的：读取华氏温度，转换为摄氏温度，保留两位小数输出。
实现方式：
1. 使用input函数读取输入的字符串，并用int函数转换为整数fahrenheit。
2. 使用转换公式 celsius = (fahrenheit - 32) * 5 / 9 进行计算。
3. 使用格式化字符串"{:.2f}"来保留两位小数。
"""
fahrenheit = int(input().strip())
celsius = (fahrenheit - 32) * 5 / 9
print("{:.2f}".format(celsius))