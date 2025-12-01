'''
Author: zmlad
Date: 2025-11-27 18:30:36
'''
"""
程序目的：读取一个英文字母，切换其大小写后输出。
实现方式：
1. 使用input函数读取一个字符。
2. 使用字符串的isupper和islower方法判断字母的大小写：
   - 如果是大写字母，使用lower方法转换为小写
   - 如果是小写字母，使用upper方法转换为大写
3. 输出转换后的字符。
"""
c = input().strip()
if c.isupper():
    c = c.lower()
elif c.islower():
    c = c.upper()
print(c)