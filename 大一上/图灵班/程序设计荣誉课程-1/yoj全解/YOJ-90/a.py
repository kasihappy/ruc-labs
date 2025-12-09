'''
Author: zmlad
Date: 2025-12-09 14:30:31
'''
def main():
    n = int(input())
    required = list(map(int, input().split()))
    
    m, k = map(int, input().split())
    
    students = []
    
    for _ in range(m):
        data = input().split()
        sno = int(data[0])
        p = int(data[1])
        solved_problems = list(map(int, data[2:2+p]))
        
        solved = 0
        counted = [False] * n  # 记录是否已经统计过该必做题
        
        for pid in solved_problems:
            for r in range(n):
                if pid == required[r] and not counted[r]:
                    counted[r] = True
                    solved += 1
                    break
        
        students.append((sno, solved))
    
    # 排序：解决题目数降序，学号升序
    students.sort(key=lambda x: (-x[1], x[0]))
    
    # 密集排名并输出前k名
    rank = 1
    prev_solved = students[0][1]
    result = []
    
    for i in range(len(students)):
        if i > 0 and students[i][1] != prev_solved:
            rank += 1
            prev_solved = students[i][1]
        
        if rank > k:
            break
        
        result.append(str(students[i][0]))
    
    print(" ".join(result))

if __name__ == "__main__":
    main()