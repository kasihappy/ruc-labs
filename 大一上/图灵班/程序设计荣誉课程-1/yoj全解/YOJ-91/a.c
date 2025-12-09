#include <stdio.h>
#include <math.h>

/*
思路：
1. 定义计算直方图的函数：将[0,255]分为16个区间，每个区间宽度16。
2. 读入查询乐曲Q：先读长度n0，再读n0个频率值，计算其直方图hist_q。
3. 读入n和k：表示音乐库有n首乐曲，需要输出最相似的k首。
4. 遍历n首乐曲：
   a. 读入每首乐曲的长度和频率值。
   b. 计算该乐曲的直方图hist_i。
   c. 计算hist_i与hist_q的欧几里得距离：sqrt(Σ(hist_i[j]-hist_q[j])²)。
   d. 存储该乐曲的编号和距离。
5. 对所有乐曲按距离排序：距离小的靠前，若距离相同则编号小的靠前。
6. 输出前k个乐曲的编号，用空格分隔。
注意：由于只需要输出编号，我们可以不实际计算sqrt，直接比较平方距离即可，但为了精确，这里还是计算sqrt。
*/

#define BINS 16
#define BIN_WIDTH 16

void compute_histogram(int* freq, int len, int hist[BINS]) {
    // 初始化直方图为0
    for (int i = 0; i < BINS; i++) hist[i] = 0;
    
    // 计算每个频率属于哪个区间
    for (int i = 0; i < len; i++) {
        int bin_index = freq[i] / BIN_WIDTH;  // 整除16得到区间索引
        hist[bin_index]++;
    }
}

double euclidean_distance(int hist1[BINS], int hist2[BINS]) {
    double sum = 0.0;
    for (int i = 0; i < BINS; i++) {
        int diff = hist1[i] - hist2[i];
        sum += diff * diff;
    }
    return sqrt(sum);
}

int main() {
    // 读取查询乐曲Q
    int n0;
    scanf("%d", &n0);
    int q_freq[100];
    for (int i = 0; i < n0; i++) {
        scanf("%d", &q_freq[i]);
    }
    
    // 计算Q的直方图
    int hist_q[BINS];
    compute_histogram(q_freq, n0, hist_q);
    
    // 读取n和k
    int n, k;
    scanf("%d %d", &n, &k);
    
    // 存储每首乐曲的编号和距离
    typedef struct {
        int id;
        double distance;
    } Song;
    Song songs[100];
    
    // 处理每首乐曲
    for (int i = 0; i < n; i++) {
        int len;
        scanf("%d", &len);
        int freq[100];
        for (int j = 0; j < len; j++) {
            scanf("%d", &freq[j]);
        }
        
        // 计算当前乐曲的直方图
        int hist_i[BINS];
        compute_histogram(freq, len, hist_i);
        
        // 计算与Q的距离
        double dist = euclidean_distance(hist_i, hist_q);
        
        // 存储
        songs[i].id = i;
        songs[i].distance = dist;
    }
    
    // 排序：按距离升序，距离相同按编号升序
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // 如果距离较大，或者距离相同但编号较大，则交换
            if (songs[j].distance > songs[j+1].distance ||
                (fabs(songs[j].distance - songs[j+1].distance) < 1e-9 && songs[j].id > songs[j+1].id)) {
                Song temp = songs[j];
                songs[j] = songs[j+1];
                songs[j+1] = temp;
            }
        }
    }
    
    // 输出前k个编号
    for (int i = 0; i < k; i++) {
        printf("%d", songs[i].id);
        if (i < k - 1) printf(" ");
    }
    printf("\n");
    
    return 0;
}