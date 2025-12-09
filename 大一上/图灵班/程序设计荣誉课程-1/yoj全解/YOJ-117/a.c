/*
 * @Author: zmlad
 * @Date: 2025-12-09 15:36:23
 */
#include <stdio.h>
#include <stdlib.h>

/*
思路：
这是一个典型的数字三角形问题，要求从底部走到顶部，每次只能向左上或右上移动，求经过路径的最大和。
可以使用动态规划自底向上求解。

具体步骤：
1. 读取输入，将桃子数存储在一个二维数组中（第i层有i个元素）。
2. 从倒数第二层开始向上逐层计算每个位置能获得的最大桃子数。
   对于位置(i, j)，其最大值为下一层左下方和右下方两个位置中较大的一个加上当前位置的桃子数。
   即：dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + peaches[i][j]。
3. 最终，顶层的值即为小猴子能摘到的最大桃子数。

注意：由于输入是从顶层到底层，而动态规划从底层向顶层计算更方便，因此可以直接在原数组上进行操作。
*/

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);  // 读取层数

    // 动态分配二维数组，用于存储每层的桃子数
    int **peaches = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 1; i <= n; i++) {
        peaches[i] = (int *)malloc((i + 1) * sizeof(int));
    }

    // 读取桃子数
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &peaches[i][j]);
        }
    }

    // 动态规划：自底向上计算
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            // 当前位置能获得的最大桃子数 = 下一层左右两个位置中较大的一个 + 当前位置的桃子数
            peaches[i][j] += max(peaches[i+1][j], peaches[i+1][j+1]);
        }
    }

    // 输出结果
    printf("%d\n", peaches[1][1]);

    // 释放动态分配的内存
    for (int i = 1; i <= n; i++) {
        free(peaches[i]);
    }
    free(peaches);

    return 0;
}