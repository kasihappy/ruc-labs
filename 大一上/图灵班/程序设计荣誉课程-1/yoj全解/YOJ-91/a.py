'''
Author: zmlad
Date: 2025-12-09 14:38:45
'''
import math

BINS = 16
BIN_WIDTH = 16

def compute_histogram(freq):
    """计算频率直方图"""
    hist = [0] * BINS
    for f in freq:
        bin_index = f // BIN_WIDTH
        hist[bin_index] += 1
    return hist

def euclidean_distance(hist1, hist2):
    """计算欧几里得距离"""
    sum_sq = 0
    for i in range(BINS):
        diff = hist1[i] - hist2[i]
        sum_sq += diff * diff
    return math.sqrt(sum_sq)

def main():
    # 读取查询乐曲Q
    n0 = int(input())
    q_freq = list(map(int, input().split()))
    
    # 计算Q的直方图
    hist_q = compute_histogram(q_freq)
    
    # 读取n和k
    n, k = map(int, input().split())
    
    songs = []
    
    # 处理每首乐曲
    for song_id in range(n):
        data = list(map(int, input().split()))
        len_ = data[0]
        freq = data[1:1+len_]
        
        # 计算当前乐曲的直方图
        hist_i = compute_histogram(freq)
        
        # 计算与Q的距离
        dist = euclidean_distance(hist_i, hist_q)
        
        # 存储
        songs.append((song_id, dist))
    
    # 排序：按距离升序，距离相同按id升序
    songs.sort(key=lambda x: (x[1], x[0]))
    
    # 输出前k个编号
    result = [str(songs[i][0]) for i in range(k)]
    print(" ".join(result))

if __name__ == "__main__":
    main()