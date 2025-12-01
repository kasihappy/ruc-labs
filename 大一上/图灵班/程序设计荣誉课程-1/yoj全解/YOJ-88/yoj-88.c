/*
 * @Author: zmlad
 * @Date: 2025-11-27 18:56:42
 */
// 垃圾ai这个题就做不出来了，真是杂鱼
// 可以找规律，也可以模拟，这里直接模拟做了
// 六种状态
// 1. 第一行向右走，只走一格
// 2. 从第一行向下走，比上列多走一格
// 3. 向左走，走到头
// 4. 第一列向下走，只走一格
// 5. 向右走，比上一行多走一格
// 6. 向上走，走到头
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int matrix[102][102] = {0};  // 初始化矩阵
    int count = 1;               // 从1开始计数
    
    matrix[1][1] = count++;  // 填充第一个位置
    int i = 1, j = 1; // i行，j列

    while (count <= n * n) {
        // 1. 第一行向右走，只走一格
        j++;
        matrix[i][j] = count++;

        // 2. 从第一行向下走，比上一列多走一格
        while(matrix[i][j-1] != 0) {
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
        while (matrix[i-1][j] != 0) {
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
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}