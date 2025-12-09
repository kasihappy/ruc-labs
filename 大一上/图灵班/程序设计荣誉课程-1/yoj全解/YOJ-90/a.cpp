/*
 * @Author: zmlad
 * @Date: 2025-12-09 14:30:20
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    long long sno;
    int solved;
};

// 比较函数：按解决题目数降序，学号升序
bool cmp(const Student &a, const Student &b) {
    if (a.solved != b.solved) return a.solved > b.solved;
    return a.sno < b.sno;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> required(n);
    for (int i = 0; i < n; i++) {
        cin >> required[i];
    }
    
    int m, k;
    cin >> m >> k;
    
    vector<Student> students(m);
    
    for (int idx = 0; idx < m; idx++) {
        long long sno;
        int p;
        cin >> sno >> p;
        
        int solved = 0;
        vector<bool> counted(n, false); // 记录是否已经统计过该必做题
        
        for (int j = 0; j < p; j++) {
            int pid;
            cin >> pid;
            // 检查是否是必做题且未统计过
            for (int r = 0; r < n; r++) {
                if (pid == required[r] && !counted[r]) {
                    counted[r] = true;
                    solved++;
                    break;
                }
            }
        }
        
        students[idx].sno = sno;
        students[idx].solved = solved;
    }
    
    // 排序
    sort(students.begin(), students.end(), cmp);
    
    // 密集排名并输出前k名
    int rank = 1;
    int prev_solved = students[0].solved;
    
    for (int i = 0; i < m; i++) {
        if (i > 0 && students[i].solved != prev_solved) {
            rank++;
            prev_solved = students[i].solved;
        }
        
        if (rank > k) break;
        
        if (i > 0) cout << " ";
        cout << students[i].sno;
    }
    
    cout << endl;
    return 0;
}