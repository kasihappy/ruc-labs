#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 定义像素结构体存储RGB值
typedef struct {
    int r, g, b;
} Pixel;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    // 分配内存存储图片
    Pixel **image = (Pixel **)malloc(n * sizeof(Pixel *));
    for (int i = 0; i < n; i++) {
        image[i] = (Pixel *)malloc(m * sizeof(Pixel));
    }
    
    // 读取输入图片
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char discard; // 用于读取R、G、B字母
            scanf(" %c %d %c %d %c %d", &discard, &image[i][j].r, 
                  &discard, &image[i][j].g, &discard, &image[i][j].b);
        }
    }
    
    // 修复过程：循环直到没有坏点被修复
    int changed;
    do {
        changed = 0;
        // 创建临时图片存储本轮修复结果
        Pixel **temp = (Pixel **)malloc(n * sizeof(Pixel *));
        for (int i = 0; i < n; i++) {
            temp[i] = (Pixel *)malloc(m * sizeof(Pixel));
            // 复制当前状态
            for (int j = 0; j < m; j++) {
                temp[i][j] = image[i][j];
            }
        }
        
        // 遍历每个像素点
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // 如果是坏点（RGB全为0）
                if (image[i][j].r == 0 && image[i][j].g == 0 && image[i][j].b == 0) {
                    int sum_r = 0, sum_g = 0, sum_b = 0;
                    int count = 0;
                    
                    // 检查上邻点（如果存在且不是坏点）
                    if (i > 0 && !(image[i-1][j].r == 0 && image[i-1][j].g == 0 && image[i-1][j].b == 0)) {
                        sum_r += image[i-1][j].r;
                        sum_g += image[i-1][j].g;
                        sum_b += image[i-1][j].b;
                        count++;
                    }
                    // 检查下邻点
                    if (i < n-1 && !(image[i+1][j].r == 0 && image[i+1][j].g == 0 && image[i+1][j].b == 0)) {
                        sum_r += image[i+1][j].r;
                        sum_g += image[i+1][j].g;
                        sum_b += image[i+1][j].b;
                        count++;
                    }
                    // 检查左邻点
                    if (j > 0 && !(image[i][j-1].r == 0 && image[i][j-1].g == 0 && image[i][j-1].b == 0)) {
                        sum_r += image[i][j-1].r;
                        sum_g += image[i][j-1].g;
                        sum_b += image[i][j-1].b;
                        count++;
                    }
                    // 检查右邻点
                    if (j < m-1 && !(image[i][j+1].r == 0 && image[i][j+1].g == 0 && image[i][j+1].b == 0)) {
                        sum_r += image[i][j+1].r;
                        sum_g += image[i][j+1].g;
                        sum_b += image[i][j+1].b;
                        count++;
                    }
                    
                    // 如果有可用的相邻点，进行修复
                    if (count > 0) {
                        temp[i][j].r = (int)ceil((double)sum_r / count);
                        temp[i][j].g = (int)ceil((double)sum_g / count);
                        temp[i][j].b = (int)ceil((double)sum_b / count);
                        changed = 1; // 标记有变化
                    }
                }
            }
        }
        
        // 更新图片为修复后的状态
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                image[i][j] = temp[i][j];
            }
            free(temp[i]);
        }
        free(temp);
        
    } while (changed); // 当有变化时继续循环
    
    // 输出修复后的图片
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("R %d G %d B %d", image[i][j].r, image[i][j].g, image[i][j].b);
            if (j < m-1) printf(" ");
        }
        printf("\n");
    }
    
    // 释放内存
    for (int i = 0; i < n; i++) {
        free(image[i]);
    }
    free(image);
    
    return 0;
}