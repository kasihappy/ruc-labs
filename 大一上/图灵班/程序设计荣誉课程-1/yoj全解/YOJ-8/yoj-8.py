'''
Author: zmlad
Date: 2025-11-27 18:37:20
'''
"""
程序目的：读取百分制成绩，根据对照表输出对应的学分绩点。
实现方式：
1. 使用input函数读取输入，并转换为整数score。
2. 使用if-elif-else语句根据成绩范围设置grade_point的值。
3. 输出时，如果grade_point为0，输出整数0；否则使用格式化字符串保留一位小数输出。
"""
score = int(input().strip())

if score >= 90 and score <= 100:
    grade_point = 4.0
elif score >= 86 and score <= 89:
    grade_point = 3.7
elif score >= 83 and score <= 85:
    grade_point = 3.3
elif score >= 80 and score <= 82:
    grade_point = 3.0
elif score >= 76 and score <= 79:
    grade_point = 2.7
elif score >= 73 and score <= 75:
    grade_point = 2.3
elif score >= 70 and score <= 72:
    grade_point = 2.0
elif score >= 66 and score <= 69:
    grade_point = 1.7
elif score >= 63 and score <= 65:
    grade_point = 1.3
elif score >= 60 and score <= 62:
    grade_point = 1.0
else:
    grade_point = 0.0

if grade_point == 0.0:
    print(0)
else:
    print("{:.1f}".format(grade_point))