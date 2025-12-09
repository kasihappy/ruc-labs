/*
 * @Author: zmlad
 * @Date: 2025-12-09 14:05:20
 */
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // 使用vector动态分配数组，更方便
    // Use space between closing angle brackets for older compilers
    vector<vector<int> > matrix(n + 2, vector<int>(n + 2, 0));
    int count = 1;
    
    matrix[1][1] = count++;
    int i = 1, j = 1; // i行，j列
    
    while (count <= n * n) {
        // 1. 第一行向右走，只走一格
        j++;
        matrix[i][j] = count++;

        // 2. 从第一行向下走，比上一列多走一格
        while (matrix[i][j - 1] != 0) {
            i++;
            matrix[i][j] = count++;
        }

        // 3. 向左走，走到头
        for (int col = j - 1; col >= 1; col--) {
            j--;
            matrix[i][j] = count++;
        }
        
        // 4. 第一列向下走，只走一格
        i++;
        matrix[i][j] = count++;
        
        // 5. 向右走，比上一行多走一格
        while (matrix[i - 1][j] != 0) {
            j++;
            matrix[i][j] = count++;
        }
        
        // 6. 向上走，走到头
        for (int row = i - 1; row >= 1; row--) {
            i--;
            matrix[i][j] = count++;
        }
    }

    // 输出矩阵
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}