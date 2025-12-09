/*
 * @Author: zmlad
 * @Date: 2025-12-09 16:03:06
 */
#include <iostream>
#include <vector>
using namespace std;

#define MAXN 100

struct Step {
    int i, j;              // 1-based swap indices
    vector<int> arr;       // array snapshot after the swap
    
    Step(int idx1, int idx2, int a[], int n) {
        i = idx1;
        j = idx2;
        arr.resize(n);
        for (int k = 0; k < n; k++) arr[k] = a[k];
    }
};

vector<Step> steps;

void record_step(int idx1, int idx2, int a[], int n) {
    steps.emplace_back(idx1 + 1, idx2 + 1, a, n); // 转换为1-based索引
}

void recursive_selection(int a[], int n, int start) {
    if (start >= n - 1) return;
    
    // 在[start, n)范围内找到最小元素的索引
    int min_pos = start;
    for (int i = start + 1; i < n; i++) {
        if (a[i] < a[min_pos]) min_pos = i;
    }
    
    // 如果需要交换，则交换并记录步骤
    if (min_pos != start) {
        swap(a[start], a[min_pos]);
        record_step(start, min_pos, a, n);
    }
    
    recursive_selection(a, n, start + 1);
}

int main() {
    int n;
    cin >> n;
    if (n <= 0 || n > MAXN) return 0;
    
    int a[MAXN];
    for (int i = 0; i < n; i++) cin >> a[i];
    
    // 清空步骤记录
    steps.clear();
    
    recursive_selection(a, n, 0);
    
    // 逆序输出步骤（从最后一步到第一步）
    for (int s = steps.size() - 1; s >= 0; s--) {
        cout << steps[s].i << "<->" << steps[s].j << ":";
        for (int k = 0; k < n; k++) {
            cout << (k == 0 ? "" : " ") << steps[s].arr[k];
        }
        cout << endl;
    }
    
    cout << "Total steps:" << steps.size() << endl;
    
    // 输出最终排序结果
    cout << "Right order:";
    for (int i = 0; i < n; i++) {
        cout << (i == 0 ? "" : " ") << a[i];
    }
    cout << endl;
    
    return 0;
}