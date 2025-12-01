/*
 * @Author: zmlad
 * @Date: 2025-11-27 18:49:43
 */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 像素结构体
struct Pixel {
    int r, g, b;
};

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<Pixel>> image(n, vector<Pixel>(m));
    
    // 读取输入图片
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char discard;
            cin >> discard >> image[i][j].r >> discard >> image[i][j].g >> discard >> image[i][j].b;
        }
    }
    
    // 修复过程
    bool changed;
    do {
        changed = false;
        vector<vector<Pixel>> temp = image; // 复制当前状态
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // 如果是坏点
                if (image[i][j].r == 0 && image[i][j].g == 0 && image[i][j].b == 0) {
                    int sum_r = 0, sum_g = 0, sum_b = 0;
                    int count = 0;
                    
                    // 检查四个方向的相邻点
                    if (i > 0 && !(image[i-1][j].r == 0 && image[i-1][j].g == 0 && image[i-1][j].b == 0)) {
                        sum_r += image[i-1][j].r;
                        sum_g += image[i-1][j].g;
                        sum_b += image[i-1][j].b;
                        count++;
                    }
                    if (i < n-1 && !(image[i+1][j].r == 0 && image[i+1][j].g == 0 && image[i+1][j].b == 0)) {
                        sum_r += image[i+1][j].r;
                        sum_g += image[i+1][j].g;
                        sum_b += image[i+1][j].b;
                        count++;
                    }
                    if (j > 0 && !(image[i][j-1].r == 0 && image[i][j-1].g == 0 && image[i][j-1].b == 0)) {
                        sum_r += image[i][j-1].r;
                        sum_g += image[i][j-1].g;
                        sum_b += image[i][j-1].b;
                        count++;
                    }
                    if (j < m-1 && !(image[i][j+1].r == 0 && image[i][j+1].g == 0 && image[i][j+1].b == 0)) {
                        sum_r += image[i][j+1].r;
                        sum_g += image[i][j+1].g;
                        sum_b += image[i][j+1].b;
                        count++;
                    }
                    
                    // 如果有可用相邻点，进行修复
                    if (count > 0) {
                        temp[i][j].r = ceil(static_cast<double>(sum_r) / count);
                        temp[i][j].g = ceil(static_cast<double>(sum_g) / count);
                        temp[i][j].b = ceil(static_cast<double>(sum_b) / count);
                        changed = true;
                    }
                }
            }
        }
        
        image = temp; // 更新图片
        
    } while (changed);
    
    // 输出结果
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "R " << image[i][j].r << " G " << image[i][j].g << " B " << image[i][j].b;
            if (j < m-1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}