'''
Author: zmlad
Date: 2025-11-27 18:24:06
'''
"""
程序目的：读取正整数n，输出n行"hello world"。
实现方式：
1. 使用input函数读取输入的字符串，并用int函数转换为整数n。
2. 使用for循环和range函数，循环n次。
3. 在循环体内，每次使用print函数输出"hello world"。
4. 由于print函数默认会换行，所以不需要额外处理换行。
"""
n = int(input())
for i in range(n):
    print("hello world")