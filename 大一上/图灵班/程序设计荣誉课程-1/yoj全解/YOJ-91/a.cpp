/*
 * @Author: zmlad
 * @Date: 2025-12-09 14:38:38
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int BINS = 16;
const int BIN_WIDTH = 16;

// 计算频率直方图
void compute_histogram(const vector<int>& freq, int hist[BINS]) {
    fill(hist, hist + BINS, 0);
    for (int f : freq) {
        int bin_index = f / BIN_WIDTH;
        hist[bin_index]++;
    }
}

// 计算欧几里得距离
double euclidean_distance(const int hist1[BINS], const int hist2[BINS]) {
    double sum = 0.0;
    for (int i = 0; i < BINS; i++) {
        int diff = hist1[i] - hist2[i];
        sum += diff * diff;
    }
    return sqrt(sum);
}

struct Song {
    int id;
    double distance;
};

// 比较函数：按距离升序，距离相同按id升序
bool compare_songs(const Song& a, const Song& b) {
    if (abs(a.distance - b.distance) > 1e-9) {
        return a.distance < b.distance;
    }
    return a.id < b.id;
}

int main() {
    // 读取查询乐曲Q
    int n0;
    cin >> n0;
    vector<int> q_freq(n0);
    for (int i = 0; i < n0; i++) {
        cin >> q_freq[i];
    }
    
    // 计算Q的直方图
    int hist_q[BINS];
    compute_histogram(q_freq, hist_q);
    
    // 读取n和k
    int n, k;
    cin >> n >> k;
    
    vector<Song> songs(n);
    
    // 处理每首乐曲
    for (int i = 0; i < n; i++) {
        int len;
        cin >> len;
        vector<int> freq(len);
        for (int j = 0; j < len; j++) {
            cin >> freq[j];
        }
        
        // 计算当前乐曲的直方图
        int hist_i[BINS];
        compute_histogram(freq, hist_i);
        
        // 计算与Q的距离
        double dist = euclidean_distance(hist_i, hist_q);
        
        // 存储
        songs[i].id = i;
        songs[i].distance = dist;
    }
    
    // 排序
    sort(songs.begin(), songs.end(), compare_songs);
    
    // 输出前k个编号
    for (int i = 0; i < k; i++) {
        cout << songs[i].id;
        if (i < k - 1) cout << " ";
    }
    cout << endl;
    
    return 0;
}